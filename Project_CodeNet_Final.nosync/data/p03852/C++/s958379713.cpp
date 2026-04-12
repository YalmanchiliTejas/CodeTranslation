#include<stdio.h>
int main()
{
    char Aa;
    scanf("%c",&Aa);

    if(Aa =='a' || Aa == 'e' || Aa == 'i' || Aa == 'o' || Aa=='u')
    {
        printf("vowel\n");
    }

    else
    {
        printf("consonant\n");
    }

}