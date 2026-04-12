#include<bits/stdc++.h>
#define LL long long
using namespace std;
#define inf 0x3fffffff

int n,m;
LL f[110][110][2][2];
char s[110];

int main()
{
    scanf("%s%d",s+1,&m);
    n=strlen(s+1);
    memset(f,0,sizeof(f));
    f[1][0][1][0]++;
    for (int i=1;i<s[1]-'0';i++)
        f[1][1][0][0]++;
    f[1][1][0][1]++;
    for (int i=2;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
        {
            f[i][j][0][0]+=f[i-1][j][0][0];
            for (int k=1;k<=9;k++)
            {
                f[i][j+1][0][0]+=f[i-1][j][0][0];
            }
            f[i][j][1][0]+=f[i-1][j][1][0];
            for (int k=1;k<=9;k++)
                f[i][j+1][0][0]+=f[i-1][j][1][0];
            if (s[i]=='0')
            {
                f[i][j][0][1]+=f[i-1][j][0][1];
            }
            else
            {
                f[i][j][0][0]+=f[i-1][j][0][1];
                for (int k=1;k<s[i]-'0';k++)
                    f[i][j+1][0][0]+=f[i-1][j][0][1];
                f[i][j+1][0][1]+=f[i-1][j][0][1];
            }
        }
    }
    LL ans=f[n][m][0][0]+f[n][m][0][1];
    cout<<ans<<endl;
    return 0;
}