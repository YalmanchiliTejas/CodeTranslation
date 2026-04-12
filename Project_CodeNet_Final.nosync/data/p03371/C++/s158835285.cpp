#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int64_t ans = INT64_MAX;
    for (int i = 0; i <= max(x, y) * 2; i++) {
        int cnt_a = i / 2;
        int cnt_b = i / 2;
        int a_needed = max(x - cnt_a, 0);
        int b_needed = max(y - cnt_b, 0);
        int64_t total = a * a_needed + b * b_needed + c * i;
        ans = min(ans, total);
    }
    cout << ans << endl;
    return 0;
}