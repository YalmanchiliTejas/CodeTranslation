/*

  _    _ _      _ _      _ _     _____ ____________ 
 | |__| | | _ _| | | _ _| | | __|__ / |__ /__ /__  |
 | '_ \_  _| ' \_  _| ' \_  _(_-<|_ \ ||_ \|_ \ / / 
 |_.__/ |_||_||_||_||_||_||_|/__/___/_|___/___//_/  

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db1(x) cout << #x << "=" << x << '\n'
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << '\n'
#define db3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << '\n'
#define rep(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(x) scanf("%s", x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(x) printf("%s\n", x)
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define F first
#define S second
#define pb push_back
#define ll long long

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int mpow(int base, int exp);
void ipgraph(int n,int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 2e5+7, M = N, OO = 1e9 + 7;
const ll LLOO = 1e18 + 7;
//=======================

vi g[N];
ll a[N];
int n;

void solve()
{
    si(n);
    ll sum = 0;
    rep(i,0,n) {sl(a[i]);sum = (sum+a[i])%mod;}
    ll ans = 0;
    rep(i,0,n)
    {
		sum = (sum-a[i]+mod)%mod;
		ans = (ans+(sum*a[i])%mod)%mod;
	}
	
	pl(ans);
    
}

int main()
{
    // uncomment if file :
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
    int t = 1;
    // si(t); // uncomment if testcases
    while (t--)
        solve();
    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int u, v;
    while (m--)
    {
        scanf("%d %d", &u, &v);
        g[u - 1].pb(v - 1);
        g[v - 1].pb(u - 1);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}
