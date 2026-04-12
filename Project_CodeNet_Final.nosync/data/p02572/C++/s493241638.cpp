#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long> c_sum(n);
    c_sum[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        c_sum[i] = c_sum[i + 1] + a[i];
        c_sum[i] %= 1000000007;
    }

    long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += a[i] * c_sum[i + 1];
        ans %= 1000000007;
    }

    cout << ans << endl;

    return 0;
}
