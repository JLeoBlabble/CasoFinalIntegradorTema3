#include "finalIntegrador.h"
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <new>

using namespace std;

/* Defines una estructura ColorConsole
 * con dos constantes estáticas que representan códigos de color ANSI
 * para la consola.
 */
struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

/* Defines una estructura ConsoleBox
 * con dos métodos:
 * - new_text(): no hace nada.
 * - set_text(const string &text): imprime el texto en la consola.
 */
struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

/* Declara un puntero a un objeto de tipo ConsoleBox
 * y lo inicializa con nullptr.
 */
ConsoleBox *consoleBox = nullptr;

/* Define una función que carga un script desde un archivo
 * y lo imprime en la consola.
 * Si show_script es true, imprime el script en la consola.
 */
void load_script(const char* filename, bool show_script)
{
    /* Definimos una string y un puntero a un archivo "f".
     * Manejo de excepciones con try-catch.
     * Si consoleBox es nullptr, asignas memoria para un nuevo objeto ConsoleBox.
     */
    string script;
    FILE* f = nullptr;
    try
    {
        if (!consoleBox)
        {
            consoleBox = new ConsoleBox;
        }

        /* Intentas abrir el archivo en modo binario,
         * si falla lanzas una excepción runtime_error.
         */
        f = fopen(filename, "rb");
        if (!f)
        {
            throw runtime_error("Error de apertura de archivo");
        }

        /* Lees el archivo en bloques de 4000 bytes y los añades a la string "script".
         * Si ocurre un error de lectura, lanzas una excepción runtime_error.
         * Cierras el archivo "f" y lo igualas a nullptr.
         */
        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0;
            script.append(buf);
        }
        if (ferror(f))
        {
            throw runtime_error("Error durante la lectura del archivo");
        }
        fclose(f);
        f = nullptr;

        /* Si show_script es true, imprimes el script en la consola con sus colores.
         * Llamas a new_text() y set_text(script).
         */
        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    /* Capturas excepciones de tipo bad_alloc y exception.
     * Si el archivo está abierto, lo cierras.
     */
    catch (const bad_alloc &e)
    {
        cerr << "Error de memoria: " << e.what() << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        if (f)
            fclose(f);
    }
}

/* Defines la función load_script que solicita al usuario un nombre de archivo.
 * Usas "fgets" para leer el nombre del archivo y eliminas el carácter de nueva línea si está presente.
 * Llamas a la función "load_script" con el nombre del archivo y "show_script" establecido a true.
 * Si ocurre un error al leer el nombre del archivo, imprimes un mensaje de error.
 */
void load_script()
{
    char filename[500];
    printf("Archivo: ");
    if (fgets(filename, sizeof(filename), stdin) != nullptr)
    {
        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n')
        {
            filename[len - 1] = '\0';
        }
        load_script(filename, true);
    }
    else
    {
        cerr << "Error al leer el nombre del archivo" << endl;
    }
}