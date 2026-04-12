#include <bits/stdc++.h>

#define ll long long
#define MAXN 3005

using namespace std;

ll dp[MAXN][MAXN];

ll sum(ll pre[], int l, int r) {

    return pre[r] - (l ? pre[l - 1] : 0);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll a[n], pre[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = (i ? pre[i - 1] : 0) + a[i];
    }

    for(int len = 0; len < n; len++) {
        for(int l = 0; l < n - len; l++) {
            int r = l + len;
            
            if(l == r) {
                dp[l][r] = a[l];
                continue;
            }

            dp[l][r] = sum(pre, l, r) - min(dp[l + 1][r], dp[l][r - 1]);
        }
    }

    cout << 2 * dp[0][n - 1] - pre[n - 1] << endl;
    return 0;
}
