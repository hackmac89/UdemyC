#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char PROJECT_DIR[] = "/Users/jwagner3/Development/C/Udemy/UdemyC/";

int main(int argc, char **argv)
{
    char input_filepath[100] = {'\0'};
    strncpy(input_filepath, PROJECT_DIR, 100);
    strncat(input_filepath,
            "Chapter11_Files/_Exercise/Exercise/InputData.txt",
            60);

    FILE *fp_in = fopen(input_filepath, "r");
    if (fp_in == NULL) {
        return -1;
    }

    uint8_t max_char_count = 100;
    uint8_t max_idx = 10;

    char **text = (char **)malloc(max_idx * sizeof(char *));
    for (uint8_t i = 0; i < max_idx; i++)
        text[i] = (char *)malloc(max_char_count * sizeof(char));

    char *tmp_buf = (char *)calloc(max_char_count, sizeof(char));

    size_t i = 0;
    while ((fgets(tmp_buf, max_char_count, fp_in) != NULL) && (i < max_idx)) {
        strncpy(text[i], tmp_buf, max_char_count);
        i++;
    }
    free(tmp_buf);

    for (unsigned int i = 0; i < max_idx; i++) {
        if (strlen(text[i]) > 0)
            printf("%d: %s", i+1, text[i]);
    }

    for (uint8_t i = 0; i < max_idx; i++)
        free(text[i]);
    free(text);

    return 0;
}
