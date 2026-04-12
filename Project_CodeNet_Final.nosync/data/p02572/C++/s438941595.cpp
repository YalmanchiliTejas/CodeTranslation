#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    const long long MOD = 1e9 + 7;

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + sum * a[i]) % MOD;
        sum = (sum + a[i]) % MOD;
    }
    cout << ans << '\n';
}