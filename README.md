# CasoFinalIntegradorTema3

https://github.com/JLeoBlabble/CasoFinalIntegradorTema3.git 

## Objetivo: 
El módulo Labmain.cpp define la función load_script(), que se utiliza para cargar un script en la memoria y aplicarle la coloración sintáctica. Esta función se basa en la librería estándar de C.

Implementa las funciones load_script() y load_script(filename, true) en CLion, de tal manera que puedas abrir y leer archivos de texto. El primer método toma el nombre de un archivo como entrada del usuario, mientras que el segundo muestra el contenido del archivo. Ambos métodos deben cargar el script en la consola.

void load_script(const char* filename, bool show_script = false);
void load_script();

## Recordatorios y Notas: 
Asegúrate de que tu código pueda manejar diferentes tipos de errores de entrada. Esto incluye, pero no se limita a:

El usuario proporciona un nombre de archivo que no existe.
El archivo proporcionado no se puede abrir por alguna razón.
Se produce un error de lectura durante la lectura del archivo.
Para manejar estos y otros errores potenciales, es posible que desees agregar comprobaciones de errores adicionales y manejar los fallos de manera más sofisticada.

Este ejercicio no requiere el uso de funciones seguras específicas de Microsoft (las funciones con sufijo _s). En cambio, deberías usar las funciones estándar de C/C++ disponibles en todas las plataformas y compiladores, como fopen, printf y scanf.

Este código debería compilar y funcionar en CLion sin necesidad de agregar la directiva _CRT_SECURE_NO_WARNINGS, ya que no se están utilizando las versiones seguras específicas de Microsoft de las funciones de la biblioteca estándar de C.

Por último, ten en cuenta que este código no realiza una comprobación completa de errores y no es robusto contra varios tipos de errores de entrada. Dependiendo de tu caso de uso específico, es posible que desees agregar comprobaciones de errores adicionales y manejar los fallos de manera más sofisticada.

## Rúbrica (Total: 100 puntos): 
### Carga de scripts (50 puntos)
Se proporciona una implementación correcta de load_script(const char* filename, bool show_script = false) que carga correctamente el archivo dado y muestra su contenido si show_script es verdadero. (25 puntos)
Se proporciona una implementación correcta de load_script() que solicita al usuario un nombre de archivo, llama a la función load_script(const char* filename, bool show_script = false) y maneja cualquier error de manera apropiada. (25 puntos)

### Manejo de errores (50 puntos)
El código tiene un manejo de errores sólido y completo para el caso de que el nombre del archivo proporcionado no exista. (15 puntos)
El código tiene un manejo de errores sólido y completo para el caso de que el archivo proporcionado no se pueda abrir por alguna razón. (15 puntos)
El código tiene un manejo de errores sólido y completo para el caso de que se produzca un error de lectura durante la lectura del archivo. (20 puntos)


# Correción compañero: Marc Baleiron Andrusaitis 

## README.md: 
Proporciona el link a su repositorio.
Contiene toda la información y una descripción apta del ejercicio.
No contiene explicaciones de su código, porque lo ha hecho en el código en sí, en formato de comentarios.
Ha empleado el uso correcto de formatting.

### Valoración final README.md: 
Su README.md contiene toda la información necesario sobre el proyecto y su trabajo realizado.

## Código: 
Cumple con los requisitos del ejercicio.

### tinylisp.h:
Declara correctamente las funciones requiridas para el cumplimiento de lo solicitado.

### tinylisp.cpp: 
Su código es capaz de cargar un script en la memoria y aplicarle la coloración correspondiente. 
Utilizó las librería estándar de C/C++ para la ejecución correcta de su trabajo.
Implementó las funciones "load_script()" y "load_script(filename, true)" para poder abrir y leer los archivos, utilizando los dos métodos señalados.
Ha manejado otros errores potenciales.

### main.cpp: 
Claro y conciso, contiene la cantidad de código adecuado para un archivo main.cpp.

### Valoración final código: 
El código realizado por mi compañero ha completado exitosamente las pautas dictadas por el enunciado. 
Se ha asegurado que mantiene una robustez en la compilación de código.

### Valoración final: 
Cumplió con todo lo debido, de una manera agradable para la vista de un programador.
No veo modificaciones que pudiese realizar para mejorarlo.
Sin embargo, el color del tema del CLion distrae un poco.
