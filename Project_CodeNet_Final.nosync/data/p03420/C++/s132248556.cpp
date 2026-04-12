#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0;
    cin >> n >> k;
    if (k == 0) {
        cout << n * n << '\n';
        exit(0);
    }
    for (int b = k + 1; b <= n; ++b) {
        ans += (b - k) * (n / b);
        ans += max(0ll, n % b - k + 1);
    }
    cout << ans << '\n';
    return 0;
}

