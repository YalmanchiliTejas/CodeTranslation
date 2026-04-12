#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll n = a * x + b * y;
    ll m = 2 * c * max(x, y);
    int p = x < y ? b : a;
    ll l = 2 * c * min(x, y) + p * abs(x - y);

    ll min_ans = min(n, min(m, l));
    cout << min_ans << endl;
    return 0;
}