#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;
using p32 = pair<i32, i32>;

i32 n;
vector<i32> a;
map<p32, i64> dp;

i64 dfs(i32 index, i32 use) {
    if (use == n / 2) return 0;
    if (index / 2 < use) return -INT64_MAX / 2;
    if ((n - index + 1) / 2 < n / 2 - use) return -INT64_MAX / 2;
    if (dp.find({index, use}) != dp.end()) return dp[{index, use}];
    return dp[{index, use}] = max(a[index] + dfs(index + 2, use + 1), dfs(index + 1, use));
}

int main() {
    cin >> n;
    a.assign(n, 0);
    for (auto& e : a) cin >> e;
    cout << dfs(0, 0) << endl;
}
