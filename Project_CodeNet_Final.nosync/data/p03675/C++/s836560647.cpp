#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007
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

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int a[200005] ;

int main()
{
    int i , j , k , l , m , n ;

    scanf("%d",&n) ;
    for(i=1 ; i<=n ; i++) scanf("%d",&a[i]) ;

    for(i=n ; i>=1 ; i-=2){
        printf("%d",a[i]) ;
        if(n!=1) printf(" ") ;
    }
    if(n%2) i = 2 ;
    else i = 1 ;

    for( ; i<=n ; i+=2)
    {
        printf("%d",a[i]) ;
        if( i+2 <= n ) printf(" ") ;
    }

    printf("\n") ;
    return 0 ;
}
