#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = a * x + b * y;
    for (int i = 1; i <= max(x, y) * 2; i++) {
        chmin(ans, 2 * i * c + a * max(0, x - i) + b * max(0, y - i));
    }

    cout << ans << endl;
    return 0;
}