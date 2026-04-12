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
    cout << fixed << setprecision(12);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int N = 1 << n;

    vector<vector<long long>> dp(N, vector<long long>(n, 0));
    dp[1][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }

            for (auto nj : graph[j]) {
                if ((i >> nj) & 1) {
                    continue;
                }
                int ni = i | (1 << nj);
                dp[ni][nj] += dp[i][j];
            }
        }
    }

    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += dp[N - 1][i];
    }

    cout << res << '\n';

    return 0;
}