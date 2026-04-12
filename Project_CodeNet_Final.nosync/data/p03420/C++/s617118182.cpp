#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    for (int i = k + 1; i <= n; i++) {
        ans += (n / i) * (i - k);
        if (k != 0 && n % i >= k) ans += n % i - k + 1;
        if (k == 0 && n % i > k) ans += n % i;
    }
    cout << ans << endl;
}
