#include<cstdio>
int main()
{
    char c;
    scanf("%c", &c);
    if(c==97||c==101||c==105||c==111||c==117)
    {
        printf("vowel\n");
        return 0;
    }
    printf("consonant\n");
    return 0;
}
