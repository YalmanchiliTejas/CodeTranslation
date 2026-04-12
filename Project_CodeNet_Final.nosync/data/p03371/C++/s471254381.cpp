#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    lint ret = inf;
    for (int i = 0; i <= 200000; ++i) {
        lint xx = i, yy = i;
        lint temp = i * c;
        temp += max(0LL, 2 * x - xx + 1) / 2 * a;
        temp += max(0LL, 2 * y - yy + 1) / 2 * b;
        chmin(ret, temp);
    }
    cout << ret << "\n";
    return 0;
}