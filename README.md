# TP integrador de Sintaxis y semántica de los lenguajes - Compilador del lenguaje Micro de Fischer

## Características del lenguaje: 

* El único tipo de dato es entero.
* Todos los identificadores son declarados implícitamente y con una longitud máxima de 32 caracteres.
* Los identificadores deben comenzar con una letra y están compuestos de letras y dígitos.
* Las constantes son secuencias de dígitos (números enteros).
* Hay dos tipos de sentencias:
  * Asignación:
	    **ID := Expresion;**
  
  * Entrada/Salida:
	    **leer (lsita de IDs);**
	    **escribir (lista de Expresiones);**
    
* Cada sentencia termina con un "punto y coma" (;). El cuerpo de un programa está delimitado por inicio y fin.
* inicio, fin, leer y escribir son palabras reservadas y deben escribirse en minúscula.


## Gramática Léxica:
```
<token> -> uno de <identificador> <constante> <palabraReservada>
<operadorAditivo> <asignación> <carácterPuntuación>
<identificador> -> <letra> {<letra o dígito>}
<constante> -> <dígito> {dígito>}
<letra o dígito> -> uno de <letra> <dígito>
<letra> -> una de a-z A-Z
<dígito> -> uno de 0-9
<palabraReservada> -> una de inicio fin leer escribir
<operadorAditivo> -> uno de + -
<asignación> -> :=
<carácterPuntuación> -> uno de ( ) , ; 
```

## Gramática Sintáctica:
```
<programa> -> inicio <listaSentencias> fin
<listaSentencias> -> <sentencia> {<sentencia>}
<sentencia> -> <identificador> := <expresión> ; |
leer ( <listaIdentificadores> ) ; |
escribir ( <listaExpresiones> ) ;
<listaIdentificadores> -> <identificador> {, <identificador>}
<listaExpresiones> -> <expresión> {, <expresión>}
<expresión> -> <primaria> {<operadorAditivo> <primaria>}
<primaria> -> <identificador> | <constante> |
( <expresión> )
```

---
En la versión 2 se agrega una función para que muestre por pantalla a medida que se ejecutan las funciones el texto del código fuente micro que falta procesar.
