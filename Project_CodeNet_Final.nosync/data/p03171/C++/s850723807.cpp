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
constexpr int loose = 0;
constexpr int tight = 1;


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

ll n;
ll a[3010];
ll dp_taro[3010][3010];
ll dp_jiro[3010][3010];

ll jiro(ll l, ll r);

ll taro(ll l, ll r){
	if(dp_taro[l][r]!=-1) return dp_taro[l][r];
	if(l==r) return dp_taro[l][r] = a[l];
	return dp_taro[l][r] = max(a[l]+jiro(l+1,r), a[r]+jiro(l,r-1));
}

ll jiro(ll l, ll r){
	if(dp_jiro[l][r]!=-1) return dp_jiro[l][r];
	if(l==r) return dp_jiro[l][r] = -a[l];
	return dp_jiro[l][r] = min(-a[l]+taro(l+1,r), -a[r]+taro(l,r-1));
}

void solve(){
	cin>>n;
	REP(i,n) cin>>a[i];
	memset(dp_taro,-1,sizeof(dp_taro));
	memset(dp_jiro,-1,sizeof(dp_jiro));

	cout<<taro(0,n-1)<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}