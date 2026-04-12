#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(string s, string& t) {
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += (s[i] != t[i]);
    }
    return ans;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0, mod = 1e9 + 7;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            ans += sum * a[j];
            ans %= mod;
            sum += a[j];
            sum %= mod;
        }
        cout << ans;
    }
    return 0;
}
