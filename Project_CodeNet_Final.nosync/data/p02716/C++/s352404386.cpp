#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;
    ll a[N];
    for(int i = 0; i < N; i++) cin >> a[i];

    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(2, vector<ll>(2, -INF)));

    ll ans = 0;

    if(N % 2 == 0) {
        dp[0][0][0] = 0;
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                dp[i + 1][0][0] = max(dp[i][0][0], dp[i][0][1]);
                dp[i + 1][0][1] = -INF;
                dp[i + 1][1][0] = -INF;
                dp[i + 1][1][1] = dp[i][0][0] + a[i];
            }
            else {
                dp[i + 1][0][0] = max(dp[i][1][0], dp[i][1][1]);
                dp[i + 1][0][1] = dp[i][0][0] + a[i];
                dp[i + 1][1][0] = -INF;
                dp[i + 1][1][1] = -INF;
            }
        }

        ans = max(dp[N][0][0], dp[N][0][1]);
    }

    else {
        dp[0][1][0] = 0;
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                dp[i + 1][0][0] = max(dp[i][1][0], dp[i][1][1]);
                dp[i + 1][0][1] = dp[i][0][0] + a[i];
                dp[i + 1][1][0] = -INF;
                dp[i + 1][1][1] = dp[i][1][0] + a[i];
            }
            else {
                dp[i + 1][0][0] = max(dp[i][0][0], dp[i][0][1]);
                dp[i + 1][0][1] = -INF;
                dp[i + 1][1][0] = max(dp[i][1][0], dp[i][1][1]);
                dp[i + 1][1][1] = dp[i][0][0] + a[i];
            }
        }

        ans = max(dp[N][0][0], dp[N][0][1]);
    }

    /*
    for(int i = 0; i <= N; i++) {
        cout << setw(15) << dp[i][0][0] << " " << dp[i][0][1] << " " << dp[i][1][0] << " " << dp[i][1][1] << endl;
    }
    */

    cout << ans << endl;
    return 0;
}