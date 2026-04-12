#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);i--)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll) 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
	to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

ll pow2_m(ll x, ll n, ll mod) {
 ll ans = 1ll;
 while (n > 0) {
  if ((n & 1) == 1) {
   ans = ans * x % mod;
  }
  x = x * x % mod;
  n >>= 1;
 }
 return ans;
}

void solve(){
    ll n;
    cin>>n;
    Array a(n);
    REP(i,n) cin>>a[i];

    Matrix dp(3,Array(n+5,-INF));
    dp[0][0]=0;
    dp[1][1]=0;
    dp[2][2]=0;

    REP(i,n){
        if(i%2==0){
            chmax(dp[0][i+2],dp[0][i]+a[i]);
            chmax(dp[1][i+3],dp[0][i]+a[i]);
            chmax(dp[2][i+4],dp[0][i]+a[i]);
            chmax(dp[2][i+2],dp[2][i]+a[i]);
        }else{
            chmax(dp[1][i+2],dp[1][i]+a[i]);
            chmax(dp[2][i+3],dp[1][i]+a[i]);
        }
    }


    if(n%2==0) cout<<max(dp[0][n],dp[1][n+1])<<en;
    else cout<<max({dp[0][n-1],dp[1][n],dp[2][n+1]})<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    //ll t;cin>>t;REP(i,t) solve();

    return 0;
}
