#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

int main() {
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = A * X + B * Y;
    if (X >= Y) {
        chmin(ans, C * 2 * X);
        chmin(ans, C * 2 * Y + A * (X - Y));
    } else {
        chmin(ans, C * 2 * Y);
        chmin(ans, C * 2 * X + B * (Y - X));
    }
    cout << ans << endl;
}