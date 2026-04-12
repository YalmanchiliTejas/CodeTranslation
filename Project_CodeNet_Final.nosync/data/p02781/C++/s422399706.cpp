
#include <iostream>
#include <iomanip> //! for setprecision(10)
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

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MOD = 1000000007;

int dp[100][2][4]; //! [digit from left 0based][1: less than N for sure][non-0 count]

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    string N;
    int K;
    cin >> N >> K;

    dp[0][0][0] = 1;
    rep(i, N.length()) {
        int nd = N[i]-'0';
        rep(j, 2) rep(k, 4) rep(d, 10) {
            if (K < k) continue;
            if (!j && nd < d) continue;
            int nextJ = ((j || d < nd) ? 1 : 0);
            //! smaller than N guaranteed
            if (k < K) {
                //! any number is allowed
                if (d) {
                    dp[i+1][nextJ][k+1] += dp[i][j][k];
                } else {
                    dp[i+1][nextJ][k] += dp[i][j][k];
                }
            } else {
                //! only 0 is allowed
                if (d == 0) {
                    dp[i+1][nextJ][k] += dp[i][j][k];
                }
            }
        }
    }

    LL ans = 0;
    rep(j, 2) {
        ans += dp[N.length()][j][K];
    }

    cout << ans << endl;

    return 0;
}
