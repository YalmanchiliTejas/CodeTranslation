#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> a;
vector<vector<ll>> dp;
vector<vector<bool>> vis;

ll f(int l, int r) {
	if (vis[l][r]) return dp[l][r];
    vis[l][r] = true;
    if (l == r) {
        return dp[l][r] = a[l];
    } else {
        return dp[l][r] = max(a[l] - f(l + 1, r), a[r] - f(l, r - 1));
    }
}

int main() {
    int n; cin >> n; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp.assign(n, vector<ll>(n, 0));
    vis.assign(n, vector<bool>(n, false));
    cout << f(0, n - 1) << endl;
    return 0;
}