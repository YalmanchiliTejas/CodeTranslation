#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
#define ll long long

ll dp[3500][3500];

ll n,s;

ll a[3500];

int main(){
    scanf("%lld%lld",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        dp[i][a[i]]=i;
        for(int j=a[i];j<=s;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
        ans=(ans+dp[i][s]*(n-i+1)%mod)%mod;
        for(int j=1;j<=s;j++){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        }
    }
    cout<<ans<<endl;
}
