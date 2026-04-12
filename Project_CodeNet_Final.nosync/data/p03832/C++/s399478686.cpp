#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007LL
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
#define off 100

using namespace __gnu_pbds;
using namespace std ;

typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef pair<int, int> pii;

#define maxn 500005

class numberTheory{

public:
    numberTheory(){}

    pii extendedEuclid(i64 a, i64 b) { // returns x, y | ax + by = gcd(a,b)

        if(b == 0) return pii( a >= 0 ? 1 : -1 , 0LL);
        else {
            pii d = extendedEuclid(b, a % b);
            return pii(d.yy, d.xx - d.yy * (a / b));
        }

    }

    i64 modularInverse(i64 a, i64 n) {
        pair<i64,i64> ret = extendedEuclid(a, n);
        return ((ret.xx % n) + n) % n;
    }


    i64 bigMod(i64 a, i64 n , i64 m)
    {
        if(n==0) return 1 ;
        i64 ret = bigMod(a,n/2,m) ;
        ret = (ret*ret)%m ;
        if(n%2) ret = (ret*a)%m ;
        return ret ;
    }
};

const i64 N = 200000 ;

i64 fact[N+5] , invFact[N+5] ;

i64 C(i64 n, i64 r)
{
    if( n<0 || r<0 || r>n ) return 0 ;
    i64 ret = (fact[n]*invFact[r])%mod ;
    return (ret*invFact[n-r])%mod ;
}

void preprocess()
{
    numberTheory nt ;

    fact[0] = 1 ;
    for(i64 x=1 ; x<=N ; x++) fact[x] = (fact[x-1]*x)%mod ;

    invFact[N] = nt.modularInverse(fact[N],mod) ;

    for(i64 x=N-1 ; x>=0 ; x--) invFact[x] = (invFact[x+1]*(x+1) )%mod ;
}



int dis[1005][1005] , dp[1005][1005] ;

int main()
{
    preprocess() ;

    int n , a , b , c , d ;

    scanf("%d %d %d %d %d",&n,&a,&b,&c,&d) ;

    dis[0][0] = 1 ;

    for(int i=1; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            if( i%j != 0 ) continue ;
            int k = i/j ;

            dis[i][j] = (1LL*C(i-1,k-1)*dis[i-k][j-1])%mod ;
          //  printf("%d %d: %d\n",i,j,dis[i][j]) ;
        }
    }

    for(int i=0 ; i<=n ; i++) dp[0][i] = 1 ;
//    dp[0][0] = 1 ;


    for( int i=1 ; i<=n ; i++ )
    {
        for(int j=a ; j<=b ; j++)
        {
            dp[i][j] = dp[i][j-1] ;

            for(int k=c ; k*j<=i && k<=d ; k++)
            {
                int ret = (1LL*C(i,k*j)*dis[k*j][k])%mod ;

                dp[i][j] = ( dp[i][j] + 1LL*dp[i-k*j][j-1]*ret )%mod ;
            }
       //     printf("---- %d %d: %d\n",i,j,dp[i][j]) ;
        }
    }

    printf("%d\n" , dp[n][b] ) ;

    return 0 ;
}
