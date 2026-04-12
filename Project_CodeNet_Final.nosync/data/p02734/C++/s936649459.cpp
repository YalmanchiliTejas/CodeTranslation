#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <assert.h>
#include <utility>
#include <tuple>
#include <array>
#include <bitset>
#include <cstdlib>

using int64 = long long;

using namespace std;

constexpr int MAX_N = 3000,
              MAX_S = 3000;
int64 dp[MAX_N + 1][MAX_S + 1];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    constexpr int64 MOD = 998244353;

    int64 ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j != S) {
                (dp[i][j] += dp[i - 1][j]) %= MOD;
            }
            if (j - A[i - 1] >= 0) {
                (dp[i][j] += dp[i - 1][j - A[i - 1]]) %= MOD;
            }
            if (j == S) {
                (ans += dp[i][j] * (N + 1 - i)) %= MOD;
            }
        }
    }

    /*
    for (int j = S; j >= 0; j--) {
        for (int i = 0; i <= N; i++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */

    cout << ans << endl;

    return 0;
}

