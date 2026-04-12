#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 3010;
int N, a[maxn];
ll dp[maxn][maxn][2];
bool vis[maxn][maxn][2];

ll rec(int l, int r, int t) {
    if (l > r) {
        return 0;
    }
    ll& ret = dp[l][r][t];
    if (vis[l][r][t]) {
        return ret;
    }
    vis[l][r][t] = true;
    if (t == 0) {
        ret = max(a[l] + rec(l + 1, r, 1), a[r] + rec(l, r - 1, 1));
    } else {
        ret = min(-a[l] + rec(l + 1, r, 0), -a[r] + rec(l, r - 1, 0));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll answer = rec(0, N - 1, 0);
    cout << answer;

    return 0;
}