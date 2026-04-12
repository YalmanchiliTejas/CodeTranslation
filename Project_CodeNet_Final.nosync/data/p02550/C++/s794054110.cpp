#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) begin(x), end(x)
using namespace std;
using ll = long long;
constexpr ll Mod = 998244353;
constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;
const double PI = acos(-1);
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
/*-------------------------------------------*/

ll n, x, m;

int t[100009];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> x >> m;

    ll ans = 0;
    int time = 0;
    while(!t[x]) {
        t[x] = ++time;
        ans += x;
        x = (x * x) % m;
        n--;
        if(n == 0) {
            cout << ans << endl;
            return 0;
        }
    }

    int cy = 0;
    ll cost = 0, y = x;
    do {
        cost += y;
        y = (y * y) % m;
        cy++;
    } while(y != x);

    ans += (n / cy) * cost;
    n %= cy;

    while(n--) {
        ans += x;
        x = (x * x) % m;
    }

    cout << ans << endl;

    return 0;
}