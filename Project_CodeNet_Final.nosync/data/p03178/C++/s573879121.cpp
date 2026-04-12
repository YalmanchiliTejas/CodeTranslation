#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
const int N = 100007;
const int K = 107;

int dp[N][K][2];
char s[N];
int a[N];
int n,m;

int dfs(int k,int now,int lim)
{
    if(dp[k][now][lim]>=0) return dp[k][now][lim];
    if(k==m) return dp[k][now][lim] = (now==0);
    int sum = 0;
    int up = lim?a[k]:9;
    for(int i=0;i<=up;i++)
    {
        sum += dfs(k+1,(now+i)%n,lim&&i==up);
        sum%=mod;
    }
    return dp[k][now][lim] = sum;
}


int main()
{
    scanf("%s%d",s,&n);
    m = strlen(s);
    for(int i=0;i<m;i++)
    {
        a[i] = s[i]-'0';
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",(dfs(0,0,1)+mod-1)%mod);
    return 0;

}
