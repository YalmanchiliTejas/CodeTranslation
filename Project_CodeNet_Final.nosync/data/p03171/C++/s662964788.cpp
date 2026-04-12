    #include <bits/stdc++.h>
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
const int INF = 0x3f3f3f3f;
using namespace std;

int n;
ll arr[3001], dp[3001][3001][2];

ll solve(int i = 0, int j = n-1, int t = 0) {
    if (i == n | j < 0 || i > j) {
        return 0;
    }
    ll& ret = dp[i][j][t];
    if (~ret) {
        return ret;
    }
    if (!t) {
        return ret = max(arr[i] + solve(i+1, j, 1), arr[j] + solve(i, j-1, 1));
    }
    return ret = min(solve(i+1, j, 0)-arr[i], solve(i, j-1, 0)-arr[j]);
}
int main()
{
    IOS
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve() << endl;


    return 0;
}
