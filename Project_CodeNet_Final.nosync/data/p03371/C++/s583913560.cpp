#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int64_t ans = 1e18;
    for(int ab = 0; ab <= 2 * max(X, Y); ab += 2) {
        int64_t a = max(0, X - ab / 2);
        int64_t b = max(0, Y - ab / 2);
        ans = min(ans, a * A + b * B + ab * C);
    }
    cout << ans << '\n';
    return 0;
}
