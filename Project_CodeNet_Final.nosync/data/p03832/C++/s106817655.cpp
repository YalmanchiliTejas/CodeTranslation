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
    if (a>b){a=b; return true;}
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){a=b; return true;}
    return false;
}

const int MAX = 510000;
vector<ll> fac(MAX),finv(MAX),inv(MAX);
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    rep2(i,2,MAX){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if (n<k) return 0;
    if (n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,A,B,C,D; cin >> N >> A >> B >> C >> D;
    COMinit();
    vector<vector<ll>> powfinv(N+1,vector<ll>(N+1,1));
    rep2(i,A,B+1){
        rep2(j,1,N+1){
            powfinv[i][j]=powfinv[i][j-1]*finv[i]%MOD;
        }
    }
    vector<vector<ll>> dp(B+2,vector<ll>(N+1,0));
    dp[A][N]=1;
    rep2(i,A,B+1){
        rep(j,N+1){
            dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
            for (int k=C;j-i*k>=0&&k<=D;++k){
                dp[i+1][j-i*k]=(dp[i+1][j-i*k]+dp[i][j]*fac[j]%MOD*finv[j-i*k]%MOD*powfinv[i][k]%MOD*finv[k]%MOD)%MOD;
            }
        }
    }
    cout << dp[B+1][0] << endl;
}