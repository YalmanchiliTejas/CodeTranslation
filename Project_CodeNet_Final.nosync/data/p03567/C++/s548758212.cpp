#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[10];
    scanf("%s",s);
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='A'&&s[i+1]=='C')
        {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
