//Be Name Khoda
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma optimize O3
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long int LL;
typedef LL ll;
typedef long double ld;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;
 
#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (int i=a;i<b;i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))
#define RET(x) { cout << x; exit(0); } 
#define RETD(x) { cout << fixed << setprecision(15) << x; exit(0); }
const ll M=2e5+5,LG=32,SM=600+5,inf=1e18+5;
ll mod=1e9+7;

ll n;
vll g[M];

str z[2]={"First","Second"};

ll dfs(ll x,ll p)
{
    if (SZ(g[x])==1) return 1;
    ll f=0;
    for (ll y:g[x])
    {
        if (y==p) continue;
        f+=dfs(y,x);
    }
    if (f>1) RET(z[0]);
    if (f==1) return 0;
    return 1;
}

int main()
{
    cin >> n;
    if (n==2) RET(z[1]);
    if (n==1) RET(z[0]);
    ll x;
    For(i,1,n)
    {
        ll u,v;
        cin >> u >> v;
        u--;v--;
        g[u].PB(v);g[v].PB(u);
    }
    For(i,0,n) if (SZ(g[i])>1) x=i; 
    RET(z[!dfs(x,x)]);
}    
