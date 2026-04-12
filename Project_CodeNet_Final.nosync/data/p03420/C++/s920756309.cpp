#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    long long res = 0;
    for (long long b = k + 1; b <= n; b++) {
        res += n / b * (b - k);
        res += max(0LL, n - (n / b * b + k) + 1LL);
    }
    if (!k) res = n * n;
    cout << res << "\n";
    return 0;
}