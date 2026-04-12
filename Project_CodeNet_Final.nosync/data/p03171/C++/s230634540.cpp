#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ld long double
typedef vector <ll> vi;                 // Vector of long long
typedef vector <vi> vvi;                // Vector of vi
typedef vector <pair<ll,ll>> ii;        // Vector of pairs
#define ff first                        // For pairs
#define ss second                       // For pairs
#define sz(a) int((a).size())           // Function to determine size of any container
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree < ll ,  null_type ,  less<ll> ,  rb_tree_tag ,  tree_order_statistics_node_update >
#define MAX (ll)((3 * 1e3) + 5)

ll n;
vi arr;
ll dp[MAX][MAX][2];

ll solve(ll l, ll r, ll t)
{
    if (l > r)
        return 0;

    if (dp[l][r][t] == -1)
    {
        if (t == 0)
            dp[l][r][t] = max(solve(l + 1, r, t ^ 1) + arr[l], solve(l, r - 1, t ^ 1) + arr[r]);
        else
            dp[l][r][t] = min(solve(l + 1, r, t ^ 1) - arr[l], solve(l, r - 1, t ^ 1) - arr[r]);
    }
    return dp[l][r][t];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(0, n - 1, 0) << "\n";
}