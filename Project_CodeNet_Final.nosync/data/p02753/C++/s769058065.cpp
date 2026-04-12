#include <stdio.h>

int main (void)
{
    char str[3];
    scanf("%s", str);

    if (str[0] != str[1]) {
        printf("Yes");
    } else if (str[1] != str[2]) {
        printf("Yes");
    } else if (str[2] != str[0]) {
        printf("Yes");
    } else {
        printf("No");
    }
    return 0;
}