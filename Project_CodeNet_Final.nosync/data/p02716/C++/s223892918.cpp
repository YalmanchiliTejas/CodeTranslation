#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<long long> pre(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    pre[1] = a[1];
    pre[2] = a[2];
    for(int i = 3; i <= n; i++) {
        pre[i] = 1LL*a[i] + pre[i-2];
    }

    vector<long long> dp(n+1);
    dp[2] = max(a[1], a[2]);
    for(int i = 4; i <= n; i += 2) {
        dp[i] = max(a[i] + dp[i-2], pre[i-1]);
    }
    dp[1] = 0;
    for(int i = 3; i <= n; i += 2) {
        dp[i] = max(dp[i-1], 1LL * a[i] + dp[i-2]);
    }

    cout << dp[n] << endl;



    return 0;
}
