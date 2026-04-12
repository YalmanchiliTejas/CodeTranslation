#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

llong n;
llong a[3005];
llong dp[3005][3005];
const llong INF = 1ll << 60ll;

llong dfs(int f, int s, int t) {
    if (s == t) return 0;

    if (dp[s][t] != INF) return dp[s][t];

    if (f) {
        return dp[s][t] = max(dfs(f ^ 1, s + 1, t) + a[s],
                              dfs(f ^ 1, s, t - 1) + a[t - 1]);
    }
    else {
        return dp[s][t] = min(dfs(f ^ 1, s + 1, t) - a[s],
                              dfs(f ^ 1, s, t - 1) - a[t - 1]);
    }
}

int main() {
    for (int i = 0; i < 3005; i++) {
        for (int j = 0; j < 3005; j++) {
            dp[i][j] = INF;
        }
    }
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << dfs(1, 0, n) << endl;

    return 0;
}
