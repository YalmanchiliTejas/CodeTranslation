#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
ll dp[3002][3002];
ll a[3002], n;
ll func(ll st, ll end) {
    if(dp[st][end] != -1) {
        return dp[st][end];
    }
    if(st == end) {
        dp[st][st] = a[st];
        return a[st];
    }
    if(end == st + 1) {
        dp[st][end] = max(a[st], a[end]);
        return dp[st][end];
    }
    dp[st][end] = max(a[st] + min(func(st + 2, end), func(st + 1, end - 1)), a[end] + min(func(st + 1, end - 1), func(st, end - 2)));
    return dp[st][end];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll i, j, k, sum = 0;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = func(0, n - 1);
    cout << ans + ans - sum << endl;

    return 0;
}