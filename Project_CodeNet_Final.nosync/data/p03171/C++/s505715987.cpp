#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <bitset>
#include <cmath>
#include <iomanip>

using namespace std;

using int64 = long long;

/////////////////////
// Code starts here//
/////////////////////


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int64> A(N);
    vector<int64> pref(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pref[i] = (!i ? A[i] : pref[i-1] + A[i]);
    }

    vector<vector<int64>> dp(N, vector<int64>(N));

    auto Sum = [&] (int l, int r) {
        return pref[r] - (l - 1 >= 0 ? pref[l-1] : 0);
    };

    for (int i = 0; i < N; i++)
        dp[i][i] = A[i];

    for (int l = 2; l <= N; l++) {
        for (int i = 0; i + l - 1 < N; i++) {
            int j = i + l - 1;

            dp[i][j] = max(A[i] + Sum(i+1, j) - dp[i+1][j], A[j] + Sum(i, j-1) - dp[i][j-1]);
        }
    }

    cout << 2 * dp[0][N-1] - Sum(0, N - 1) << "\n";

    return 0;
}
