#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> s(n);
    s[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) s[i] = (s[i+1] + a[i])%MOD;

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i] * s[i+1];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
