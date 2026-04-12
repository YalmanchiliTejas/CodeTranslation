#include "bits/stdc++.h"
 
#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[a]; if (a != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9
 
const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
 
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
///(??´????????`)(??´????????`)(??´????????`)(??´????????`)(??´????????`)(??´????????`)///
ll mypow(ll a, ll n) {
    if (n == 0)return 1;
    if (n % 2 == 0)return mypow(a, n / 2)*mypow(a, n / 2) % MOD;
    return (a*mypow(a, n / 2) % MOD)*mypow(a, n / 2) % MOD;
}
struct UnionFind {
    vector<int> par;
    vector<int> ran;
 
    UnionFind(int n) {
        par.resize(n);
        ran.resize(n);
        REP(i, n) {
            par[i] = i;
            ran[i] = 0;
        }
    }
 
    int root(int a) {
        return par[a] == a ? a : par[a] = root(par[a]);
    }
 
    bool same(int x, int y) {
        return root(x) == root(y);
    }
 
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)return;
        if (ran[x] < ran[y]) {
            par[x] = y;
        }
        else {
            par[y] = x;
            if (ran[x] == ran[y]) ran[x]++;
        }
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n)break;
        UnionFind u(n);
     
        REP(i, m) {
            int a, b;
            cin >> a >> b;
            a--; b--;
 
            u.unite(a, b);
        }
        vi cnt(n, 0);
        REP(i, n) {
            cnt[u.root(i)]++;
        }
        int c = 0;
        REP(i, n) {
            if (cnt[i] > 0)c++;
        }
        ll res = mypow(2, c);
        if (m != 0)res++;
        cout << res%MOD << endl;
    }
    return 0;
}