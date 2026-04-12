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
const int N = 2e5+2;

vl patty(52), siz(52);

ll cnt(int n, ll x)
{
    if(n == 0) return 1;
    if(x == 1) return 0;
    if(x <= 1 + siz[n-1]) return cnt(n-1, x-1);
    if(x == 2 + siz[n-1]) return patty[n-1] + 1;
    if(x <= 2 + 2 * siz[n-1]) return patty[n-1] + 1 + cnt(n-1, x - 2 - siz[n-1]);
    return patty[n];
}

void solve()
{
    { // Preprocess
        patty[0] = 1; siz[0] = 1;
        rep(i, 1, 51) {
            patty[i] = 2 * patty[i-1] + 1;
            siz[i] = 2 * siz[i-1] + 3;
        }
    }

    int n; ll x;
    scn(n); lscn(x);

    lprin(cnt(n, x));
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