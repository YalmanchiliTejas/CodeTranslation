#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);
    if (c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u')
        puts("vowel");
    else
        puts("consonant");
    return 0;
}
