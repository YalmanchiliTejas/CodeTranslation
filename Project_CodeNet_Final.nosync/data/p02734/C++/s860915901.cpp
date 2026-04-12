#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define MOD 998244353
int a[3030];
lli dp[3030][3030];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,s=0;lli res=0ll;
    cin>>n>>s;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<sizeof(dp[0]);++j)
            dp[i+1][j]=dp[i][j];
        dp[i+1][a[i]]=(dp[i+1][a[i]]+i+1)%MOD;
        for(int j=0;a[i]+j<=s;++j)
            dp[i+1][a[i]+j]=(dp[i+1][a[i]+j]+dp[i][j])%MOD;
        res=(res+dp[i+1][s])%MOD;
    }
    cout<<res<<endl;
}
