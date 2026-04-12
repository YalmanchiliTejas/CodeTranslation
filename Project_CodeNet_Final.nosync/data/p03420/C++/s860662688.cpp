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

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int i = k + 1; i <= n; i++) {
        ll p = n / i;
        ll r = (n % i);
        ans += (i - k) * p;
        ans += max(0ll, r - k + 1);
    }

    if (k == 0) {
        ans -= n;
    }

    cout << ans << "\n";
}
