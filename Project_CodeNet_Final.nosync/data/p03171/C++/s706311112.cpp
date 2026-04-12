// Daritys Morgho ban Rovegrie
// Math = ♥
// Sometimes it is people that no one imagines anything of who do things that no one can imagine
// After all this time? Always

#include <bits/stdc++.h>                        // uncomment before submission
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define ld long double
const int INF = 1e15 + 7;
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<ii> vii;                 // Vector of pairs
typedef vector<vii> vvii;               // Vector of Vector of pairs
typedef vector<bool> vb;                // Vector of bool
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Push back to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
#define run(x, c) (x)=(c).begin(); (x)!=(c).end(); (x)++ // Mainly used by me for range based loops
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

vi v;
vector<vvi> f(3005, vvi(3005, vi(2, -1)));

int solve(int l, int r, int flag)
{
    if (l > r) return 0;
    if (f[l][r][flag] != -1) return f[l][r][flag];

    if (flag)
        return f[l][r][flag] = max(solve(l + 1, r, flag ^ 1) + v[l], solve(l, r - 1, flag ^ 1) + v[r]);
    else
        return f[l][r][flag] = min(solve(l + 1, r, flag ^ 1) - v[l], solve(l, r - 1, flag ^ 1) - v[r]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n, v.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    cout << solve(1, n, 1) << endl;
    return 0;
}

