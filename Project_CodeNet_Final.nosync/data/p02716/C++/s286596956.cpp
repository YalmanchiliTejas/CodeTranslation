#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , A[MAXN] , dp[MAXN][3][2];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(ll i = 0 ; i < MAXN ; i++){
        for(ll j = 0 ; j < 3 ; j++) dp[i][j][0] = dp[i][j][1] = -INF;
    }
    dp[0][1][0] = 0;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)    cin >> A[i];
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 0 ; j < 3 ; j++){
            ll x = (i - 1) / 2 + j - 1 , y = -1;
            if(x < 0 || x > n)  continue;
            if(x == i / 2 + 1)  y = 2;
            if(x == i / 2)  y = 1;
            if(x == i / 2 - 1)  y = 0;
            if(y == -1) continue;
            dp[i][y][0] = max(dp[i - 1][j][0] , dp[i - 1][j][1]);
            if(y != 2)  dp[i][y + 1][1] = dp[i - 1][j][0] + A[i];
            //cout << i << sep << j << sep << y << sep << dp[i][y][0] << sep << dp[i][y][1] << endl;
        }
    }
    cout << max(dp[n][1][0] , dp[n][1][1]) << endl;

    return 0;
}
/*

*/
