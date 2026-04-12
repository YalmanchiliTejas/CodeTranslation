#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 200;


char st[maxn][maxn];
int num[maxn][maxn];
int flag[maxn], flag2[maxn];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        scanf("%s",st[i]+1);

    for(int i=1; i<=n; i++)
    {
        for(int j=1 ; j<= m; j++)
        {
            if(st[i][j] == '.')
                num[i][j] = num[i][j-1] + 1;
            else
                num[i][j] = num[i][j-1];
        }
        if(num[i][m] == m)
            flag[i] = 1;
    }
    memset(num,0,sizeof(num));

    for(int j=1 ; j<= m; j++)
    {
        for(int i=1; i<=n; i++)

        {
            if(st[i][j] == '.')
                num[j][i] = num[j][i-1] + 1;
            else
                num[j][i] = num[j][i-1];
        }

        if(num[j][n] == n)
            flag2[j] = 1;

    }


    for(int i=1;i<=n;i++)
    {
        if(flag[i] == 1) continue;
        for(int j=1;j<=m;j++)
        {
            if(flag2[j] == 1)
                continue;
            printf("%c",st[i][j]);
        }
        puts("");
    }



}
