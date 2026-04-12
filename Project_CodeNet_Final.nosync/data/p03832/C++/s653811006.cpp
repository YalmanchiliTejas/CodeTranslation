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
const int MAX = 2e3 + 10;
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
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

int C[MAX][MAX] = {0}, fact[MAX] = {0}, dp[MAX][MAX] = {0};

int power(int x, int n)
{
    x %= MOD;
    int res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res *= x, res %= MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    C[0][0] = fact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    dp[0][a - 1] = 1;
    for (int x = a; x < b + 1; x++)
    {
        for (int i = 0; i < n + 1; i++)
        {
            int k = x * c;
            int net = 0;
            while (i >= k && k <= x * d)
            {
                int count = (dp[i - k][x - 1] * C[n - (i - k)][k]) % MOD;
                count = (count * fact[k]) % MOD;

                int temp = power(fact[x], k / x);
                count = (count * power(temp, MOD - 2)) % MOD;

                count = (count * power(fact[k / x], MOD - 2)) % MOD;

                net = (net + count) % MOD;
                k += x;
            }
            dp[i][x] = (net + dp[i][x - 1]) % MOD;
        }

    }
    cout << dp[n][b] << endl;
    return 0;
}
