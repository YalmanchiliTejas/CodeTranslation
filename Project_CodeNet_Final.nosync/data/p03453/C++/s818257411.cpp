#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
#define maxn 100005
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define DBG pf("Hi\n")
#define INF 2000000000000000000LL
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

vector <i64> g[maxn] , c[maxn] , flagEdge[maxn] ;
i64 d[2][maxn]  , flagNode[maxn] ;
vector< pair<i64,i64> > vd ;

i64 dp[2][maxn] ;

struct data {
    i64 city, dist;
    data(i64 _city,i64 _dist){ city = _city ; dist = _dist ; }
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

void dijkstra(i64 src, i64 idx , i64 n)
{
    i64 i , j , k , l , m , cnt = 1 ;
    bool done[maxn] ;
    for(i=1 ; i<=n ; i++) done[i] = false ;
    
    for(i=1 ; i<=n ; i++) d[idx][i] = INF ;
    d[idx][src] = 0 ;

    priority_queue <data> pq ;

    pq.push( data(src,0) ) ;

    while( !pq.empty() )
    {
        data dat = pq.top() ;
        pq.pop() ;

        i64 u = dat.city ;
        
        if(done[u]==true) continue ;

     //   printf("%lld %lld\n",idx,u) ;

        for(i=0 ; i<g[u].size() ; i++)
        {
            i64 v = g[u][i] ;
            if( d[idx][v] > d[idx][u]+c[u][i] )
            {
                d[idx][v] = d[idx][u]+c[u][i] ;
                pq.push( data(v,d[idx][v]) ) ;
            }
        }
        done[u] = true ;
    }
    return ;
}

int main()
{
    i64 i , j , k , l , m , n , S , T ;

    scanf("%lld %lld",&n,&m) ;
    scanf("%lld %lld",&S,&T) ;

    for(i=1 ; i<=m ; i++)
    {
        i64 u , v , dis ;
        scanf("%lld %lld %lld",&u,&v,&dis) ;
        g[u].pb(v) ; c[u].pb(dis) ;
        g[v].pb(u) ; c[v].pb(dis) ;
    }

    dijkstra(S,0,n) ;
    dijkstra(T,1,n) ;

 //   for(i=1 ; i<=n ; i++) printf("....%lld: %lld %lld\n",i,d[0][i],d[1][i]) ;

    memset(flagNode,1,sizeof(flagNode)) ;

    for(i=1 ; i<=n ; i++)
    {
        if( d[0][i]+d[1][i] != d[0][T] ) flagNode[i] = 0 ;
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=0 ; j<g[i].size() ; j++)
        {
            k = g[i][j] ;
            if( d[0][i]+c[i][j]+d[1][k] != d[0][T] ) flagEdge[i].pb(0) ;
            else flagEdge[i].pb(1) ;
        }
    }

    for(i=1 ; i<=n ; i++)
    {
        vd.pb( mp(d[0][i],i) ) ;
    }

    sort( vd.begin() , vd.end() ) ;

    dp[0][S] = 1LL ; dp[1][T] = 1LL ;

    for(i=0 ; i< vd.size() ; i++)
    {
        i64 u = vd[i].second ;

        if( flagNode[u]==0 ) continue;

        for(j=0 ; j<g[u].size() ; j++)
        {
            if( flagEdge[u][j]==0 ) continue ;
            i64 v = g[u][j] ;
            if(flagNode[v]==0) continue ;
            dp[0][v] = (dp[0][v]+dp[0][u])%mod ;
        }
    }

    for(i=(int)vd.size() - 1 ; i>=0 ; i--)
    {
        i64 u = vd[i].second ;

        if( flagNode[u]==0 ) continue;

        for(j=0 ; j<g[u].size() ; j++)
        {
            if( flagEdge[u][j]==0 ) continue ;
            i64 v = g[u][j] ;
            if(flagNode[v]==0) continue ;
            dp[1][u] = (dp[1][v]+dp[1][u])%mod ;
        }
    }

  //  printf(" dp[0][T]: %lld\n",dp[0][T]) ;

  //  for(i=1 ; i<=n ; i++) printf("dp...%lld: %lld %lld\n",i,dp[0][i],dp[1][i]) ;

    i64 ans = (dp[0][T]*dp[0][T])%mod ;

    for(i=1 ; i<=n ; i++)
    {
        if(flagNode[i]==0) continue ;
        if( d[0][T] == 2*d[0][i] )
        {
            i64 path = (dp[0][i]*dp[1][i])%mod ;
      //      printf("node entered %lld %lld\n",i,path) ;
            ans = (ans- path*path )%mod ;
        }

        for(j=0 ; j<g[i].size() ; j++)
        {
            if( flagEdge[i][j]==0 ) continue ;
            k = g[i][j] ;
            if( flagNode[k]==0 ) continue ;

            if( 2*d[0][i] < d[0][T] && 2*d[1][k] < d[0][T] )
            {
       //         printf("entered %lld %lld\n",i,k) ;
                i64 path = (dp[0][i]*dp[1][k])%mod ;
                ans = (ans- path*path )%mod ;
            }
        }
    }

    printf("%lld\n",( (ans%mod) + mod)%mod) ;

    return 0 ;
}
/*
4 4
1 4
1 2 1
2 3 1
2 4 2
4 3 1


4 4
1 3
1 2 5
2 3 1
3 4 5
4 1 1

*/
