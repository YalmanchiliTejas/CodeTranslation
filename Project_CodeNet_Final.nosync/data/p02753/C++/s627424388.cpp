#include <stdio.h>

int main()
{
    char inputA, inputB, inputC;

    scanf("%c%c%c", &inputA, &inputB, &inputC);
    (inputA + inputB + inputC == 195 || inputA + inputB + inputC == 198) ? puts("No") : puts("Yes");

    return 0;
}