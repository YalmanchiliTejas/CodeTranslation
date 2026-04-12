#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
const int N=150;
char s[N];
ll dp[N][4][2];
int main()
{
    scanf("%s",s+1);
    scanf("%d",&k);
    n=strlen(s+1);
    dp[0][0][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=3;j++)
        {
            for(int h=0;h<=1;h++)
            {
                int f;
                if(h==0)
                    f=9;
                else
                    f=s[i]-'0';
                if(j==k) f=0;
                for(int m=0;m<=f;m++)
                {
                    dp[i][j+((m==0)?0:1)][h&&((m==f)?1:0)]+=dp[i-1][j][h];
                }
            }
        }
    }
    printf("%lld\n",dp[n][k][1]+dp[n][k][0]);
    return 0;
}
