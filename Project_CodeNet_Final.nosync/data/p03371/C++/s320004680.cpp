#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = A * X + B * Y;
    ans = min(ans, max(X, Y) * 2 * C);
    int mi = min(X, Y);
    X -= mi, Y -= mi;
    ans = min(ans, mi * 2 * C + A * X + B * Y);
    cout << ans << endl;
    return 0;
}
