#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll ans = ll(INF);
    rep(i, x+1) {
        // Aピザの枚数
        int buy_a = i;
        // ABピザの枚数
        int buy_ab = (x-i) * 2;
        int buy_b = max(0, y - (x-i));
        ans = min(ans, ll(buy_a*a+buy_b*b+buy_ab*c));
    }
    rep(i, y+1) {
        // Bピザの枚数
        int buy_b = i;
        // ABピザの枚数
        int buy_ab = (y-i) * 2;
        int buy_a = max(0, x - (y-i));
        ans = min(ans, ll(buy_a*a+buy_b*b+buy_ab*c));
    }

    cout << ans << endl;
}