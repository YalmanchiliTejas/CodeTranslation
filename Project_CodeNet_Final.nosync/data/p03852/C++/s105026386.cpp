#include <stdio.h>

char A[6]={'a','e','i','o','u'};

int main()
{
    int flag=0;
    char x;
    scanf("%c", &x);

    for(int i=0; i<5; i++)
        if(x==A[i])
            flag = 1;

    if(flag) printf("vowel\n");
    else printf("consonant\n");

    return 0;

}
