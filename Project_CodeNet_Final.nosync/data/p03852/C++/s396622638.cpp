#include <stdio.h>

int main()
{
    char a;
    scanf("%c",&a);

    switch(a){
case 'a':
case 'i':
case 'u':
case 'e':
case 'o':
    printf("vowel");
    break;
default:
    printf("consonant");
    break;
    }

    return 0;
}
