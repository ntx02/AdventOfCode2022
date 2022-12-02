#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[])
{
    FILE *fp = fopen("input.txt", "r");

    int firstMax = 0, secondMax = 0, thirdMax = 0, currTotal = 0;
    char currLine[10];

    while (fgets(currLine, 10, fp))
    {
        if (!strcmp(currLine, "\n"))
        {
            thirdMax = (currTotal > thirdMax && currTotal < secondMax) ? currTotal : thirdMax;
            secondMax = (currTotal > secondMax && currTotal < firstMax) ? currTotal : secondMax;
            firstMax = (currTotal > firstMax) ? currTotal : firstMax;

            currTotal = 0;
        }
        currTotal += strtol(currLine, NULL, 10);
    }

    printf("Combined top three calories: %d\n", firstMax + secondMax + thirdMax);
    fclose(fp);
}