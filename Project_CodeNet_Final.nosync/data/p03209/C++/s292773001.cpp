#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

const ll MOD = 1000000007;
const long double EPS = 10e-10;
const int dyx[4][2] = {
    { 0, 1}, {-1, 0}, {0,-1}, {1, 0}
};

// string dfs(int level) {
//     if(level == 0) {
//         return string("P");
//     }
//     string s = dfs(level-1);
//     return string("B") + s + string("P") + s + string("B");
// }

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll n,x;
    cin >> n >> x;

    ll count[51], count_p[51];
    count[0] = 1;
    count_p[0] = 1;
    for(int i=1;i<=50;i++) {
        count[i] = count[i-1] * 2 + 3;
        count_p[i] = count_p[i-1] * 2 + 1;
    }

    if(x <= n) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0LL;
    for(int i=n-1;i>=0;i--) {
        x--;
        if(count[i] * 2 + 1 <= x) {
            x -= count[i] * 2 + 2;
            ans += count_p[i] * 2 + 1;
        } else if(count[i] + 1 <= x) {
            x -= count[i] + 1;
            ans += count_p[i] + 1;
        } else if(count[i] <= x) {
            x -= count[i];
            ans += count_p[i];
        }
        // cerr << x << " " << ans << endl;
        if(x <= 0) break;
    }
    cout << ans << endl;
}
