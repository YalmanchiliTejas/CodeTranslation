/*
  Idea : reverse array calc lis  in nlogn 
    
*/    

// #pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std; 
  
#define     pii             pair<int ,int>
#define     ff              first
#define     ss              second
#define     pb(x)           push_back(x ) 
#define     mp              make_pair
#define     sz(x)           x.size()
#define     clr(x)          x.clear()
#define     mem(x ,y)       memset(x , y , sizeof x )
#define     all(a )         a.begin() , a.end()
#define     endl            "\n"
#define     si(x )          scanf("%d", &x)
#define     sl(x )          scanf("%I64d", &x)
#define     sd(x )          scanf("%lf", &x)
#define     sii(x,y )       scanf("%d%d", &x,&y)
#define     siii(x,y ,z)    scanf("%d%d%d ", &x,&y , &z)
#define     rep(i ,n )      for(int i = 0 ; i < n ; i++ )
#define     repi(i ,n )     for(int i = 1 ; i <= n ; i++ )
#define     forn(i ,x,n )   for(int i = x ; i <= n ; i++ )
#define     ford(i ,x,n )   for(int i = x ; i >= n ; i-- )
#define     repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#define     dbg(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
  
typedef long long ll  ;
typedef unsigned long long  ull ;
typedef vector<int> vi  ;
 
const ll  mod =  1e9+7;
const int  inf = 1e9+7  ;
const long long  infL = 1e18 ;
 
int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int  n,int pos ) { return (bool ) (n&(1<<pos))  ; }
 
template < typename T > T mul(T x, T y   ) { x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template < typename T > T add(T x, T y  ) { x %= mod ; y %= mod ; return (x+y)%mod ;  }
template < typename T > T modPow(T x, T k ,T mod ) { if(k == 0 ) return 1; if(k&1  ) { return ( (x%mod)*modPow(x,k-1, mod )%mod )%mod ; } else { T ret = modPow(x,k/2 , mod ) ; ret %= mod ; return (ret*ret )%mod; } }
template < typename T > T ext_gcd(T num1 , T num2, T &X , T &Y ) { T r2,r1, q2, q1 , x2, x1, y2 ,y1 , x,  y, r   ; x2 = 1; y2 = 0;  x1 = 0; y1 = 1; for( r2 =num1 ,r1 = num2 ;r1 != 0 ; y2 = y1, y1 = y,x2 = x1 ,x1 = x ,r2 = r1, r1 = r) {q1 = r2/r1; x = x2 - q1*x1; y = y2 - q1*y1; r = r2%r1 ; } X = x2 ; Y = y2 ; return r2 ;  }
template < typename T > void print(const T& v) {    cerr << v << ' ' ;}
template < typename T1, typename... T2 > void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
 
template < typename T > 
T  modInv( T x , T m ) {  
    return modPow(x,m-2 , m) ;   
    // long long ret, t ;// 
    // ext_gcd( x, m ,ret ,t  ) ;
    // ret %= m ; if(ret<0) ret += m  ; 
    // return ret;
}
// debuging ...
template<typename T > 
void dbg_a(T a[] ,int n=10 ) {
    rep(i,n )cerr<<a[i]<<' ' ; 
    cerr<< endl; 
}
 
template < typename F,  typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "[ " << p.first << ", " << p.second << " ]";
}
 
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "[ "; rep(i , sz( v)  )  os << v[i] << ' ' ; return os << " ]" ; 
}
 
//int dx[] = {0 , 0 ,+1, -1 } ;
//int dy[] = {-1, +1,0 , 0 };
  
ll modAdd(ll &x ,ll  y) {
    x += y ;
    if(x>= mod ) x-=mod; 
    return x ;
}
const int M = (int )1e6+12 ;  
const int nx  = 2000+ 5  ;
 

////  code from here ...  

int a[M+2] , d= 0 ,n, k    ; 
vector<int>v ; 
void func( ) {
    v.pb(a[0] ) ; 

    for(int i=1;i<n;i++   ) {
        int top= v[sz(v )-1] ;
        if(a[i]>=top ) v.pb(a[i] ) ; 
        else {
            int id ;
            id = upper_bound(all(v) ,a[i] ) -v.begin() ;
            v[id] =  a[i ] ; 
        } 



    } 
    // dbg(sz(v) ) ; 
    // rep(i , sz(v) ) cout<< v[i] << ' ' ;
    // cout<<endl; 
}

void solve() {
    int  x, sum = 0  , cnt =0 , ans= 1e7  ;
    cin >> n; 
    rep(i,n) cin>>a[i] ;
     reverse(a,a+n ) ;
    func() ;
    cout << sz(v) << endl ; 
 
}
    

 
int main() {
  
     ios::sync_with_stdio(false);  cin.tie(0);  
    int t=1 , c= 0 ; // si( t) ; 
    n = 2e5 +5;  
     

    while(t--) {
       // printf("Case %d: ",++c)  ;
        solve();
 
    }   
    return 0 ;

}



 

