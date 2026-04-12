#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n,s;cin>>n>>s;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    vector<vector<ll> >dp(n+1,vector<ll>(s+1));
    dp[0][0]=1;
    rep(i,n){
        rep(j,s){
            dp[i+1][j]=(dp[i][j]+dp[i+1][j])%mod;
            if(j>0)if(j+a[i]<=s)dp[i+1][j+a[i]]=(dp[i+1][j+a[i]]+dp[i][j])%mod;
            if(j==0&&a[i]<=s){
                dp[i+1][a[i]]=(dp[i+1][a[i]]+i+1)%mod;
            }
        }
    }
    ll ans=0;
    rep(i,n+1){
        ans=(ans+dp[i][s]*(n+1-i))%mod;
        //cout<<i<<' '<<dp[i][s]<<endl;
    }
    cout<<ans<<endl;
}