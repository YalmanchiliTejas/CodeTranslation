#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
LL solve(int L, int R, auto &dp, auto &arr, auto &preS) {
    if (~dp[L][R]) return dp[L][R];
    if (L == R) return dp[L][R] = 0;
    return dp[L][R] = max(
        preS[R] - preS[L + 1] - solve(L + 1, R, dp, arr, preS) + arr[L],
        preS[R - 1] - preS[L] - solve(L, R - 1, dp, arr, preS) + arr[R - 1]
    );
}
void marmot0814() {
    int n; cin >> n;
    vector<LL> arr(n);
    vector<LL> preS{0};
    for (auto &v : arr)
        cin >> v, preS.push_back(preS.back() + v);
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, -1));
    cout << solve(0, n, dp, arr, preS) - (preS.back() - solve(0, n, dp, arr, preS)) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}