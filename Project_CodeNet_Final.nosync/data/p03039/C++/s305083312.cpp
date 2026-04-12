#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
// #define double long double
//#define slld(t) scanf("%lld",&t)
//#define sd(t) scanf("%d",&t)
//#define pd(t) printf("%d\n",t)
//#define plld(t) printf("%lld\n",t)
#define vec vector < int >
#define vecp vector < pair < int , int > >
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define pii pair < int , int >
#define pll pair < ll , ll > 
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define mod  1000000007
#define N   200005
#define MAX 300005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcountll
#define PI acos(-1)
//#define endl "\n"
#define inf 1e+15
int fact[N];
int powmod(int x , int y){
	int res = 1;
	while(y>0){
		if(y&1)
			res = (res*x)%mod;
		x=(x*x)%mod;
		y/=2;
	}
	return res;
}
int get(int x , int y){
	   int res = 1;
	   res  = fact[x];
	   res  *= powmod(fact[y] , mod-2) % mod;
	   res %= mod;
	   res  *= powmod(fact[x-y] , mod-2)%mod;
	   res %= mod;
	   return res;
}
signed main(){
  fast;
  int n , m , k , ans = 0;
  cin>>n>>m>>k;
  fact[0] = 1;
  for(int i=1;i<= n*m ; i++)
  	fact[i] = (fact[i-1] * i) % mod;
  for(int i=0;i<= m;i++)  ans += (((m-i)*n*n % mod )*i) % mod , ans%= mod;
  for(int i=0;i<= n;i++)  ans += (((n-i)*m*m % mod)*i)%mod ,  ans %= mod;

  ans = (ans * get(n*m -2 , k-2)) %mod;
  cout << ans << endl;

}
  
