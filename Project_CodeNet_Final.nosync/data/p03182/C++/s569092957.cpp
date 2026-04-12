#include <bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);i--)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll) 1e9 + 7;
//constexpr long long MOD = 998244353LL;
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
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

template<typename T,typename E,typename F,typename G,typename H,typename P>
class LazySegmentTree {
private:
    const T identity_t;
    const E identity_e;
    F f_tt;
    G f_te;
    H f_ee;
    P f_ep;//区間に比例する場合*b
    vector<T> dat;
    vector<E> lazy;
    int n;
    void eval(int k, int len) {
        if (lazy[k] == identity_e)return;
        if (k < n - 1) {
            lazy[2 * k + 1] = f_ee(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = f_ee(lazy[2 * k + 2], lazy[k]);
        }
        dat[k] = f_te(dat[k], f_ep(lazy[k], len));
        lazy[k] = identity_e;
    }
    void update(int a, int b, E x, int k, int l, int r) {
        eval(k, r - l);
        if (a <= l && r <= b) {
            lazy[k] = f_ee(lazy[k], x);
            eval(k, r - l);
        }
        else if (a < r && l < b) {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = f_tt(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    T query(int a, int b, int k,int l,int r) {
        eval(k,r-l);
        if (r <= a || b <= l)return identity_t;
        else if (a <= l && r <= b)return dat[k];
        else {
            T vl = query(a, b, 2*k + 1, l, (l + r) / 2);
            T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
            return f_tt(vl, vr);
        }
    }
public:
    LazySegmentTree(vector<T> v, T id_t, E id_e, F f, G g, H h, P p) :
        identity_t(id_t), identity_e(id_e), f_tt(f), f_te(g), f_ee(h), f_ep(p) {
        n = 1;
        while (n < v.size())n *= 2;
        dat.resize(2 * n - 1, identity_t);
        lazy.resize(2 * n - 1, identity_e);
        REP(i, v.size())dat[n + i - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)dat[i] = f_tt(dat[i * 2 + 1], dat[i * 2 + 2]);

    }
    void update(int a, int b, E x) { update(a, b, x, 0, 0, n); }
    T query(int a, int b) { return query(a, b, 0, 0, n); }
};

void solve(){
    ll n,m;
    cin>>n>>m;

    vec<tuple<ll,ll,ll>> rla(m);
    REP(i,m){
        ll l,r,a;
        cin>>l>>r>>a;
        rla[i]=make_tuple(r,l,a);
    }
    sort(all(rla));

    ll id_t = 0, id_e = 0;
    auto f = [](ll a, ll b) {return max(a, b); };
    auto g = [](ll a, ll b) {return a + b; };
    auto h = [](ll a, ll b) {return a + b; };
    auto p = [](ll a, ll b) {return a; };
    LazySegmentTree<ll, ll,decltype(f),decltype(g),decltype(h),decltype(p)> seg(Array(n + 1, 0), id_t, id_e, f, g, h, p);

    int pos=0;

    rep(i,1,n+1){
        ll ma=seg.query(0,i);
        seg.update(i,i+1,ma);
        while(pos<m){
            ll r,l,a;
            tie(r,l,a)=rla[pos];
            if(r!=i) break;
            seg.update(l,r+1,a);
            pos++;
        }
    }
    cout<<seg.query(0,n+1)<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    //ll t;cin>>t;REP(i,t) solve();

    return 0;
}
