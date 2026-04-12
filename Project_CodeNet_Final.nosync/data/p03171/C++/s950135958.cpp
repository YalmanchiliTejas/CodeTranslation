#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(n+1, vector<long long>(2, 0)));
    for (int i = 0; i <= n; i++) {
        dp[i][i][0] = dp[i][i][1] = 0;
    }
    for (int j = 0; j <= n; j++) {
        for (int i = j - 1; i >= 0;i--) {
            dp[i][j][0] = max(dp[i + 1][j][1] + a[i], dp[i][j - 1][1] + a[j - 1]);
            dp[i][j][1] = min(dp[i + 1][j][0] - a[i], dp[i][j - 1][0] - a[j - 1]);
        }
    }
    cout << dp[0][n][0] << endl;
    return 0;
}