#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=998244353;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n,s;
    cin>>n>>s;
    int a[n];
    rep(i,n)cin>>a[i];
    int dp[s+1]={};
    dp[0]=1;
    ll ans=0;
    rep(i,n){
        for(int j=s-1;j>0;--j){
            if(j+a[i]<=s){
                dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
            }
        }
        if(a[i]<=s){
            dp[a[i]]=(dp[a[i]]+i+1)%mod;
        }
        ans=(ans+dp[s])%mod;
    }
    cout<<ans<<endl;
}
