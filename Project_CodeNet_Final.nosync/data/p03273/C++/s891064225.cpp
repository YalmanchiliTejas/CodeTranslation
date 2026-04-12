#include<bits/stdc++.h>
using namespace std;

int a[110],b[110];
char s[110][110];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",s[i]+1);
        for(int j=1; j<=m; j++)
        if(s[i][j]=='#')a[i]=1,b[j]=1;
    }
    for(int i=1; i<=n; i++)
        if(a[i])
        {
            for(int j=1; j<=m; j++)
                if(b[j])
                    printf("%c",s[i][j]);
            printf("\n");
        }
    return 0;
}
