#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN = 3003;

int n;

ll dp[mxN][mxN];
ll a[mxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int L=n; L>=1; L--) {
        dp[L][L]=a[L];
        for (int R=L+1; R<=n; R++) {
            dp[L][R]=max(a[L]-dp[L+1][R], a[R]-dp[L][R-1]);
        }
    }
    cout << dp[1][n] << endl;
}
