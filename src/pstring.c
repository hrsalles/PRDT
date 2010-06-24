/*
** Manipula strings
** Prefixo: pst
** $ Herond Robaina Salles
** 07 Mai 2010
*/

/* ========================================================================== */

#ifndef PRD_STRING
#define PRD_STRING

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PST_NOT_PRESENT (-1)

/* ========================================================================== */

char* pstPersist (const char* string) {
    if (string) {
        char* string_copy = (char*) malloc(sizeof(char) * (strlen(string) + 1));

        if (string_copy) return strcpy(string_copy, string);
    }

    return NULL;
}

int pstLocationOf (const char* string, const char** array) {
    int i;

    if (string && array)
        for (i = 0; ; i++) {
            if (!array[i]) break;
            if (!strcmp(string, array[i])) return i;
        }

    return PST_NOT_PRESENT;
}

char* pstCharToString (char character) {
    char* string_return = (char*) malloc(sizeof(char) * 2);

    if (string_return) {
        string_return[0] = character;
        string_return[1] = '\0';
    }

    return string_return;
}

char* pstAddChar (char* string, unsigned position, char character) {
    if (string && position <= strlen(string)) {
        string[position]     = character;
        string[position + 1] = '\0';
    }

    return string;
}

char* pstCharApend (char** string, char character) {
    if (string) {
        char* string_aux = (char*) realloc(*string, sizeof(char*) * (strlen(*string) + 1));

        if (string_aux) {
            if (*string != string_aux) {
                char* dirty = *string;

                *string = strcpy(string_aux, *string);
                free(dirty);
            }

            string[0][strlen(*string)] = character;
            string[0][strlen(*string) + 1] = '\0';
        }
    }

    return *string;
}

/* ========================================================================== */

#endif

