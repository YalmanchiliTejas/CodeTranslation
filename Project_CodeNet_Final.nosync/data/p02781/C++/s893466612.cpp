#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<(n);++i)
#define rep2(i,a,b) for (ll i=(a);i<(b);++i)
#define debug(x) cout << #x << '=' << x << endl
#define all(v) (v).begin(),(v).end()
const ll MOD=1e9+7;
//const ll MOD=998244353;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){a=b; return true;} return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;} return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string N; int K; cin >> N >> K;
    int n=N.size();
    ll dp[n+1][K+1][2];
    rep(i,n+1) rep(j,K+1) rep(k,2) dp[i][j][k]=0;
    dp[0][0][1]=1;
    rep(i,n) rep(j,K+1) rep(k,2){
        if (k){
            int x=N[i]-'0';
            if (x!=0){
                dp[i+1][j][0]+=dp[i][j][k];
                if (j<K) dp[i+1][j+1][0]+=dp[i][j][k]*(x-1);
                if (j<K) dp[i+1][j+1][1]+=dp[i][j][k];
            }
            else dp[i+1][j][1]+=dp[i][j][k];
        } else {
            dp[i+1][j][0]+=dp[i][j][k];
            if (j<K) dp[i+1][j+1][0]+=dp[i][j][k]*9;
        }
    }
    cout << dp[n][K][0]+dp[n][K][1] << endl;
}