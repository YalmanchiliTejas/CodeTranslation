#include<bits/stdc++.h>
using namespace std;
#define   vpll   vector<pll >
#define   all(x) x.begin(),x.end()
#define   present(c,x)    ((c).find(x) != (c).end())
#define   dbg(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){
  std::cerr << name << " = " << arg1 << "\n";
}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#define   sz(a)  a.size()
#define   vll vector<int>
#define   pll pair<int,int>
#define   ff  first
#define   ss  second
#define   br  cout<<"\n";
#define   ld  long double
#define   int  long long int
const int  INF = 1e18+7;
const int  MAX = 3001;
const int  MOD = 998244353;


int n , s ;
int A[MAX] , dp[MAX][MAX] ;
int sets ( int r , int sum ){
	if ( !sum ) return ( n - r + 1 ) ;
	if ( r == n  ) return 0 ;
	if ( dp[r][sum] != - 1) return dp[r][sum] ;
	int ans = 0 ;
	ans = sets ( r + 1 , sum ) ;
	if ( sum >= A[r] ){
		ans += sets( r + 1 , sum - A[r] ) ;
		ans %= MOD ;
	}		
	return dp[r][sum] = ans ;
}
void solve(){
    memset ( dp , -1 , sizeof dp ) ;
    cin >> n >> s ;
    for ( int i = 0 ; i < n   ; i++ )
    	cin >> A[i] ;
    int ans = 0 ;
    for ( int r = 0 ; r < n ; r++ )
    	ans += sets ( r , s ) , ans %= MOD ;
    cout << ans ;
}
int32_t main(){
    int t;
    t=1;
    cin.sync_with_stdio(0), cin.tie(0);
    //cin>>t;
    while(t--){
        solve();
        br;
    }
    return 0;
}
 
 
 
 
 
 