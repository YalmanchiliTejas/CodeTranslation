#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,c=0;
    char s[10];
    scanf("%s",s);
    for(i=0;i<2;i++)
    {
        if(s[i]==s[i+1]||s[i]==s[i+2])
        {
            c++;
        }
    }
    if(c==1)
    {
        printf("Yes\n");
    }
    else printf("No\n");
}
