 /* 
sometimes you must hurt in order to know 
fall in order to grow,lose in order to gain  
because life's greatest lessons are learned through pain 

*/

/*
When you walk through a storm
Hold your head up high
And don't be afraid of the dark
At the end of the storm
There's a golden sky
And the sweet silver song
of the lark
Walk on, through the wind
Walk on, through the rain
Though your dreams be tossed
and blown
Walk on, walk on
With hope in your heart
And you'll never walk alone
 
*/ 

//IT TAKES EVERYTHING and IT IS NOT LUCK
 


#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
 
using namespace std;

#define sz(x) x.size()
#define clr(x) x.clear()
#define mem(x ,y) memset(x , y , sizeof x )
#define all(a ) a.begin() , a.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int , int>
#define endl "\n"
#define fast()   ios_base :: sync_with_stdio(false ) ; cin.tie(0) ; cout.tie(0) ;
#define dbg(args...) do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
#define dbgv(v ) rep(i, sz(v) )  cerr << v[i] << ' ' ;  cout << endl ;
#define dbga(x, n) rep(i , n ) cerr << x[i] << ' ' ;  cout << endl
#define forn(i,a,n ) for(int  i = a ; i <= n ; i++ )
#define rep(i ,n ) for(int i = 0 ; i < n ; i++ )
#define repi(i ,n ) for(int i = 1 ; i <= n ; i++ )
#define repit(i, c) for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )

const long long  mod = 1e9+7 ;
const int inf = 1e9  ;
const long long  lnf = 1e18 ;
 
int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int n,int pos ) { return (bool ) (n& (1<<pos))  ; }

template< typename T > void print(const T& v) {    cerr << v << ' ' ;}
template< typename T > T modMul(T x, T y ) { x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template< typename T > T modAdd(T x, T y  ) { x %= mod ; y %= mod ; return (x+y)%mod ;  }
template< typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
template< typename T > T modPow(T x, T k ) { if(k == 0 ) return 1; if(k&1  ) { return ( (x%mod)*modPow(x,k-1, mod )%mod )%mod ; } else { T ret = modPow(x,k/2 , mod ) ; ret %= mod ; return (ret*ret )%mod; } }
template< typename T > T ext_gcd(T num1 , T num2, T &X , T &Y ) { T r2,r1, q2, q1 , x2, x1, y2 ,y1 , x,  y, r   ; x2 = 1; y2 = 0;  x1 = 0; y1 = 1; for( r2 =num1 ,r1 = num2 ;r1 != 0 ; y2 = y1, y1 = y,x2 = x1 ,x1 = x ,r2 = r1, r1 = r) {q1 = r2/r1; x = x2 - q1*x1; y = y2 - q1*y1; r = r2%r1 ; } X = x2 ; Y = y2 ; return r2 ;  } 

template<typename T >
T modInv( T x , T m ) {  
    return modPow(x,m-2 , m) ; 
    long long ret, t ;
    ext_gcd( x, m ,ret ,t  ) ;
    ret %= m ;
    if(ret<0) ret += m  ;
    return ret;
}

typedef long long ll  ;
typedef unsigned long long  ull ;
typedef vector<int> vi  ;

//int dx[] = {0 , 0 ,+1, -1 } ;
//int dy[] = {-1, +1,0 , 0 };
 
/////////////////////////////////////  code from here ///////////////////////////////////////////////////

const int M = 200002 ;  
//const ll N = 1e1 ;
//const int N =10;

ll dp[3002][3001][3],  vis[3002][3001][3]   ;
ll  n , lim , a[M +2] ;

ll  func (int l, int r , int id) {
    
   // dbg(l,r , id) ;
    if(l== r) {
        if(id==1) return a[l] ;
        else return -a[l ] ;

    }
    ll &ans  = dp[l][r][id] ;
    if(vis[l][r][id] ) return dp[l][r][id ] ;
    vis[l][r][id ] = 1; 
    if(id==1 ) {
        ans = -lnf ;
        ans = max(ans, a[l]+func(l+1,r, 2) ) ;
        ans = max(ans, a[r]+func(l,r-1, 2) ) ;

    } else {

        ans = lnf ;
        ans = min(ans, -a[l]+func(l+1,r, 1) ) ;
        ans = min(ans, -a[r]+func(l,r-1, 1) ) ;

    }




    return ans ;

}



void solve() {  
    int x , y , q ; 
    cin >>n  ; 
    rep(i ,n ) cin>>a[i] ;


    cout << func(0,n-1, 1) << endl;


}


int main() {
       //  freopen("in.txt", "r", stdin  );
    // freopen( "out.txt", "w",stdout );     
    fast(); 
    int t=1; 
    // si(t) ;
    while( t-- ){
        
          

        solve() ;
    }




    return 0 ;




}
