#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

const int maxn = 3003;
ll dp[maxn][maxn];
bool done[maxn][maxn];

//状態としては 1: どちらの手番か？ 2: 残りの数列
ll dfs(int l, int r, vector<ll> &a) {
    if (l > r) return 0;
    if (done[l][r]) return dp[l][r];
    if ((a.size() - (r - l)) % 2 == 1) { // 先攻
        dp[l][r] = max(dfs(l+1, r, a) + a[l], dfs(l, r-1, a) + a[r]);
    } else { // 後攻
        dp[l][r] = min(dfs(l+1, r, a) - a[l], dfs(l, r-1, a) - a[r]);
    }
    done[l][r] = true;
    return dp[l][r];
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    rep(i, maxn) {
        rep(j, maxn) done[i][j] = false;
    }
    ll ans = dfs(0, a.size()-1, a);
    cout << ans << endl;
}