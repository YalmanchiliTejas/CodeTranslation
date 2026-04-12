#include<cstdio>
#include<cstring>

int main()
{
    char s[10];
    int lng = strlen(s);
    bool b = false;

    scanf("%s", s);

    for (int i = 0; i < lng - 1; i++)
        if (s[0 + i] == 'A' && s[1 + i] == 'C')
            b = true;

    if (b) printf("Yes");
    else printf("No");
}