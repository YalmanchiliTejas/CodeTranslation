#include <cstdio>

#define vowel "vowel"
#define conso "consonant"

using namespace std;

int main() {
    char s[1];
    scanf("%s",s);
    switch(s[0]){
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
            printf(vowel);
            break;
        default:
            printf(conso);
            break;
    }
    printf("\n");
}