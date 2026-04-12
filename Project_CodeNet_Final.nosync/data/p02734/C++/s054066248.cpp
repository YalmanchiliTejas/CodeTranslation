//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=1000000007LL;
const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

ll dp[3010][3010];
int main(){
    ll n,s;cin>>n>>s;
    vl a(n+1);
    rep(i,3010){
        rep(j,3010)dp[i][j]=0;
    }
    rep(i,n)cin>>a[i+1];
    dp[1][0]=1;
    dp[1][a[1]]=1;
    for(ll i=2;i<=n;i++){
      rep(j,s+1){
        dp[i][j]+=2*dp[i-1][j];
        dp[i][j]-=dp[i-2][j];
        if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]]-dp[i-2][j-a[i]];
        dp[i][j]%=MOD;
      }
      dp[i][0]++;
      dp[i][a[i]]++;
    }
    cout<<(dp[n][s]+MOD)%MOD<<endl;
    //rep(i,n+1){
        //rep(j,s+1)cout<<dp[i][j]<<" ";
        //cout<<endl;
    //}
}