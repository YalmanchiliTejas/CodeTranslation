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

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
    #else
//        freopen("capitals.in", "r", stdin);
//        freopen("capitals.out", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    multiset<int, greater<int>> kek;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = kek.upper_bound(a[i]);
        if (it != kek.end()) {
            kek.erase(it);
        } else ans++;
        kek.insert(a[i]);
    }
    cout << ans;
}
/*

*/
