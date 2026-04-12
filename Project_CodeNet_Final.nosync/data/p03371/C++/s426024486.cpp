#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll base = X * A + Y * B;
    int min_needs = min(X, Y);
    int x_diff = X - min_needs;
    int y_diff = Y - min_needs;
    ll pair = C * 2 * min_needs;
    int min_a = min(A, C * 2);
    int min_b = min(B, C * 2);
    ll remain_a = min_a * x_diff;
    ll remain_b = min_b * y_diff;

    cout << min(base, pair + remain_a + remain_b) << endl;

    return 0;
}
