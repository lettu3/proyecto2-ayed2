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
    while (s1[i] && s2[i] && s1[i] == s2[i]){       
        i = i + 1;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {       
        res = true; 
    } 
    else if (s1[i] <= s2[i]) {                  
        res = true;
    }
    return res;
}

void fstring_set(fixstring s1, const fixstring s2) {
    int i=0;
    while (i<FIXSTRING_MAX && s2[i]!='\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void fstring_swap(fixstring s1,  fixstring s2) {
    fixstring aux;
    fstring_set(aux, s1);  // Guardamos la cadena s1 en una variable auxiliar
    fstring_set(s1, s2);  // Copiamos la cadena s2 en s1
    fstring_set(s2, aux);  // Copiamos la cadena original s1 en s2
}


