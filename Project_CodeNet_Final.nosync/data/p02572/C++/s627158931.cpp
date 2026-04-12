#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
#define double long double
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        sum -= arr[i];
        // int temp = ((sum % MOD) * arr[i]) % MOD;
        // sum = ((sum % MOD) + (temp));
        ans += (sum % MOD) * arr[i];
        ans %= MOD;
    }
    cout << ans << endl;
}

int32_t main()
{
    IOS;
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    solve();

}