#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;

int main() {
    char c;

    if (scanf("%c", &c) < 1) return 0;

    if (c == 'a' || c == 'e' || c == 'i'
        || c == 'o' || c == 'u')
    {
        printf("%s\n", "vowel");
    }
    else
    {
        printf("%s\n", "consonant");
    }

    return 0;
}
