#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, mod = 1e9 + 7;

long long a[N];
long long sum[N] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        sum[i] = (sum[i + 1] + a[i]) % mod;
    }
    long long res = 0;
    for (int i = 1; i < n; ++i) {
        res = (res + a[i] * sum[i + 1] % mod) % mod;
    }
    cout << res << '\n';
    return 0;
}