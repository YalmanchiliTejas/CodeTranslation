#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stack[100][1000], *sp[100];
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; ++i) sp[i] = stack[i];

    while (true) {
        char s[12]; // "push ppp a\n"
        fgets(s, 12, stdin);
        s[strlen(s) - 1] = '\0';
        if (strcmp(s, "quit") == 0) break;

        if (strncmp(s, "pop ", 4) == 0) printf("%c\n", *--sp[atoi(&s[4]) - 1]);
        else if (strncmp(s, "push ", 5) == 0) {
            int i;
            char c;
            sscanf(s, "push %d %c", &i, &c);
            *sp[i - 1]++ = c;
        }
        else {
            int i, j;
            sscanf(s, "move %d %d", &i, &j);
            *sp[j - 1]++ = *--sp[i - 1];
        }
    }

    return 0;
}