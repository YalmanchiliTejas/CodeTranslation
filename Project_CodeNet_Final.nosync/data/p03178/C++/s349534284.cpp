//#pragma  GCC optimize("Ofast")

//#ifdef  DEBUG
//#define _GLIBCXX_DEBUG
//#endif

// -Ofast
// -O3
// -O2
// -fsanitize=address
// -fsanitize=undefined

// add_compile_options()

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <random>

using namespace std;
//using namesparsace __gnu_pbds;

void solve();

int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    solve();
    return 0;
}

#define ld double
#define int long long

const int maxN = 1e5 + 10, maxK = 1e5 + 10, inf = 1e15 + 10, base = 223, mod = 1e9 + 7;

int d, dp[maxN][110][2];
string s;

void solve() {
    cin >> s >> d;
    dp[0][(s[0] - '0') % d][1] = 1;
    for (int i = 0; i < (s[0] - '0'); i++) {
        dp[0][i % d][0] += 1;
    }
    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < d; j++) {
            for (int l = 0; l < 10; l++) {
                int e = (j - l + d * 10) % d;
                //cout << i << " " << j << " " << l << " " << e << endl;
                if (l < s[i] - '0') {
                    dp[i][j][0] += dp[i - 1][e][0] + dp[i - 1][e][1];
                    dp[i][j][0] %= mod;
                }
                if (l == s[i] - '0') {
                    dp[i][j][1] += dp[i - 1][e][1];
                    dp[i][j][1] %= mod;
                }
                if (l >= s[i] - '0') {
                    dp[i][j][0] += dp[i - 1][e][0];
                    dp[i][j][0] %= mod;
                }
                //cout << dp[i][j][0] << endl;
            }
        }
    }
    cout << (dp[s.size() - 1][0][0] + dp[s.size() - 1][0][1] - 1 + mod) % mod;
}
/*
00
08
13
22
04
17


 */