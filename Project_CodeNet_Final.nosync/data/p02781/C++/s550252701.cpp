#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int k;
ll dp[1005][5][3];
ll solve(int idx, int cnt, int state) {
    if (idx == s.size())
        return 0;
    ll &ret = dp[idx][cnt][state];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i <= 9; i++) {
        int newcnt = cnt - (i > 0);
        if (newcnt < 0) continue;
        if (idx == s.size() - 1 && state == 2) continue;
        if (idx == s.size() - 1 && state == 1 && i > s[idx] - '0') continue;
        int newstate = state;
        if (newstate == 1 && i > s[idx] - '0') newstate = 2;
        if (newstate == 1 && i < s[idx] - '0') newstate = 0;
        ret += solve(idx + 1, newcnt, newstate) + (newcnt == 0);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> k;
    ll cnt = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= 9; i++) {
        if (s.size() > 1 && k == 1) cnt++;
        if (s.size() == 1 && k == 1 && i <= s[0] - '0') cnt++;
        int state = 0;
        if (i == s[0] - '0')
            state = 1;
        else if (i > s[0] - '0')
            state = 2;
        cnt += solve(1, k - 1, state);
    }
    cout << cnt;
    return 0;
}
