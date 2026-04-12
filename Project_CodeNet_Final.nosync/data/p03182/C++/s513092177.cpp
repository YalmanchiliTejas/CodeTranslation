#include <bits/stdc++.h>
#include <tuple>
using namespace std;

#ifdef LOCAL 
string to_string(char a) { return string(1,a); }
string to_string(bool a) { return a ? "1" : "0"; }
string to_string(const char* a) { return (string)a; }
string to_string(string a) { return a; }
string to_string(vector<bool> v) {
	string s = "["; for(unsigned i=0;i<v.size();i++){ s += ((i>0)?" ":"");
    s += char('0'+v[i]); } 	s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) {
	bool b = 1; string s = "["; for (const auto& x: v) {
		if (!b) {s += ", ";} b = 0; s += to_string(x); } s += "]"; return s; }
template<class A, class B> string to_string(pair<A,B> p) {
	return "("+to_string(p.first)+", "+to_string(p.second)+")"; }
void dbgf() { cerr << endl; }
template<class H, class... T> void dbgf(H h, T... t) {
	cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
	dbgf(t...); }
#define dbg(...) cerr << #__VA_ARGS__ << " = ", dbgf(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
#define boolout(x) cout<<(x?"YES":"NO")<<endl;
typedef long long ll;

const int nmax = 2e5+5;

const ll INF = 1e18 +10;
/////////////////////////////////// segment tree
struct S {
    ll smallest, lazy;
    void merge(const S& a, const S& b){
        smallest = min(a.smallest, b.smallest);
    }
    void add(ll a){
        smallest += a;
        lazy += a;
    }
};

const int TYPE_ADD=1, TYPE_MIN=2;
vector<S> tree;
void rec(int id, int low, int high, int q_low, int q_high, int type, ll &x){
    if (high < q_low || low > q_high) {
        return;
    }

    if (q_low <= low && q_high >= high) {
        if (type==TYPE_ADD) {
            tree[id].add(x); 
        } else if (type==TYPE_MIN) {
            x = min(x, tree[id].smallest); 
        } else {
            assert(false);
        }
        return;
    }
    for (int c : {2*id, 2*id+1}) {
       tree[c].add(tree[id].lazy); 
    }
    tree[id].lazy = 0;

    int mid = (low+high)/2;
    rec(2*id, low, mid, q_low, q_high, type, x);
    rec(2*id+1, mid+1, high, q_low, q_high, type, x);

    tree[id].merge(tree[2*id], tree[2*id+1]);
}

/////////////////////////////////// segment tree

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> intervals(nmax);

    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        int l, r, a;
        cin >> l >> r >> a;
        intervals[r].push_back({l, a});
        sum += a;
    }


    int base = 1;
    while (base <= n+1) {
        base *= 2;
    }
    tree.resize(2*base, {INF, 0});
    ll answer = 0;
    ll what = 0 -INF;
    rec(1, 0, base-1, 0, 0, TYPE_ADD, what);
    for (int i = 1; i < n+2; ++i) {
        for (pair<int, int> p : intervals[i-1]) {
           ll some = p.second;
           rec(1, 0, base-1, 0, p.first-1, TYPE_ADD, some); 
        }
        ll best = INF;
        rec(1, 0, base-1, 0, base-1, TYPE_MIN, best);
        if (i==n+1) {
            answer = best;
        }
        ll what = best - INF;
        rec(1, 0, base-1, i, i, TYPE_ADD, what);
    }

    cout << sum - answer << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t; // read t. cin knows that t is an int, so it reads it as such.
    for (int i = 1; i <= t; ++i) {
        solve();
    }
    return 0;
}

