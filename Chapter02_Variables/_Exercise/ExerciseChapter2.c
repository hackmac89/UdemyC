#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    u_int8_t age = 0;

    printf("Please enter your age in years: ");
    scanf("%hhu", &age);

    uint64_t days = age * 365UL;
    uint64_t hours = days * 24UL;
    uint64_t minutes = hours * 60UL;
    uint64_t seconds = minutes * 60UL;

    printf("You are living since %llu days\n", days);
    printf("You are living since %llu hours\n", hours);
    printf("You are living since %llu minutes\n", minutes);
    printf("You are living since %llu seconds\n", seconds);

    return 0;
}
