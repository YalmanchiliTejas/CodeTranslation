#include <bits/stdc++.h>
using namespace std;
#define P pair<int,int>
#define ll long long
const int N = 200+10;
char s[N];
int n,k;
ll dp[N][4];//dp[N][k]N个0有多少个k个不是0的数
int main()
{
    scanf("%s",s+1);
    scanf("%d",&k);
    n=strlen(s+1);
    //dp[0][1]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=dp[i-1][1]+9;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=3;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*9;
        }
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    //cout<<dp[n][k]<<"\n";
    ll num=k;
    ll ans=0;
    for(int i=1;i<=n&&num;i++)
    {
        if(s[i]=='0')
            continue;
        if(num==1)
            ans+=(s[i]-'0')*dp[n-i][num-1]+dp[n-i][num];
        else
            ans+=(s[i]-'0'-1)*dp[n-i][num-1]+dp[n-i][num];
//        cout<<ans<<" "<<num<<"\n";
        num--;
    }
    cout<<ans;
    return 0;
}
