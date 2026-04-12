#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long b = k + 1; b <= n; b++) {
        long long m = n / b;
        ans += (b - k) * m;
        ans += max(n - (b * m + k - 1), 0LL);
        ans -= (k == 0 ? 1 : 0);
        // cout << "b=" << b << " m=" << m << " ans=" << ans << endl;
    }
    cout << ans << endl;
    return 0;
}