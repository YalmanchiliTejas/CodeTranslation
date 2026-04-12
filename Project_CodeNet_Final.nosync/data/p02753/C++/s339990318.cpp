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
#include <chrono>
#include <stack>

using namespace std;

#define int long long
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define ld long double

ostream& operator<< (ostream &a, const vector<int> &b) {
    for (auto k : b) cout << k << " ";
    return a;
}

istream& operator>> (istream& a, pii& b) {
    cin >> b.first >> b.second;
    return a;
}

ostream& operator<< (ostream& a, const pii& b) {
    cout << "{" << b.first << ", " << b.second << "}";
    return a;
}

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}


#ifdef LOCAL
    #define dbg(x) cout << #x << " : " << (x) << "\n";
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 10;
    // const ld PI = 3.1415926535;
#else
    #define dbg(x)
    const int INF = 1e18;
    // const int mod = 2600000069;
    // const int p = 179;
    // const ld PI = 3.1415926535;
#endif

// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,sse3,sse4")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("fast-math")
// #pragma GCC target("avx2")  
// #pragma GCC optimize("section-anchors")
// #pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
// #pragma GCC optimize("vpt")
// #pragma GCC optimize("rename-registers")
// #pragma GCC optimize("move-loop-invariants")
// #pragma GCC optimize("unswitch-loops")
// #pragma GCC optimize("function-sections")
// #pragma GCC optimize("data-sections")

mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    if (s[0] != s[1] || s[1] != s[2] || s[0] != s[2]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
/*

*/  