// Dāritys Morgho ban Rōvēgrie
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
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

string num;
int K, D = 0;
vector<vvi> f(10005, vvi(105, vi(2, -1)));

int check(char c)
{
    return (c - '0');
}

int call(int pos, int sum, int flag)
{
    if (pos == num.size())
    {
        if (sum % D == 0) return 1;
        else return 0;
    }

    if (f[pos][sum][flag] != -1) return f[pos][sum][flag];

    int lim = 9;
    if (flag == 0) lim = check(num[pos]);

    int res = 0;
    for (int i = 0; i <= lim; i++)
    {
        int n_sum = (sum + i) % D;

        int n_flag = flag;
        if (i < lim) n_flag = 1;

        res = (res + call(pos + 1, n_sum, n_flag)) % MOD;
    }

    return f[pos][sum][flag] = res;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> num >> D;

    int ans = (call(0, 0, 0) + MOD - 1) % MOD;
    if (ans < 0) ans = 0;
    cout << (ans % MOD) << endl;
    return 0;
}
