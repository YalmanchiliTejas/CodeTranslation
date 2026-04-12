/*------U Have To DO It------*/
/* BY-> RicoProg */
/*        ___ 
           __|__|
          |  |___       */
#include <bits/stdc++.h>
using namespace std;
 
 
//---------------------------------------------------MACROS----------------------------------------------------------
#define ll long long
#define ld long double
#define beg(i ,n) for(ll i=0;i<n;i++)
#define beg1(i ,n) for(ll i=1;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back 
#define mp make_pair
#define nl "\n" 
#define vec(v , n) vector<ll> v(n)
#define all(x) x.begin() , x.end()
#define pii pair<int , int>
#define pll pair<ll , ll>
#define mii map<int , int>
#define mll map<ll , ll>
#define msi map<string , int>
#define mci map<char , int>
#define f1 first
#define f2 second
#define inf 1e18 + 10

//---------------------------------------------------GLOBAL----------------------------------------------------------
const ll MOD = 1e9 + 7 ;
const ll MAX = 1e5 + 7 ;

//---------------------------------------------------FUNCTIONS-------------------------------------------------------

ll dp[3001][3001] , ar[3001] , n ;

void rec(ll s , ll e){
	if(s==e){
		dp[s][e] = ar[s] ;
		return ;
	}
	else if(dp[s][e] != -1){
		return ;
	}
	rec(s+1 , e) ;
	rec(s , e-1) ;
	dp[s][e] = max(ar[s] - dp[s+1][e] , ar[e] - dp[s][e-1]) ;
	return ;
}

void solve(){
	memset(dp , -1 , sizeof(dp)) ;
	scanf("%lld" , &n) ;
	beg(i , n) scanf("%lld" , &ar[i]) ;
	rec(0 , n-1) ;
	printf("%lld" , dp[0][n-1]) ;
}

//---------------------------------------------------DRIVER----------------------------------------------------------
int main()
{
    fast ;
    int t=1 ;
    //cin >> t ;
    while(t--){
        solve() ;
    }
    return 0;
}	