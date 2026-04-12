#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[5], a[] = "AAA", b[] = "BBB";
    scanf("%s", s);
    if(!strcmp(s, a) || !strcmp(s, b))
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}