/* Simplicity and Goodness */

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
using namespace std;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> indexed_set;

void my_dbg() { cout << endl; }
template<typename Arg, typename... Args> void my_dbg(Arg A, Args... B)
{ cout << ' ' << A; my_dbg(B...); }
#define dbg(...)  cout << "(" << #__VA_ARGS__ << "):", my_dbg(__VA_ARGS__)

#define scn(n) scanf("%d", &n)
#define lscn(n) scanf("%lld", &n)
#define pri(n) printf("%d ", (int)(n))
#define prin(n) printf("%d\n", (int)(n))
#define lpri(n) printf("%lld ", n)
#define lprin(n) printf("%lld\n", n)
#define rep(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9+7;
const int N = 3e3+2;

/* dp[i][j] : max score first player can get when elements from 
 * i to j are available and first player starts the game
*/
ll a[N];
ll dp[N][N];

ll rec(int i, int j)
{
    if(i == j)
        return a[i];
    if(i > j)
        return 0;

    ll& ans = dp[i][j];

    if(ans != -1)
        return ans;

    ll v1 = a[i] + min(rec(i+2, j), rec(i+1, j-1)); // I want the oppenent to get less score than mine
    ll v2 = min(rec(i+1, j-1), rec(i, j-2)) + a[j]; // For the first player, the opponent is second player and vice versa

    ans = max(v1, v2);
    return ans;
}

void solve()
{
    int n;
    scn(n);

    ll total = 0;

    rep(i, 0, n)
    lscn(a[i]), total += a[i];

    memset(dp, -1, sizeof(dp));

    ll here = rec(0, n-1);

    lprin(here - (total - here));
}

int main()
{
    int t = 1;
    // scn(t);
    
    while(t --) {
        solve();
    }
    return 0;
}