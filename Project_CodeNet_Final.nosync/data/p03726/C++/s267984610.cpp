#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define IN freopen("test.txt","r",stdin)
#define OUT freopen("pieaters.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<i64, i64> pii;

#define INF 2000000000
#define alpha 26
const int N = 200 ;
#define LOG 18

#define maxn 100005

vector <int> g[maxn] ;

int dfs(int u ,int par)
{
    int ans = 1 ;
    for(int i=0 ; i<g[u].size() ; i++)
    {
        int v = g[u][i] ;
        if(v==par) continue ;
        ans += dfs(v,u) ;
    }
    if( ans > 2 ) return ans ;
    return (ans&1) ;
}

int main()
{
    int n ;

    scanf("%d",&n) ;

    for(int i=1 ; i<n ; i++)
    {
        int u , v ;
        scanf("%d %d",&u,&v) ;
        g[u].pb(v) ; g[v].pb(u) ;
    }

    int res = dfs(1,0) ;

    if(res==0) printf("Second\n") ;
    else printf("First\n") ;

    return 0 ;
}
