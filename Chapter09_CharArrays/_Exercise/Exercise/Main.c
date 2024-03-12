#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aufgabenstellung war nicht eindeutig, habe deshalb einfach ein größeres "malloc" gemacht ohne dynamische reallokation.
char *join(char *delimiter, char **list)
{
    char *ret = (char *)malloc(256 * sizeof(char));
    uint16_t size = 0;
    uint16_t size_delim = strlen(delimiter);

    if( ( delimiter == NULL ) || ( list == NULL ) || ( list[0] == NULL ) )
        return NULL;

    size_t i = 0;
    while(list[i] != NULL) {
        //printf("Current list item: %s\n", list[i]);
        size = strlen(list[i]);

        strncat(ret, list[i], size);
        if ( list[i+1] != NULL )
            strncat(ret, delimiter, size_delim);
        i++;
    }

    return ret;
}

int main(int argc, char **argv)
{
    char *list1[] = {NULL};
    char *list2[] = {"Clara", NULL};
    char *list3[] = {"Clara", "Florian", NULL};
    char *list4[] = {"Clara", "Florian", "Jan", NULL};
    char *s = NULL;

    s = join(" -> ", list1); // ""
    if (NULL != s)
    {
        printf("List1: %s\n", s);
        free(s);
    }

    s = join(" -> ", list2); // "Clara"
    if (NULL != s)
    {
        printf("List2: %s\n", s);
        free(s);
    }

    s = join(" -> ", list3); // "Clara -> Florian"
    if (NULL != s)
    {
        printf("List3: %s\n", s);
        free(s);
    }

    s = join(" -> ", list4); // "Clara -> Florian -> Jan"
    if (NULL != s)
    {
        printf("List4: %s\n", s);
        free(s);
    }

    return 0;
}
