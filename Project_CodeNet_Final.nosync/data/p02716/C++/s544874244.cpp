#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
const ll MOD = 998244353;
//const ll MOD = (1e+9) + 7;
const ll INF = 1LL<<58;
typedef pair<ll, ll> P;

template<class T> bool chmin(T &a, const T &b){
    if(a > b) {a = b; return true;}
    else return false;
}
template<class T> bool chmax(T &a, const T &b){
    if(a < b) {a = b; return true;}
    else return false;
}

int main() {
    cin>>N;
    vec a(N);
    rep(i,N) cin>>a[i];
    int skip = (N&1 ? 3 : 2);
    vector<mat> dp(N + 1, mat(2, vec(skip, 0)));
    rep(j,2) rep(k,skip) dp[0][j][k] = -INF;
    dp[0][0][0] = 0;
    rep(i,N){
        rep(k,skip){
            dp[i+1][0][k] = dp[i][1][k];
            if(k != 0) chmax(dp[i+1][0][k], dp[i][0][k-1]);
            dp[i+1][1][k] = dp[i][0][k] + a[i];
        }
    }
    ll ans = max(dp[N][0][skip - 1], dp[N][1][skip - 1]);
    chmax(ans, dp[N][0][skip - 2]);
    cout<<ans<<endl;
}