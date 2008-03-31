

#include <st-compiler.h>
#include <st-lexer.h>
#include <st-node.h>
#include <st-universe.h>

#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define BUF_SIZE 10000

int
main (int argc, char *argv[])
{
    /* read input from stdin */
    char buffer[BUF_SIZE];
    char c;
    int i = 0;
    while ((c = getchar ()) != EOF && i < (BUF_SIZE - 1))
	buffer[i++] = c;
    buffer[i] = '\0';

    /* the big bang */
    st_bootstrap_universe ();

    STLexer *lexer = st_lexer_new (buffer);

    GError *error = NULL;

    STNode *node = st_parser_parse (lexer, &error);
    if (!node) {
	fprintf (stderr, "error: %s\n", error->message);
	g_error_free (error);
	exit (1);
    }

    printf ("-------------------\n");	    

    st_print_method_node (node);

    st_node_destroy (node);

    return 0;
}
