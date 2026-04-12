#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <deque>
#include <forward_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll MOD = 1E+09 + 7;
const ll INF = 1E18;
const int MAX_N = 3000;

int N;

ll A[MAX_N + 1], dp[MAX_N + 2][MAX_N + 2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    for (int i = N; i >= 1; i--) {
        for (int j = i; j <= N; j++) {
            if (i < j) {
                if ((N + i - j - 1) & 1) {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
                } else {
                    dp[i][j] = max(dp[i + 1][j] + A[i], dp[i][j - 1] + A[j]);
                }
            } else if (!((N + i - j - 1) & 1)) {
                dp[i][j] = A[i];
            }
        }
    }

    cout << 2 * dp[1][N] - sum << "\n";

    return 0;
}