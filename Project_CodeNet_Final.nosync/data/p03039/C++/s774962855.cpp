#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef vector<vector<int>> v2int;
typedef vector<ll> vll;
typedef vector<vector<ll>> v2ll;
typedef list<int> liint;
typedef pair<int, int> pint;
const int INF = int(2e9);
const ll LINF = ll(2e9) * ll(2e9);
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b) { a > b ? : a = b; }
template<class T, class C> void chmin(T& a, C b) { a < b ? : a = b; }

ll exp_mod(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll fact_mod(ll n, ll m) {
    ll res = 1;
    for (ll i = n; i>0; --i)
        res = (res * i) % m;
    return res;
}

ll comb_mod(ll n, ll r, ll p) {
    ll res = 1;
    for (int i = 0; i<r; ++i)
        res = (res * (n - i)) % p;
    return (res * exp_mod(fact_mod(r, p), p - 2, p)) % p;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    ll ans1 = 0;
    ll p = 1000000007;
    REP(i, 1, M + 1) {
        ans1 += ll(i) * ll(M - i);
        ans1 %= p;
    }
    ans1 *= N;
    ans1 %= p;
    ans1 *= N;
    ans1 %= p;

    ll ans2 = 0;
    REP(i, 1, N + 1) {
        ans2 += ll(i) * ll(N - i);
        ans2 %= p;
    }
    ans2 *= M;
    ans2 %= p;
    ans2 *= M;
    ans2 %= p;
    ll ans = (ans1 + ans2) % p;
    cout << (comb_mod(N * M - 2, K - 2, p) * ans) % p << endl;
    return 0;
}