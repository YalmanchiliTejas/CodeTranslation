#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int N = (int) 3e3+ 10;

int n;
ll a[N];
ll memo[N][N];

ll dp(int l, int r) {
    if(l > r) return 0;
    ll &ans = memo[l][r];
    if(ans != -1) return ans;
    ll left = a[l] - dp(l + 1, r);
    ll right = a[r] - dp(l, r - 1);
    return ans = max(left, right);
}

void solve() {
    cin >> n;
    memset(memo, -1LL, sizeof(memo));
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << dp(0, n - 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    solve();
    return 0;
}