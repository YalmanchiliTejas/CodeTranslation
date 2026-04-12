#include <cmath>
#include <chrono>
#include <random>
#include <ctime>
#include <algorithm>
#include <iosfwd>
#include <iostream>
#include <list>
#include <ostream>
#include <streambuf>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fori(i, n) for(ll i = 0; i < (n); ++i)
#define forI(i, n) for(ll i = 1; i <= (n); ++i)
#define pll pair<ll, ll>
#define ff first
#define ss second

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#define pt pair<ll, ll>
#define x first
#define y second

pll operator+(pll a, pll b) { return {a.x + b.x, a.y + b.y}; }

ll rand0m() {
    return (ull(rand()) << 15ull | ull(rand()));
}                   //[0 ... n)
ll rand0m(ll x) {
    return rand0m() % x;
}               //[0 ... n)
ll rand0m(ll minn, ll maxx) {
    return rand0m(maxx - minn + 1) + minn;
}   //[minn ... maxx]

const ll MAXN = 2e5 + 1;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

ll n, m;

struct SegTree{
    vector<ll> t;
    
    explicit SegTree(ll siz){
        t.resize(siz * 4, 0);
    }
    
    void set(ull v, ull l0, ull r0, ull ind, ll val){
        if(l0 + 1 == r0){
            t[v] = val;
            return;
        }
        ull mid = (l0 + r0) >> 1ull;
        if(ind < mid){
            set(v << 1ull, l0, mid, ind, val);
            if(t[v] < t[v << 1ull]) t[v] = t[v << 1ull];
        }else {
            set(v << 1ull | 1ull, mid, r0, ind, val);
            if(t[v] < t[v << 1ull | 1ull]) t[v] = t[v << 1ull | 1ull];
        }
    }

    ll get(ull v, ull l0, ull r0, ull l, ull r){
        if(r <= l) return 0;
        if(l0 == l && r0 == r){
            return t[v];
        }
        ull mid = (l0 + r0) >> 1ull;
        return max(get(v << 1ull, l0, mid, l, min(mid, r)),
                get(v << 1ull | 1ull, mid, r0, max(l, mid), r));
    }
};

ll dp[10 * 1000 + 1][10][100];

void solve() {
    string s;
    ll d;
    cin >> s >> d;
    fori(i, 10) dp[0][i][i % d] = 1;
    forI(i, 10 * 1000){
        fori(j, 10){
            fori(k, d){
                dp[i][0][k] += dp[i - 1][j][k];
                if(dp[i][0][k] >= mod) dp[i][0][k] -= mod;
            }
        }

        forI(j, 9){
            dp[i][j][0] = dp[i][j - 1][d - 1];
            forI(k, d - 1) dp[i][j][k] = dp[i][j - 1][k - 1];
        }
    }
    ll c = 0;
    ll offset = 0;
    fori(i, s.size()){
        fori(j, s[i] - '0') {
            c += dp[s.size() - i - 1][j][offset];
            if(c >= mod) c -= mod;
        }
        offset = (offset - (s[i] - '0') + 100 * d) % d;
    }
    c += dp[0][s.back() - '0'][(offset + s.back() - '0') % d];
    cout << (c - 1 + mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
}
