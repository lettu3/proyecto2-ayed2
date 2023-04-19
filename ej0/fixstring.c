#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i = 0;
    while (s[i] != '\0'){
        i = i + 1;
    }

    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool res = true;
    for (unsigned int i = 0u; i < FIXSTRING_MAX; ++i){
        res = res && (s1[i] == s2[i]);
    }
    return res;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool res = false;
    unsigned int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i]){       //itera hasta que encuentre caracteres dispares o llegue al final de la cadena
        i = i + 1;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {       //luego, si ambas cadenas tienen un caracter nulo en la posicion i, entonces son iguales
        res = true; 
    } 
    else if (s1[i] <= s2[i]) {                  //checkeamos si el caracter dispar es menor o igual
        res = true;
    }
    return res;
}

