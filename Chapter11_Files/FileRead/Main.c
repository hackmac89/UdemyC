#include <stdio.h>
#include <string.h>

#include "Lib.h"

char PROJECT_DIR[] = "/Users/jwagner3/Development/C/Udemy/UdemyC/";

int main(int argc, char **argv)
{
    char input_filepath[100] = {'\0'};
    strncpy(input_filepath, PROJECT_DIR, 100);
    strncat(input_filepath, "Chapter11_Files/FileRead/InputData.txt", 60);

    FILE *fp = fopen(input_filepath, "r");

    if (NULL == fp)
    {
        return 1;
    }

    Vector v1 = {.data = createArray(5, 0), .length = 5};

    for (unsigned int i = 0; i < v1.length; i++)
    {
        fscanf(fp, "%d", &v1.data[i]);
    }

    fclose(fp);

    printVector(&v1);

    freeArray(v1.data);

    return 0;
}
