#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
//#define mod 1000000007LL
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
typedef pair<i64, i64> pii;

int mod ;

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

numberTheory nt ;
int n ;

int p1[3005] , p2[3005*3005] ;
int st[3005][3005] ;

int s(int n , int k)
{
    return (st[n][k] + 1LL*(k+1)*st[n][k+1])%mod ;
}

int f(int k )
{
    i64 ans = 0 ;

    for(int i=0 ; i<=k ; i++)
    {
        int ret = ( 1LL*p1[n-k]*p2[i*(n-k)] )%mod ;
        ret = (1LL*ret*(( st[k][i] + 1LL*st[k][i+1]*(i+1) )%mod) )%mod ;
    //    ret = (1LL*ret*nt.bigMod(2,1LL*i*(n-k),mod))%mod ;

        ans = (ans+ret) ;
    }

    return ans%mod ;
}

int main()
{
    scanf("%d %d",&n,&mod) ;

    preprocess() ;

    st[0][0] = 1 ;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=i ; j++) st[i][j] = ( st[i-1][j-1] + 1LL*j*st[i-1][j] )%mod ;
    }

    for(int i=0 ; i<=n ; i++) p1[i] = nt.bigMod( 2 , nt.bigMod(2,i,mod-1) , mod ) ;
    p2[0] = 1 ;
    for(int i=1 ; i<=n*n ; i++) p2[i] = (2LL*p2[i-1])%mod ;

    int ans = nt.bigMod( 2 , nt.bigMod(2,n,mod-1)  , mod ) ;
  //  cout<<ans<<endl ;

    for(int i=1 ; i<=n ; i++)
    {
        int ret = (1LL*C(n,i)*f(i))%mod ;
      //  cout<<ret<<endl ;
        if( i%2 == 1 ) ans = (ans-ret)%mod ;
        else ans = (ans+ret)%mod ;
    }

    ans = (ans%mod + mod)%mod ;

    printf("%d\n",ans) ;

    return 0 ;
}
