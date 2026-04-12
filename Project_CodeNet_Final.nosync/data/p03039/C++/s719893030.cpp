#include <chrono>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <time.h>
#include <random>
#include <string>
#include <cassert>
#include <vector>
#include <ostream>
#include <istream>
#include <stack>
#include <deque>
#include <queue>
#include <functional>

using namespace std;

#define int long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define ld long double

ostream& operator << (ostream &a, const vector<int> &b) {
    for (auto k : b) cout << k << " ";
    return a;
}

#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << (x) << "\n";
    const int INF = 1e18;
//    const int mod = 2600000069;
//    const int p = 10;
//    const ld PI = 3.1415926535;
#else
    #define dbg(x)
    const int INF = 1e18;
//    const int mod = 2600000069;
//    const int p = 179;
//    const ld PI = 3.1415926535;
#endif

//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,sse3,sse4")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC target("avx2")
//#pragma GCC optimize("section-anchors")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("vpt")
//#pragma GCC optimize("rename-registers")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("function-sections")
//#pragma GCC optimize("data-sections")

const int MAXN = 2e5 + 1;
const int mod = 1e9 + 7;

int f[MAXN];

int powmod(int a, int p) {
    if (p == 0) return 1;
    if (p == 1) return a;
    int k = powmod(a, p / 2);
    if (p & 1) return (((k * k) % mod) * a) % mod;
    return (k * k) % mod;
}

int inv(int k) {
    return powmod(k, mod - 2);
}

int C(int n, int k) {
    int ans = f[n];
    ans *= inv(f[n - k]);
    ans %= mod;
    ans *= inv(f[k]);
    ans %= mod;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    #else
//        freopen("capitals.in", "r", stdin);
//        freopen("capitals.out", "w", stdout);
    #endif
    f[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += ((j * (j + 1) / 2 + (m - j) * (m - j - 1) / 2) * n) % mod;
            ans %= mod;
            ans += ((i * (i + 1) / 2 + (n - i) * (n - i - 1) / 2) * m) % mod;
            ans %= mod;
        }
    }
    ans *= C(n * m - 2, k - 2);
    ans %= mod;
    ans *= inv(2);
    ans %= mod;
    cout << ans;
}
/*

*/
