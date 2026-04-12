
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }


const int MOD = 1000000007;


int dp[10005][100][2];  // [i-th digit where left-most is index 1][SUM % D up to i-th digit][1: num < K fullfilled, 0: otherwise] => count so far


int main()
{
    string K;
    int D;
    cin >> K >> D;

    dp[0][0][0] = 1;

    int len = K.length();
    for (int i = 1; i <= len; ++i) {
        int cd = (int) (K[i-1] - '0');
        rep(small, 2) rep(d, 10) {
            int nextSmall = small;
            if (!small && cd < d) continue;
            if (!small && d < cd) nextSmall = 1;
            // cout << "i = " << i << ", d = " << d << ", small = " << small << endl;
            rep(m, D) {
                if (dp[i-1][m][small] == 0) continue;
                int nextM = (m + d) % D;
                dp[i][nextM][nextSmall] = (dp[i][nextM][nextSmall] + dp[i-1][m][small]) % MOD;
                // cout << "dp[" << i << "][" << nextM << "][" << nextSmall << "] = " << dp[i][nextM][nextSmall] << endl;
            }
        }
    }

    // exclude 0
    int ans = (dp[len][0][0] + dp[len][0][1] - 1 + MOD) % MOD; 

    cout << ans << endl;

    return 0;
}