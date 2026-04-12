#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define INF 1000000000000000000LL
#define mod 1000000007LL
#define IN freopen("C.in","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define REP(i,a,b) for(i=(a) ; i<=(b) ; i++)
#define DBG pf("Hi\n")
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 45
#define off 2
#define whatis(x) cout<<x<<endl ;

using namespace __gnu_pbds;
using namespace std ;

typedef pair<int,int> pi ;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define maxn 1000005

i64 a[55] ;

int main()
{
    i64 i , j , k , l , n , m ;

    scanf("%lld",&n) ;

    for(i=1 ; i<=n ; i++) scanf("%lld",&a[i]) ;

    sort( a+1 , a+n+1 ) ;

    i64 sum = 0LL ;

    for(i=1 ; i<=n ; i++) sum += a[i] ;

    i64 x = sum - n*n ;

    x = max( x  , 0LL ) ;

    REP(i,1,n) a[i] += x ;

    i64 lo = n , hi = a[n] ;

    while( lo<hi )
    {
        i64 m = ( lo+hi )/2 ;

        i64 ret = 0LL ;

        REP( i , 1 , n )
        {
            ret += (max(a[i]-m,0LL)+n)/(n+1) ;
        }
     //   printf("lo:%lld hi:%lld m:%lld ret:%lld x:%lld\n",lo,hi,m,ret,x) ;
        if( ret <= x ) hi = m ;
        else lo = m+1 ;

    }
    i64 cnt = 0LL ;
    REP(  i, 1 , n )
    {
        i64 c = (max(( a[i]-lo),0LL)+n)/(n+1) ;
        a[i] -= (n+1)*c ;
        cnt += c ;
    }

/*    for(i=1 ; i<=n ; i++) printf("%lld ",a[i]) ;
    printf("\n") ;
    printf("%lld %lld\n",cnt,x) ;
*/
    priority_queue<i64> pq ;

    REP(i,1,n) pq.push(a[i]) ;

    while( cnt<x )
    {
 //       printf("Entered\n") ;
        cnt++ ;
        i64 tp = pq.top() ;
        pq.pop() ;
        tp -= (n+1) ;
        pq.push( tp ) ;
    }

    for(i=1 ; i<=n ; i++)
    {
        a[i] = pq.top() ;
        pq.pop() ;
    }

 /*   for(i=1 ; i<=n ; i++) printf("%lld ",a[i]) ;
    printf("\n") ;
*/

    i64 ans = x ;

    while( 1 )
    {
        i64 mx = 0  ,id ;
        REP(i,1,n)
        {
            mx = max( mx , a[i] ) ;
            if( mx==a[i] ) id = i ;
        }
        if( mx > n-1 ) ans++ ;
        else break ;
        REP(i,1,n) a[i] += 1 ;
        a[id] -= (n+1) ;
    }

    printf("%lld\n",ans) ;

    return 0 ;
}
