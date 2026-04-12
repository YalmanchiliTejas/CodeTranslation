#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &it : a) cin >> it;
    int64_t ans = 0, sum = 0;
    
    for (int i = 0; i < n; i++) {
        ans = (ans + sum * a[i]) % mod;
        sum = (sum + a[i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}