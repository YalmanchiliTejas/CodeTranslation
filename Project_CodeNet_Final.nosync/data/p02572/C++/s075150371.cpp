#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    ll mod=1e9+7;
    vector<ll> a;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        ll b;cin>>b;
        a.push_back(b%mod);
    }
    ll dp[n+1];
    ll sum=(a[0]+a[1])%mod;
    for(int i=0;i<=n;i++)dp[i]=0;
    dp[1]=a[0]*a[1]%mod;
    for(int i=1;i<n-1;i++){
        dp[i+1]=dp[i]+a[i+1]*sum%mod;
        dp[i+1]%=mod;
        sum+=a[i+1];
        sum%=mod;
    }
    cout <<dp[n-1];

}