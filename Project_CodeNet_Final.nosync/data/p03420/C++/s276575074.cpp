#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }

    ll t = 0;

    for (int i = k + 1; i <= n; i++) {
        t += n / i * (i - k);
        t += max(0ll, n - ((n / i) * i) - k + 1);
    }

    cout << t << endl;
}
