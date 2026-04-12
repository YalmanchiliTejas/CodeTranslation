#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int x, y; cin >> x >> y;
    int ans = 0;
    while (a + b > c * 2 && x && y)
        x--, y--, ans += c * 2;
    // cout << x << y << endl;
    if (x && a > 2 * c) ans += c * 2 * x, x = 0;
    if (y && b > c * 2) ans += c * 2 * y, y = 0;
    
    // cout << x << y << endl;
    cout << ans + x * a + y * b << endl;
}