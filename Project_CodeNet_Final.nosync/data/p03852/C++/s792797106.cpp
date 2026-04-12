#include <stdio.h>

int main(void)
{
    char r;
    scanf("%c" ,&r);
    if(r=='a' || r=='e' || r=='i' || r=='o' || r=='u')
        printf("vowel");
    else
        printf("consonant");

}