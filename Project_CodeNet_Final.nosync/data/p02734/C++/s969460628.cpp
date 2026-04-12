#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=998244353;

#define pb push_back
#define mp make_pair

ll dp[3001][3001];


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t,n,s;
    cin>>n>>s;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    ll ans=0;
    for(ll i=0;i<n;i++){
        memcpy(dp[i+1],dp[i],sizeof(dp[0]));
        dp[i+1][a[i]]=dp[i+1][a[i]]+i+1;
        for(ll j=0;j+a[i]<=s;j++){
                dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%mod;
        }
        ans=(ans+dp[i+1][s])%mod;
    }
    cout<<ans;

    return 0;
}


