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
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define ordered_set                            \
    tree<ll, null_type, less<ll>, rb_tree_tag, \
         tree_order_statistics_node_update>

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll dp[n][n][2];
    for (int i = 0; i < n; i++) {
        dp[i][i][0] = arr[i];
        dp[i][i][1] = -arr[i];
    }

    for (int gap = 1; gap < n; gap++) {
        for (int i = 0; i + gap < n; i++) {
            dp[i][i + gap][0] = max(dp[i + 1][i + gap][1] + arr[i],
                                    dp[i][i + gap - 1][1] + arr[i + gap]);
            dp[i][i + gap][1] = min(dp[i + 1][i + gap][0] - arr[i],
                                    dp[i][i + gap - 1][0] - arr[i + gap]);
        }
    }

    cout << dp[0][n - 1][0] << "\n";
}
