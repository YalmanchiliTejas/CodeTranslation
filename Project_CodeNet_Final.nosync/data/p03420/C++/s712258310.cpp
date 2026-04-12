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
#define INF 1000000000
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
#define off 2
#define sq(x) ((x)*(x))

using namespace __gnu_pbds;
using namespace std ;

// typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef pair<i64, i64> pii;

int main()
{
    i64 i , j , k , l , m , n ;

    scanf("%lld %lld",&n,&k) ;

    i64 ans = 0LL ;

    for(i=k+1 ; i<=n ; i++)
    {
        j = n/i ;
        l = n%i ;

        ans += j*(i-k) ;
        ans += max(0LL,l-k+1) ;
    //    printf("%lld\n",ans) ;
    }

    if(k==0) ans -= n ;

    printf("%lld\n",ans) ;
    return 0 ;
}
