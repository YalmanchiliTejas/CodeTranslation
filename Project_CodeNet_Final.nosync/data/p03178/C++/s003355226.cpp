// Math = ♥️

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define sz(c) ((ll)c.size())
#define ordered_set                            \
    tree<ll, null_type, less<ll>, rb_tree_tag, \
         tree_order_statistics_node_update>
#define MAX (ll)(1e5 + 5)
#define MOD (ll)(1e9 + 7)

ll dp[MAX][105][2];
ll D;
string num;

ll solve(ll d, ll cnt, ll f) {
    if (d == -1) {
        if (cnt == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (dp[d][cnt][f] == -1) {
        ll ans = 0;
        if (f == 0) {
            for (int i = 0; i <= 9; i++) {
                ans += solve(d - 1, (cnt + i) % D, 0);
                ans %= MOD;
            }
        } else {
            for (int i = 0; i < (num[d] - '0'); i++) {
                ans += solve(d - 1, (cnt + i) % D, 0);
                ans %= MOD;
            }
            ans += solve(d - 1, (cnt + (num[d] - '0')) % D, 1);
            ans %= MOD;
        }
        dp[d][cnt][f] = ans;
    }
    return dp[d][cnt][f];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> num >> D;
    reverse(all(num));
    cout << (((solve(num.size() - 1, 0, 1) - 1) + MOD) % MOD) << "\n";
}
