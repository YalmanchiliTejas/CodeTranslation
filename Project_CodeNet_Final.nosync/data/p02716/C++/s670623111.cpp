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

constexpr int MAX_N = 200000;
int64 dp[MAX_N + 1][3];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int64> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    constexpr int64 INF = (1LL << 60);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = -INF;
        }
    }

    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (j + 1 < 3) {
                dp[i + 1][j + 1] = std::max(dp[i + 1][j + 1], dp[i][j]);
            }
            int ni = std::min(N, i + 2);
            dp[ni][j] = std::max(dp[ni][j], dp[i][j] + A[i]);
        }
    }

    int64 ans;
    if (N % 2) {
        ans = std::max(dp[N][1], dp[N][2]);
    } else {
        ans = std::max(dp[N][0], dp[N][1]);
    }
    cout << ans << endl;

    return 0;
}

