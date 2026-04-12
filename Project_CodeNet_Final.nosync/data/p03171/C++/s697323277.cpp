#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3000 + 5;
int arr[N];
ll dp[2][N][N];
int n;

ll solve(int l, int r, int turn) {
    if (l > r)
        return 0;
    if (dp[turn][l][r] != -1)
        return dp[turn][l][r];
    ll res = 0;
    if (turn == 0)
        res = max(solve(l + 1, r, 1) + arr[l], solve(l, r - 1, 1) + arr[r]);
    else
        res = min(solve(l + 1, r, 0) - arr[l], solve(l, r - 1, 0) - arr[r]);
    return dp[turn][l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, n - 1, 0);
    return 0;
}
