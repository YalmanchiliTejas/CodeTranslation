#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s; i < e; i++)


typedef long long ll;

const int N = 3500;

int n;
int a[N];

ll dp[N][N];

ll calc(int j, int k) {
    if(j > k) return 0;
    ll &r = dp[j][k];
    if(r != -1) return r;
    ll res = 0;
    res = max(a[j] - calc(j + 1, k), a[k] - calc(j, k - 1));
    // cout << i << " " << j << " " << k << "  " << res << endl;
    return r = res;
}

int main() {
    cin >> n;
    fore(i, 0, n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << calc(0, n - 1) << endl;
}