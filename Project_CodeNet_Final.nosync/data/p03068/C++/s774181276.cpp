#include <stdio.h>
int main()
{
    int n,i,d;
    scanf("%d",&n);
    char s[100];
    scanf(" %s",s);
    scanf("%d",&d);
    d--;
    for(i=0;i<n;i++)
    {
        if(s[i]!=s[d])
        {
            s[i]='*';
        }
    }
    printf("%s\n",s);
}