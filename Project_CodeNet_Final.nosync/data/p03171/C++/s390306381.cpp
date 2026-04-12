#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <time.h>
#include <limits>
#include <math.h>
#include <climits>
#include <numeric>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <functional>
#include<unordered_map>

using namespace std;
const double pi=acos(-1.0);
//memset ( a , 0 , n * sizeof(ll) ) ;

#define 	boost  		ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); // don't use if small inpts
#define 	endl 		'\n'
#define 	sl(n) 		scanf("%lld",&n)
#define		mp 			make_pair
#define 	pb 			push_back
#define 	ppb 		pop_back
#define 	fi 			first
#define 	se 			seconchutd
#define 	ll 			long long
#define     ld 			long double
#define 	ull 		unsigned long long
#define 	pii 		pair<int, int>
#define 	f(i,a,b) 	for(ll i = (ll)(a); i < (ll)(b); i++)
#define 	rf(i,a,b) 	for(ll i = (ll)(a); i > (ll)(b); i--)
#define 	ms(a,b) 	memset((a),(b),sizeof(a))
#define 	max(a,b) 	((a>b)?(a):(b))
#define 	min(a,b) 	((a<b)?(a):(b))
#define 	vec(g1) 	int temp;cin>>temp;g1,push_back(temp);
#define 	abs(x) 		((x<0)?(-(x)):(x))
#define 	MAX 		100005
#define 	inf 		LLONG_MAX
#define 	MIN 		INT_MIN

//typedef
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}// ll fac[200005];
// ll inverse(ll n){return powmod(n, mod-2);}
// ll nCr(ll n, ll r){return (fac[n] * inverse(fac[r]) % mod * inverse(fac[n-r]) % mod) % mod;}

/**.................................................................................................................................*/
ll a[3010],n;
ll dp[3010][3010][2];
ll fun(ll i,ll j,ll k){
	ll ans=0;
	if(dp[i][j][k]!=-1)return dp[i][j][k]; 
	if(i==j){
		if(k)return a[i];
		if(!k) return -a[i];
	}
	if(k){
			ans=max(fun(i+1,j,!k)+a[i],fun(i,j-1,!k)+a[j]);
		return dp[i][j][k]=ans;
	}
	if(!k){
		ans=min(fun(i+1,j,!k)-a[i],fun(i,j-1,!k)-a[j]);
		return dp[i][j][k]=ans;
	}
}

int main() {

  boost;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  ms(dp,-1);
  for(int i=0;i<n;i++){
         dp[i][i][1]= a[i];
         dp[i][i][0]=-a[i];
  }
  	
  fun(0,n-1,1);
   cout<<dp[0][n-1][1]<<endl;
     return 0;
}
