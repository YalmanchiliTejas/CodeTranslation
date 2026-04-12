#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:512000000")
#include<utility>
#include<iostream>
#include<fstream>
#include<vector>
#include<array>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<functional>
#include<random>
#include<climits>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
#include<ccomplex>
#include<chrono>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#define int128 __int128
#else
#define int128 long long
#endif

#define all(x) x.begin(), x.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define mp make_pair
#define X first
#define Y second

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(nullptr));

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll mod = 1e9 + 7;

namespace {
    ll mul(ll a, ll b) {
        ll val = a * b - (ll)((ld)a * b / mod) * mod;
        if (val < 0) val += mod;
        if (val >= mod) val -= mod;
        return val;
    }
    ll poww(ll a, ll b) {
        ll val = 1;
        a %= mod;
        while (b > 0) {
            if (b % 2) val = mul(a, val);
            a = mul(a, a);
            b >>= 1;
        }
        return val % mod;
    }
    ll inv(ll a) {
        return poww(a, mod - 2);
    }
    ll gcd(ll a, ll b) {
        return (a == 0 ? b : gcd(b % a, a));
    }
    ll gcdex(ll a, ll b, ll& x, ll& y) {
        if (a == 0) {
            x = 0; y = 1;
            return b;
        }
        ll x1, y1;
        ll d = gcdex(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }

    ll inv_eu(ll a, ll m) {
        ll x, y;
        ll g = gcdex(a, m, x, y);
        if (g != 1)
            assert(0);
        else {
            x = (x % m + m) % m;
            return x;
        }
    }
}

ll const maxn = 1e6 + 6;

unordered_map<ll, ll> cnt1, cnt;

vector<pair<vector<int>, int>> rofl[50];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, m; cin >> n >> x >> m;
    ll ans = 0;
    vector<ll> kek; kek.push_back(x);
    vector<ll> pos(m + 1, - 1);
    pos[x] = 0;
    ll l = 0;
    for (ll i = 1; i < m; i++) {
        ll xx = kek.back() * kek.back();
        xx %= m;
        if (pos[xx] != -1) {
            l = pos[xx];
            break;
        }
        else {
            pos[xx] = kek.size();
            kek.push_back(xx);
        }
    }

    if (n <= kek.size()) {
        for (ll i = 0; i < n; i++) {
            ans += kek[i];
        }
        cout << ans << endl;
        return 0;
    }

    for (ll i = 0; i < l; i++) ans += kek[i];
    n -= l;
    ll sm = 0;
    for (ll i = l; i < kek.size(); i++) {
        sm += kek[i];
    }
    ans += (n / ((ll)kek.size() - l)) * sm;
    ll ost = n % ((ll)kek.size() - l);
    for (ll i = l; i < l + ost; i++) {
        ans += kek[i];
    }
    cout << ans << endl;

    return 0;
}

/*

*/
