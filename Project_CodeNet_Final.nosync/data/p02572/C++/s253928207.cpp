#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
 
using namespace std;
using namespace __gnu_pbds;
 	// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inff (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
#define SPEED ios_base::sync_with_stdio(false) ;cin.tie(NULL) ;cout.tie(NULL) ;
#define fp(i,a,n) for(ll i=n-1; i>a ;i--)
#define deb(x) cout << #x << " ---> " << x << endl;
#define X first
#define Y second
#define pia 3.1415926536
#define mod 1000000007
#define mod2 998244353

#define ml map<ll,ll>
#define mll map<pll,ll>
#define vvl vector<vl>
#define vvi vector<vi>
#define letsh(a,b) a<<b
#define rigsh(a,b) a>>b 
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count()) ;
		bool sortbysec(const pair<int,int> &a, 
		      const pair<int,int> &b) 
		{ 
		    return (a.second < b.second); 
		} 	   
		
		  ll power(ll a,ll n)
		{
		ll ans=1;
		while(n)
		{
		if(n&1) ans=(ans*a)%mod;
		a=(a*a)%mod ;
		n=n>>1;
		 }
		 return ans;
		}
		ll power2(ll a,ll n)
		{
		ll ans =1 ;
		while(n)
		{
			if(n&1) ans =(ans*a) ;
			n =n>>1 ;
			a = (a*a) ;
		  }
		  return ans ;
		}
		ll lcm(ll a, ll b)
		{
		       return a / __gcd(a, b) * b;
		}
#define N 100050
#define M 400060
         vll dir({{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) ;
         bool doOverlap(pll l1, pll r1, pll l2, pll r2) 
{ 
    // If one rectangle is on left side of other 
    if (l1.X>= r2.X || l2.X >= r1.X) 
        return false; 
  
    // If one rectangle is above other 
    if (l1.Y <= r2.Y || l2.Y <= r1.Y) 
        return false; 
  
    return true; 
} 
         void solve()
		 {
		   ll n ;cin>>n ;
		   vl sum(n+4,0) ,a(n+4,0) ;
		   ll ans =0 ;
		   f(i,1,n+1) cin>>a[i] ;
		   fd(i,n,1) sum[i] =(sum[i+1]+a[i])%mod;
		   f(i,1,n) ans =(ans+(a[i])*(sum[i+1]))%mod ;
		   cout<<ans<<endl ;
 		 }
		
		    
		  
		int main() 
	  	{
	    SPEED
	   ll t  =1 ;
	    while(t--) solve() ;
	    
	    }