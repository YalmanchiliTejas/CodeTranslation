#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
using ll = long long; using ld = long double;
using pii = pair<int,int>; using pil = pair<int,ll>;
using pli = pair<ll,int>; using pll = pair<ll,ll>;
const int MOD = 1000000007, MOD2 = 998244353;
const int INF = 0x3f3f3f3f, INF2 = 0x3f3f3f37;
const ll LINF = 0x3f3f3f3f3f3f3f3f, LINF2 = 0x3f3f3f3f3f3f3f3d;

int dp[102][2][4];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string n; int k;
    cin >> n >> k;
    vector<int> a(n.size());
    for (int i = 0; i < n.size(); ++i) a[i] = n[i] - '0';
    memset(dp, -1, sizeof dp);
    function<int(int, int, int)> solve = [&](int idx, int lim, int cnt) {
        if (cnt > k) return 0;
        if (idx >= n.size()) return int(cnt == k);
        if (dp[idx][lim][cnt] != -1) return dp[idx][lim][cnt];
        int res = 0;
        for (int i = 0; i <= (lim ? a[idx] : 9); ++i)
            res += solve(idx + 1, lim ? i == a[idx] : 0, cnt + !!i);
        return dp[idx][lim][cnt] = res;
    };
    cout << solve(0, 1, 0) << '\n';
}