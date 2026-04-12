#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
    ll n, k, b, ans = 0;

    cin >> n >> k;

    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }

    for (b = k + 1; b <= n; b++) {
        ans += (ll)(b - k) * (n / b);
        ans += max(0ll, n % b - k + 1);
    }

    cout << ans << endl;

    return 0;
}