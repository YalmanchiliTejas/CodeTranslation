#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long x;
    cin >> x;

    vector<long long> dp(n + 2, 0);
    dp[0] = 1;
    vector<long long> dp2(n + 2, 0);
    dp2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        // assert(dp[i] < LLONG_MAX);
        dp[i] = dp[i - 1] * 2 + 3;
        dp2[i] = dp2[i - 1] * 2 + 1;
        // cout << i << " " << dp2[i] << endl;
    }
    // cout << dp[n] << endl;

    long long res = 0;

    for (int i = n; i > 1 && x > 0; --i) {
        if (dp[i - 1] + 1 + 1 <= x) {
            res += dp2[i - 1] + 1;
            x = max(0LL, x - dp[i - 1] - 1 - 1);
        } else {
            --x;
        }
    }
    if (x > 0) {
        --x;
        res += min(3LL, x);
    }

    cout << res << '\n';

    return 0;
}