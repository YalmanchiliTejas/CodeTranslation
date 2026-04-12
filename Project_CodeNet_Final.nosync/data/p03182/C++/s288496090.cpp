/* ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄▄            ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄         ▄       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌          ▐░▌          ▐░█▀▀▀▀▀▀▀█░▌▐░▌       ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌
▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌   ▄   ▐░▌     ▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌       ▐░▌
▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌     ▐░▌▐░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌ ▐░▌░▌ ▐░▌     ▐░▌ ▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░▌          ▐░▌       ▐░▌▐░▌          ▐░▌          ▐░▌       ▐░▌▐░▌▐░▌ ▐░▌▐░▌     ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
▐░▌          ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌░▌   ▐░▐░▌     ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌     ▐░░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
 ▀            ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀       ▀▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  */
 
//#pragma optimization_level 3
 
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <chrono>
#include <ctime>
#include <queue>
#include <math.h>
#include <deque>
#include <stack>
#include <iomanip>
#include <assert.h>
#include <stdio.h>
#include <cstring>
#include <random>
#include <limits.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pld pair<ld, ld>
#define vi vector <int>
#define vpi vector <pii>
#define vld vector <ld>
#define try tr
#define left left11
#define right right11
#define lb lower_bound
#define ub upper_bound
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define pf push_front
#define sqr(a) ((a) * (a))
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
#define x first
#define y second
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
clock_t START;
 
inline ld TIME() {
    return (ld) (clock() - START) / CLOCKS_PER_SEC;
}

void SHOW() {
    cout << TIME() << " SECONDS FROM START\n";
}
 
ld TL = 2.0; 
int calls = 0;
 
inline bool IS() {
    if(++calls == 1000) {
        calls = 0;
        if(TL - TIME() < 0.1)
            return true;
    }
    return false;
}
 
template<typename T1, typename T2>
inline void amin(T1 &a, T2 b) { if (a > b) a = b; }
 
template<typename T1, typename T2>
inline void amax(T1 &a, T2 b) { if (a < b) a = b; }
 
template<typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
    os << p.first << ' ' << p.second << endl;
    return os;
}
 
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
 
template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (auto &u : v) is >> u;
    return is;
}
 
template<typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
    for (auto &u : v) os << u << ' ';
    os << endl;
    return os;
}
 
int hash_mod[4] = {1000000007, 998244353, 1000000009, 999999937}, mod = hash_mod[rnd() % 4];
int hash_pows[4] = {179, 239, 1007, 2003}, P = hash_pows[rnd() % 4];
 
int binpow(int x, int p) {
    int res = 1;
    while(p) {
        if(p % 2)
            res = (res * x) % mod;
        x = (x * x) % mod;
        p /= 2;
    }
    return res;
}
 
int sum(int x, int y) {
    x += y;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
 
int mult(int x, int y) {
    return (x * y) % mod;
}
 
const int N = 1e6 + 7, NS = 3e3 + 7, lg = 20, sq = 550, inf = 1e18 + 7, SM = 1e2 + 7;
const ld eps = 1e-9;
vpi p[N];
struct tree{
    int n;
    vi t, add;
    void init(int _n) {
        int n = _n;
        t.resize(4 * n);
        add.resize(4 * n);
    }
    void push(int v, int l, int r) {
        t[v] += add[v];
        if(l != r - 1) {
            add[2 * v] += add[v];
            add[2 * v + 1] += add[v];
        }
        add[v] = 0;
    }
    void update(int v, int l, int r, int vl, int vr, int val) {
        push(v, l, r);
        if(l >= vr || vl >= r)
            return;
        if(l >= vl && r <= vr) {
            add[v] += val;
            push(v, l, r);
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, vl, vr, val);
        update(2 * v + 1, m, r, vl, vr, val);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
    int get(int v, int l, int r, int vl, int vr) {
        push(v, l, r);
        if(vl >= vr || l >= vr || vl >= r)
            return -inf;
        if(l >= vl && r <= vr)
            return t[v];
        int m = (l + r) / 2;
        return max(get(2 * v, l, m, vl, vr), get(2 * v + 1, m, r, vl, vr));
    }
} T;
void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        p[l].pb({l, a});
        p[r + 1].pb({l, -a});
    }
    T.init(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto u : p[i])  {
            T.update(1, 0, n + 1, 0, u.x, u.y);
        }
        int d = T.get(1, 0, n + 1, 0, i);
        amax(ans, d);
        T.update(1, 0, n + 1, i, i + 1, d);
    }
    cout << ans;
//    cout << T.get(1, 0, n + 1, 0, n + 1);
}
 
signed main() {
    fast
    solve();
}