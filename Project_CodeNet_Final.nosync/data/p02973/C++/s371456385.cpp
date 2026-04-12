#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = (int)(1e9+1) - a[i];
    }

    int dp0[n+1], dp1[n+1];
    fill(dp1, dp1+n+1, 1e9+1);
    dp0[0] = 0, dp1[0] = 0;
    int maxl = 0;
    for (int i = 1; i <= n; i++) {
        dp0[i] = upper_bound(dp1, dp1+maxl+1, a[i]) - dp1;
        maxl = max(maxl, dp0[i]);
        dp1[dp0[i]] = min(dp1[dp0[i]], a[i]);
    }

    cout << maxl << endl;

    return 0;
}
