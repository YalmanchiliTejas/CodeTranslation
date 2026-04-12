#include <stdio.h>
#include <string.h>

 int main()
{
    char S[3];
    scanf("%s",S);
    if ((strcmp(S , "AAB") == 0) || (strcmp(S , "ABA") == 0) || (strcmp(S , "BBA") == 0) || (strcmp(S , "BAB") == 0) || (strcmp(S , "ABB") == 0) || (strcmp(S , "BAA") == 0))
    {
        puts("Yes");
    }
    else 
    {
        puts("No");
    }

    return 0;
} 