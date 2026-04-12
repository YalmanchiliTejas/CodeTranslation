#include <iostream>
#define int long long

using namespace std;

const int Num = 2e5 + 10;
const int Mod = 1e9 + 7;

int a[Num];

signed main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; ++i)
      cin >> a[i], sum += a[i];

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        sum -= a[i];
        ans += a[i] * (sum % Mod);
        ans %= Mod;
    }

    cout << ans << '\n';

    return 0;
}

