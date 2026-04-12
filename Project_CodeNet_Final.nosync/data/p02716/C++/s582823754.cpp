
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

map<int, LL> dp[200005][2];  //! dp[i][j][k]  i: index of the last number checked, j: if the number at i was used, k: the count of numbers used so far

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<LL> A(N);
    rep(i, N) cin >> A[i];

    dp[0][0][0] = 0;
    dp[0][1][1] = A[0];
    // cout << "dp[0][0][0] = 0" << endl; 
    // cout << "dp[0][1][1] = " << dp[0][1][1] << endl; 

    for (int i = 1; i < N; ++i) {
        for (int k = i/2; k <= (i+2)/2; ++k) {
            if (dp[i-1][1].find(k) != dp[i-1][1].end()) {
                if (dp[i-1][0].find(k) != dp[i-1][0].end()) {
                    dp[i][0][k] = max(dp[i-1][1][k], dp[i-1][0][k]);
                } else {
                    dp[i][0][k] = dp[i-1][1][k];
                }
            } else {
                if (dp[i-1][0].find(k) != dp[i-1][0].end()) {
                    dp[i][0][k] = dp[i-1][0][k];
                }
            }
            // if (dp[i][0].find(k) != dp[i][0].end()) {
            //     cout << "dp[" << i << "][0][" << k << "] = " << dp[i][0][k] << endl;         
            // }
            if (k) {
                dp[i][1][k] = dp[i-1][0][k-1] + A[i];
                // cout << "dp[" << i << "][1][" << k << "] = " << dp[i][1][k] << endl; 
            }
        }
    }

    cout << max(dp[N-1][0][N/2], dp[N-1][1][N/2]) << endl;

    return 0;
}
