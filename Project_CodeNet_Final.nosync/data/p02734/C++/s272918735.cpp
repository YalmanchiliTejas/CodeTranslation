#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3005][3005];
int pre[3005];
int main() {
    const ll mod=998244353;ll ans=0;
    int n,s;cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>pre[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=i+1;
        for(int j=1;j<=s;j++){
            dp[i][j]=(dp[i-1][j]+(j>=pre[i]?dp[i-1][j-pre[i]]:0))%mod;
        }
        if(pre[i]<=s)
            ans=(ans+dp[i-1][s-pre[i]]*(n-i+1)%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}