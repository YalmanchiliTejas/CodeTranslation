#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
int main(){
    string S;int K;cin>>S>>K;
    int N = S.size();
    int dp[N][2][4];
    rep(i,N)rep(j,2)rep(k,4)dp[i][j][k]=0;
    ll x=S[0]-'0';
    dp[0][0][1]=1;
    dp[0][1][0]=1;
    dp[0][1][1]=x-1;
    rep(i,N-1){
        ll x=S[i+1]-'0';
        int p=0;
        if(x!=0)p=1;
        dp[i+1][0][1]=dp[i][0][1]*(!p);
        dp[i+1][0][2]=dp[i][0][1]*p+dp[i][0][2]*(!p);
        dp[i+1][0][3]=dp[i][0][2]*p+dp[i][0][3]*(!p);
        dp[i+1][1][0]=dp[i][1][0];
        dp[i+1][1][1]=9*dp[i][1][0]+dp[i][1][1]+dp[i][0][1]*p;
        dp[i+1][1][2]=9*dp[i][1][1]+dp[i][1][2]+dp[i][0][2]*p+dp[i][0][1]*(x-1)*p;
        dp[i+1][1][3]=9*dp[i][1][2]+dp[i][1][3]+dp[i][0][3]*p+dp[i][0][2]*(x-1)*p;
    }
    cout<<dp[N-1][0][K]+dp[N-1][1][K]<<endl;
    return 0;
}