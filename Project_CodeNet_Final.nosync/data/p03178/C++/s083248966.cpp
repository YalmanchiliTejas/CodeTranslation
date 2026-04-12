#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
// #define int ll
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
#define N 102
#define MAX 200005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcount
#define PI acos(-1)
//#define endl "\n"

const ll inf = (ll)1e18 + 10;
int l;
vec v;
int dp[102][10004][2] ;
int d;
int digitdp(int sum , int k , int t){
	int res = 0;
	if(k == l && sum % d == 0)
		return 1;
	else if(k == l && sum% d != 0)
		return 0;
	if(dp[sum][k][t] != -1)
		return dp[sum][k][t];
    int mx = (t == 1) ? v[k] : 9;
	for(int i = 0 ; i <= mx ; i++){
         int dt = (i == v[k]) ? t : 0;
         res += digitdp((sum + i) % d , k + 1 , dt);
         res %= mod;
	}

	dp[sum][k][t] = res;


	return dp[sum][k][t];

}
signed main(){
  fast;
   string s;
  cin >> s;
  l = s.length();
  for(int i = 0 ; i < s.length() ; i++){
  	int x = (int )s[i]  - '0';
  	v.pb(x);
  }
  
  memset(dp , -1 , sizeof(dp));
  cin >> d;

  int ans = digitdp(0 , 0 , 1) - 1 + mod;
  ans %= mod;
  
  cout << ans << endl;


}	