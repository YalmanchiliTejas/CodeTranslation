#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;

#define assert_range(x,a,b) assert((a) <= (x) and (x) <= (b))
using ll = long long;
const int INF = 1e9;

const int N = 3000;
ll dp[N+1][N+1][2];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }
    for (int d = 2; d <= n; ++d) {
        for (int i = 0; i+d-1 < n; ++i) {
            int j = i+d-1;
            dp[i][j][0] = max(dp[i+1][j][1] + a[i], dp[i][j-1][1] + a[j]);
            dp[i][j][1] = min(dp[i+1][j][0] - a[i], dp[i][j-1][0] - a[j]);
        }
    }
    cout << dp[0][n-1][0] << endl;
    return 0;
}
