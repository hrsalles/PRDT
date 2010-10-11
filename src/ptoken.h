/*
** Define os tipos para o restante do compilador
** Prefixo: pty
** $ Herond Robaina Salles
** 24 Mai 2010
*/

/* ========================================================================== */

#ifndef _PRD_TYPES_LIB
#define _PRD_TYPES_LIB

#include <string.h>

#include "pstring.h"

#define PTY_NULL_TOKEN 		(ptyDefToken(PTY_NONE, NULL, 0))
#define PTY_RESERVED_WORDS	(ptyReservedWords())

/* ========================================================================== */

enum PTYTokenId_EN {
    PTY_END_OF_FILE                 = 0,
    PTY_NONE                        = 1,

    PTY_ERROR_COMMENT               = 10,
    PTY_ERROR_HEXADECIMAL_CONSTANT  = 11,
    PTY_ERROR_BINARY_CONSTANT       = 12,
    PTY_ERROR_OCTAL_CONSTANT        = 13,
    PTY_ERROR_FLOAT_CONSTANT        = 14,
    PTY_ERROR_DECIMAL_CONSTANT      = 15,
    PTY_ERROR_STRING_CONSTANT       = 16,
    PTY_ERROR_DIRECTIVE             = 17,

    /*PTY_NULL_VAL                    = 130,*/

    PTY_OP_NOT                      = 140,
    PTY_OP_INC                      = 141,
    PTY_OP_DEC                      = 142,
    PTY_OP_MUL                      = 143,
    PTY_OP_DIV                      = 144,
    PTY_OP_MOD                      = 145,
    PTY_OP_ADD                      = 146,
    PTY_OP_SUB                      = 147,
    PTY_OP_TO                       = 148,
    PTY_OP_SML                      = 149,
    PTY_OP_SEQ                      = 150,
    PTY_OP_BIG                      = 151,
    PTY_OP_BEG                      = 152,
    PTY_OP_EQV                      = 153,
    PTY_OP_DIF                      = 154,
    PTY_OP_EQL                      = 155,
    PTY_OP_NQL                      = 156,
    PTY_OP_AND                      = 157,
    PTY_OP_OR                       = 158,
    PTY_OP_AML                      = 159,
    PTY_OP_ADV                      = 160,
    PTY_OP_AMD                      = 161,
    PTY_OP_AAD                      = 162,
    PTY_OP_AMN                      = 163,
    PTY_OP_IST                      = 164,
    PTY_OP_ASG                      = 165,
    PTY_OP_DEF                      = 166,
    PTY_OP_ADF                      = 167,

    PTY_USES                        = 175,
    PTY_LINKED                      = 176,
    PTY_ONLY                        = 177,
    PTY_EXCEPT                      = 178,
    PTY_OPERATOR                    = 179,
    PTY_CONST                       = 180,
    PTY_MAIN                        = 181,
	PTY_STATIC						= 182,
	PTY_SHARED						= 183,
	PTY_INTERNAL					= 184,
	PTY_FIX							= 185,

    PTY_END_COMMAND                 = 190,
    PTY_RETICENCE                   = 192,
    PTY_DOT                         = 193,
    PTY_ESCOPE_RESOLUTION           = 194,
    PTY_POINTER                     = 195,

    PTY_LEFT_PARENTHESIS            = 200,
    PTY_RIGHT_PARENTHESIS           = 201,
    PTY_LEFT_BRACE                  = 202,
    PTY_RIGHT_BRACE                 = 203,
    PTY_LEFT_BRACKET                = 204,
    PTY_RIGHT_BRACKET               = 205,

    PTY_BIN_INT_VAL                 = 210,
    PTY_OCTAL_INT_VAL               = 211,
    PTY_DECIMAL_INT_VAL             = 212,
    PTY_HEXADECIMAL_INT_VAL         = 213,
    PTY_FLOAT_VAL                   = 214,
    PTY_STRING_VAL                  = 215,

    PTY_ID                          = 220,
    PTY_COMMENT                     = 221

};

typedef struct {
    int id;
    char* lexeme;
    unsigned line;
} PTYToken_ST;

/* ========================================================================== */

PTYToken_ST ptyDefToken (int id, const char* lexeme, unsigned line);

PTYToken_ST ptyCopyToken (PTYToken_ST token);

int ptyIsNullToken (PTYToken_ST token);

int ptyIsLastToken (PTYToken_ST token);

PTYToken_ST ptyGetToken (const char* lexeme, const PTYToken_ST token_list[]);

const PTYToken_ST* ptyReservedWords (void);

/* ========================================================================== */

#endif
