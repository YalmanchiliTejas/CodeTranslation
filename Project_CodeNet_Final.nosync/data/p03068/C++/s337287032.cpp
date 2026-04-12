#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,k;
char s[15];
int main()
{
    scanf("%d %s %d",&n,s,&k);
    for(i=0;i<n;i++)
    {
        if(s[i]!=s[k-1])printf("*");
        else printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}