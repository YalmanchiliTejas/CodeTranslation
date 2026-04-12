#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[10];
    scanf("%s", s);
    for(int i=0; s[i+1]; i++)
    {
        if(s[i]=='A' && s[i+1]=='C')return 0*printf("Yes\n");
    }
    printf("No\n");
}
