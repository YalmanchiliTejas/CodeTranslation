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

const int MAXN = 101;

int dp[2][MAXN][4];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string n;
    int k;
    cin >> n >> k;
    int sz = n.size();
    dp[0][0][1] = n[0] - '1';
    dp[0][0][0] = 1;
//    dp[0][1][1] = 9;
    int cnt = 1;
    dp[1][0][1] = 1;
    for (int i = 1; i < sz; i++) {
        if (n[i] != '0') cnt++;
        if (cnt > 3) break;
        dp[1][i][cnt] = 1;
    }
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j <= k; j++) {
            dp[0][i][j] = (n[i] != '0' ? dp[1][i - 1][j] : 0) + dp[0][i - 1][j];
            if (j != 0) {
                dp[0][i][j] += 9 * dp[0][i - 1][j - 1] + max(n[i] - '1', 0) * dp[1][i - 1][j - 1];
            }
        }
    }
//    for (int i = 0; i < sz; i++) {
//        for (int j = 0; j <= k; j++) {
//            cout << i << " " << j << " " << dp[0][i][j] << "\n";
//        }
//    }
    cout << dp[0][sz - 1][k] + dp[1][sz - 1][k];
}
/*

*/
