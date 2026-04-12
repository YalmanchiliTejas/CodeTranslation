#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ff              first
#define ss              second
#define pb(x)           push_back(x)
#define mp              make_pair
#define sz(x)           (int)x.size()
#define mem(x ,y)       memset(x , y , sizeof x )
#define all(a )         a.begin() , a.end()
#define endl            "\n"
#define pii             pair<int,int> 
#define clr(x)          x.clear()
#define sl(x )          scanf("%I64d" ,&x)
#define si(x )          scanf("%d" ,&x)
#define forn(i ,x,n )   for(int i = x ; i <= n ; i++ )
#define ford(i ,x,n )   for(int i = x ; i >= n ; i-- )
#define rep(i,n )       for(int i= 0; i<n ; i++ ) 
#define repi(i,n )      for(int i= 1; i<=n ; i++ ) 
#define repit(i, c)     for( __typeof((c).begin()) i = (c).begin(); i != (c).end();++i )
#define dbg(args...)    do {   cerr << #args << ' ' ;  print(args); } while(0); cerr<< endl ;
typedef long long ll  ;
ll mod =  1e9+7, mod2 = 998244353 ; 
typedef unsigned long long  ull ;
int setbit(int n, int pos  ) { return n = n|(1<< pos) ; }
int resetbit(int n,int pos ) {  return n =  n & ~(1<<pos ); }
bool checkbit(int  n,int pos ) { return (bool ) (n&(1<<pos))  ; }
template<typename T> void print(const T& v) {    cerr << v << ' ' ;}
template<typename T>T add(T x, T y, T mod = mod ){ x%= mod ;  y%= mod ;   return (x+y)%mod ;  }
template<typename T>T sub(T x, T y, T mod = mod ){ return ((x-y)%mod+mod )%mod;  }
template<typename T>T mul(T x, T y, T mod = mod ){ x %= mod ; y %= mod ; return (x*y)%mod  ;  }
template<typename T1,typename... T2> void print( const T1& first, const T2&... rest ){ print(first); print(rest...) ;}
template<typename T> void dbg_a(T a[] ,int n=10 ) {cerr << "[ "; for(int i=0;i <= n ; i++ )cerr<<a[i]<<' ' ; cerr<< " ]" <<  endl; } 
template<typename F,typename S>ostream& operator<<( ostream& os, const pair< F, S > & p ){return os << "[ " << p.first << ", " << p.second << " ]";}
template<typename T>ostream &operator<<(ostream & os, const vector< T > &v ){os << "[ "; for(int i=0; i<sz(v) ; i++ )  os << v[i] << ' ' ; return os << " ]\n" ; } 
template<typename T>ostream &operator<<(ostream & os,const map< T ,T> &Map ){os << "[ "; repit(it , Map ) os << "[" <<(*it).ff << ' ' << (*it).ss << "] "    ; return os << "]\n" ; } 
template<typename T>ostream &operator<<(ostream & os, const set< T > &Set  ){os << "[ "; repit(it , Set ) os <<  *it  << ' ' ; return os << " ]\n" ; }  
template<typename T>ostream &operator<<(ostream & os, const multiset< T > &Set) {os << "[ "; repit(it , Set )os <<  *it  << ' ' ; return os << " ]\n" ; }  
template<class T> string to_str(T t){stringstream ss; ss<<t; return ss.str();} 
// typedef tree<  int    ,     // change type 
//               null_type, 
//               less_equal  < int  >  ,  // change type ..    
//               rb_tree_tag,
//               tree_order_statistics_node_update> ordered_set;
template < typename T > 
#define  int  ll   
T  bigmod(T x, T k ,T mod = mod) {
    if(k == 0 ) return (T)1; 
    if(k&1  ) { 
        return ( (x%mod)*bigmod(x,k-1, mod )%mod )%mod ; 
    } else { 
        T ret = bigmod(x,k/2  , mod ) ; 
        ret %= mod ;             
        return (ret*ret )%mod; 
    } 
}
template < typename T > 
T  invmod( T x , T m) {  
    return bigmod(x,m-2 , m) ;   

}  


const ll inf  =    1e18 ; //  0xc0  ; //0x3f ; // 
const int maxn  = (int) 1e6 + 123 ;
//////////////////////////////////////////////

int a[maxn ]  ,res[maxn ];  
int dp[3005][ 3005]  ,s  ; 

int func(int id ,int sum )  {   
    // if( sum==0) return 1 ;  

    if(sum==0)  return  id+1  ;  
    if(id<1)  return   sum == 0 ;   
    if(sum<0) return 0 ; 
    int &ans = dp[id][sum]  ; 

    if(ans !=-1 ) return ans ; 
    ans =  0  ;
    
    ans =  add( ans , func(id-1 ,  sum-a[id] )  ) ;  //  start  new .. 
    ans =  add(ans ,  func(id-1  , sum  ) ) ; 


    return  ans  ; 




}
void solve() { 
    int x,y,z, ans=0 , q, k   , n     ;

    cin >> n >>s  ; 
    forn(i,1 , n)  cin >> a[i]  ; 
     
    swap( mod, mod2 ) ; 
    mem(dp,-1)  ;
    ans =0 ; 

    forn(i,1,n)  {
        res[i] =  func(i-1,s-a[i] )  ;
        ans =  add(ans , mul( res[i]  , n-i+1   ) )  ;

   
    }   
    cout << ans << endl ; 






}           
signed main() {         
      
    ios :: sync_with_stdio(false);  cin.tie(0);   cout.tie(0) ;     
        // clock_t st = clock()  ; cout << fixed << setprecision(12) ;
    int  c = 0 ,t = 1 ; 

    // cin>>t  ; 
    while(t--) {
        solve() ;  
    }
    // cerr << "Execution time : " << (double  )  (clock()-st )/CLOCKS_PER_SEC << endl ;
    // 12m424476 _)___ /// 20/3 // 5  

    return 0 ;    
}       





 