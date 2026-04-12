#include <bits/stdc++.h>
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
const int INF = 0x3f3f3f3f;
using namespace std;
const double PI = acos(-1);
const int N = 1e5+1;

int n;
ll arr[3001];
ll dp[3001][3001], sm;

ll solve(int i = 0, int j = n-1) {
    if (i > j) {
        return 0;
    }
    ll& ret = dp[i][j];
    if (~ret) {
        return ret;
    }
    return ret = max(arr[i] + min(solve(i+1, j-1), solve(i+2, j)), arr[j] + min(solve(i+1, j-1), solve(i, j-2)));
}
int main() {
    //freopen("lazy.in", "r", stdin);
    IOS
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sm += arr[i];
    }
    memset(dp, -1, sizeof dp);
    ll ans = solve();
    cout << ans-(sm-ans) << endl;
    return 0;


}
