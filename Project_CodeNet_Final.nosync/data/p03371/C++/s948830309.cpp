#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 0;
    if(A + B <= 2 * C) {
        ans += A * X + B * Y;
    } else {
        ans += 2 * C * min(X, Y);
        if(X > Y) {
            ans += min(A, 2 * C) * (X - Y);
        } else {
            ans += min(B, 2 * C) * (Y - X);
        }
    }
    cout << ans;
    return 0;
}
