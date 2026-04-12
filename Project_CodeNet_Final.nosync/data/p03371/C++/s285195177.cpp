#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int A, B, C, X, Y;
    ll ans = 0;
    cin >> A >> B >> C >> X >> Y;

    int a = min(X, Y);
    X -= a;
    Y -= a;
    ll cost_a = 0;
    ll cost_b = 0;
    cost_a = A*a + B*a;
    cost_b = 2 * C * a;
    ans = min(cost_a, cost_b);
    if (X <= 0 && Y <= 0) {
        cout << ans << endl;
    } else if (X > 0) {
        cost_a = A*X;
        cost_b = 2 * C * X;
        ans += min(cost_a, cost_b);
        cout << ans << endl;
    } else {
        cost_a = B*Y;
        cost_b = 2 * C * Y;
        ans += min(cost_a, cost_b);
        cout << ans << endl;
    }
    return 0;
}
