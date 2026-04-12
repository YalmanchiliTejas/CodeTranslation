#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

const lint INF = 1000000000000000000;
vector<lint> a;
vector<vector<lint>> dp;

lint rec(int l, int r) {
    if (dp[l][r] != INF) return dp[l][r];
    if (l == r) return 0;
    if ((a.size() - (r - l)) & 1) {
        return dp[l][r] = min(rec(l + 1, r) - a[l], rec(l, r - 1) - a[r - 1]);
    } else {
        return dp[l][r] = max(rec(l + 1, r) + a[l], rec(l, r - 1) + a[r - 1]);
    }
}

int main() {
    int N;
    cin >> N;
    a = vector<lint>(N);
    rep(i, N) cin >> a[i];
    dp = vector<vector<lint>>(N + 1, vector<lint>(N + 1, INF));
    cout << rec(0, N) << "\n";
    return 0;
}
