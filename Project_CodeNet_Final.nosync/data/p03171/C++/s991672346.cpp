#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
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
#define N 200005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcount
#define PI acos(-1)
//#define endl "\n"

const int inf = (int)1e18 + 10;

int a[3003];
int dp[3003][3003];
signed main(){
  fast;
  
 int n , sum = 0;
 cin >> n;
 for(int i = 1 ; i <= n ; i++){
 	cin >> a[i];
 	sum += a[i];
 }

 for(int l = 1 ; l <= n ; l++ ){
 	for(int i = 1 ; i<= n - l + 1 ; i++){
 		if(l == 1) dp[i][i] = a[i];
 		else if(l == 2) dp[i][i+1] = max(a[i] , a[i+1]);
 		else{
 			dp[i][i+l-1] = max(a[i] + min(dp[i+1][i+l-2] , dp[i+2][i+l-1]) ,
 			                      a[i+l-1] + min(dp[i+1][i+l-2] , dp[i][i+l-3]));

 			// cout << i << " "<< (i + l-1) << " " << dp[i][i+l-1]<<endl;
 		}
 	}
 }
 
 
 int ans = dp[1][n]  - (sum - dp[1][n]);
 cout << ans << endl; 

}	