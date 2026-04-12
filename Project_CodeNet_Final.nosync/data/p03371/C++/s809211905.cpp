#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0);
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
ll a, b, c, x, y;
int main() {
    IO;
   
    cin >> a >> b >> c >> x >> y;
    ll res = LINF;
    res = min(res, a * x + b * y);
    res = min(res, 2 * c * min(x, y) + (x - min(x, y)) * a + (y - min(x, y)) * b);
    res = min(res, 2 * c * max(x, y));
    cout << res;
    return 0;
}
