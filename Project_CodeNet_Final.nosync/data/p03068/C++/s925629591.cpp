#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[100005];
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d",&k);
    for(int i=1;i<=n;i++)
        if(s[i]!=s[k]) s[i]='*';
    printf("%s",s+1);
}
