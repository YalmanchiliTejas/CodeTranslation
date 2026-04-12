// first second push_back unordered return continue break vector visited check flag bool while iterator begin end lower_bound upper_bound temp true false ll_MAX ll_MIN insert erase clear pop push compare ll64_MAX ll64_MIN  reverse replace stringstream string::npos length substr front
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
const ll mod = 1e9 + 7 ;
const ll inf =
 1e9 + 5 ;
 //1e18L + 5;
const ll nax = 2e5 + 5;
void min_self(ll&a , ll b){a=min(a,b);}
void max_self(ll&a , ll b){a=max(a,b);}
void add_self(ll& a , ll b){a =  (a + b)%mod;}
//#define (x)  get<0>(x) 
//#define (x)  get<1>(x)
//#define (x)  get<2>(x)
signed main(){
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll n  ;cin>> n; 
vector<ll>arr(n);
for(auto &i:arr)cin>>i;

ll i = 0 , j = n -1  ;
ll ans = 0 ;
vector<vector<ll>>dp(n,vector<ll>(n));

for(ll i = n ; i>=0 ; i--){
	for(ll j = i ;j<n; j++){
		if(i==j)dp[i][j] = arr[i];
		else 
		dp[i][j] = max(arr[i] - dp[i+1][j] , arr[j] - dp[i][j-1]);
	}
}
cout<<dp[0][n-1];
	
}