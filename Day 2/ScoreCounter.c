#include <stdio.h>

#define ASCII_FALLOFF 65
#define ASCII_DIFF 88
#define DRAW_DIRECTIVE 1
#define WIN_DIRECTIVE 2

void main()
{
    FILE *fp = fopen("input.txt", "r");

    int totalScore = 0;
    char line[5];

    while (fgets(line, 5, fp))
    {
        char opponent, friendly;
        sscanf(line,"%c %c", &opponent, &friendly);

        int friendInt, friendIntInit = friendly - ASCII_DIFF, opponentInt = opponent - ASCII_FALLOFF;

        friendInt = (friendIntInit == WIN_DIRECTIVE) ? (4 + opponentInt) % 3 : (5 + opponentInt) % 3;
        friendInt = (friendIntInit == DRAW_DIRECTIVE) ? opponentInt : friendInt;

        totalScore += 3 * friendIntInit + friendInt + 1;
    }

    printf("Total score: %d\n", totalScore);
    fclose(fp);
}
