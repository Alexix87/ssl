#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO_NOMBRE 20+1 //tamanio de nombre de archivo permitido


FILE * in;

void Objetivo(void);

int main(int argc, char * argv[]){

    char nombreArchivo[TAMANIO_NOMBRE];
    int largoDeNombre;

//verifica errores posibles
    if ( argc == 1 ){
        printf("Debe ingresar el nombre del archivo fuente (en lenguaje Micro) en la linea de comandos\n");
        return -1;
    }

    if ( argc != 2 ){
        printf("Numero incorrecto de argumentos\n");
        return -1;
    }

    strcpy(nombreArchivo, argv[1]);
    largoDeNombre = strlen(nombreArchivo);

    if ( largoDeNombre > TAMANIO_NOMBRE ){
        printf("Nombre incorrecto del Archivo Fuente\n");
        return -1;
    }

    //requiere para compilar un archivo de extensión.m archivo.m
    if ( nombreArchivo[largoDeNombre-1] != 'm' || nombreArchivo[largoDeNombre-2] != '.' ){
        printf("Nombre incorrecto del Archivo Fuente, debe terminar en .m\n");
        return -1;
    }

    if ( (in = fopen(nombreArchivo, "r") ) == NULL ){
        printf("No se pudo abrir archivo fuente\n");
        return -1;//no pudo abrir archivo
    }
//fin de verificaciones

    Objetivo();

    fclose(in);
    return 0;
}

void Objetivo(void){
 /* <objetivo> -> <programa> FDT #terminar */
 /*
    Programa();
    Match(FDT);
    Terminar();
*/
}


