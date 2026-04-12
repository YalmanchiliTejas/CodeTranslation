#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int sum = a * x + b * y;
    chmin(sum, 2 * c * max(x, y));
    if (x > y) {
        chmin(sum, 2 * c * y + a * (x - y));
    } else {
        chmin(sum, 2 * c * x + b * (y - x));
    }
    cout << sum << endl;
    return 0;
}