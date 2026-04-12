#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    long long ans(0);

    cin >> n >> k;

    for (int a(k + 1); a <= n; a++) {
        int pmax = (n + 1) / a - 1;
        ans += (pmax + 1) * (a - k);
        int x = n - (pmax + 1) * a + 1;
        ans += (x >= k ? x - k : 0);
    }

    if (k == 0)
        ans -= n;

    cout << ans << '\n';
    return 0;
}
