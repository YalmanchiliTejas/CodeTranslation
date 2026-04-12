#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (x[i] > y[i]) swap(x[i], y[i]);
    }
    long long ans = (long long)(*max_element(x, x+n) - *min_element(x, x+n)) *
        (*max_element(y, y+n) - *min_element(y, y+n));
    int idx[n];
    iota(idx, idx+n, 0);
    sort(idx, idx+n, [&x](int i, int j) { return x[i] < x[j]; });

    const long long B = *max_element(y, y+n) - x[idx[0]];
    int mn = y[idx[0]], mx = x[idx[n-1]];
    for (int i = 1; i < n; i++) {
        int j = idx[i-1], k = idx[i];
        mn = min(mn, y[j]);
        mx = max(mx, y[j]);
        long long A = mx - min(mn, x[k]);
        ans = min(ans, A * B);
    }
    cout << ans << endl;
}
