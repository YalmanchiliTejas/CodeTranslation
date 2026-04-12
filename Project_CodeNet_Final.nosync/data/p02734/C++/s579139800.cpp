//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,s,ans=0; cin>>n>>s;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(3001,0));
    rep(i,n)rep(j,3001){
        dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
        if(j==0) dp[i+1][a[i]]=i+1;
        else{
            if(j+a[i]<=3000)
            dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%mod;
        }
        if(j+a[i]==s)
            ans=(ans+dp[i+1][j+a[i]]*(n-i))%mod;
    }
    cout<<ans<<endl;
}