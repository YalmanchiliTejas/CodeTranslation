#include <iostream>
#include <vector>
using namespace std;

#define int long long

const int MOD = 1000000007;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> cum(n);
    cum[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) cum[i] = (cum[i + 1] + a[i]) % MOD;

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += (a[i] * (cum[i + 1] % MOD)) % MOD;
    }

    cout << ans % MOD<< endl;
    return 0;
}
