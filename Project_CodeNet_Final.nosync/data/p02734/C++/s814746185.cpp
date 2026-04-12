/// Code By t_bone_289
/// An Immature Programmer.... I'm still developing !!
/// 29/03/20
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define endl '\n'
#define M 998244353
#define error(x) cout << #x << " = " << x << endl;
#define pi 3.14159265358979323846
typedef long long ll;
typedef long double ld;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll powmod(ll base, ll exp, ll MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return (res % MOD);
}

ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base);
        base = (base * base);
        exp /= 2;
    }
    return (res);
}

ll SUM = 3100;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll s;
    cin >> s;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<ll> > dp(n + 1, vector<ll>(SUM + 1, 0));
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        dp[i][v[i]] = i;
        for (ll j = 0; j <= SUM; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
            if (j - v[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i]]) % M;
            }
        }
        ans = (ans + dp[i][s]) % M;
    }
    cout << ans;
    return 0;
}
