#include <bits/stdc++.h>

#define int long long

#define F first
#define S second
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    const int mod = 1e9+7;
    int n, s = 0, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i], s += a[i];
    for(int i = 0; i < n; i++) {
        s -= a[i];
        ans = ( ans + ( a[i] * ( s % mod ) ) ) % mod;
    }
    cout << ans;

    return 0;
}
