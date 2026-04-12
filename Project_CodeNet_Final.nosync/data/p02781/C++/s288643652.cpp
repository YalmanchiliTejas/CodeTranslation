#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const int maxn = 200000 + 10;
const ll mod = 1000000000 + 7;


char s[maxn];
int n, k, a[110];
ll dp[200][10];
ll dfs(int pos, bool lead, bool limit, int state) {
    if (pos == -1 && state == 0) return 1;
    if (pos == -1 && state != 0) return 0;
    if (!limit && !lead && dp[pos][state] != -1) return dp[pos][state];
    int up = limit ? a[pos] : 9;
    if (state == 0) up = 0;
    ll ans = 0;
    int st = state;
    for (int i = 0; i <= up; i++) {
        if (i != 0) st = max(0, state - 1);
        ans += dfs(pos - 1, lead && i == 0, limit && i == a[pos], st);
    }
    if (!limit && !lead) dp[pos][state] = ans;
    return ans;
}
ll solve() {
    memset(dp, -1, sizeof(dp));
    int pos = 0;
    for (int i = n - 1; i >= 0; i--) {
        a[pos++] = s[i] - '0';
    }
    return dfs(n - 1, true, true, k);
}
int main() {
    cin >> s >> k;
    n = strlen(s);
    cout << solve() << endl;
    return 0;
}