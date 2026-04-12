#include <cstdio>

int main()
{
    char a;
    scanf("%c", &a);
    if (a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u')
    {
        printf("vowel");
    }
    
    else
    {
        printf("consonant");
    }
}
