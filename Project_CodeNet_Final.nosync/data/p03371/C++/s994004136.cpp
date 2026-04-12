#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;
    ans = min(ans, C * 2 * X + max(0, Y - X) * B);
    ans = min(ans, C * 2 * Y + max(0, X - Y) * A);
    cout << ans << endl;
}
