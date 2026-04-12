#include  <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define allarr(a) a , a + n
#define ll long long
#define ull unsigned long long 
#define pb push_back
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL); cout.tie(NULL)
typedef pair<int, int> pi;
typedef pair<ll,ll> pll; 
typedef pair<int,pi> trp ;
typedef vector<pi> vpi;
typedef vector<pll> vpll ;
// int ab  (int  x ) { return (x>0?x:-x); }
ll dp[5005][5005][2];
vector<ll> coins ;  
ll solve(int i , int j , bool p ){
	if( i > j )return 0 ; 
	ll& r = dp[i][j][p] ; 
	if( r != -1 )return r; 
	if(p)
	return r = min ( {solve ( i + 1 , j,!p) - coins[i] , solve(i+1,j,!p)-coins[i] , solve(i,j-1,!p)-coins[j] , solve(i,j-1,!p)-coins[j]});
	return r = max ( {solve ( i + 1 , j,!p) + coins[i] , solve(i+1,j,!p)+coins[i] , solve(i,j-1,!p)+coins[j] , solve(i,j-1,!p)+coins[j]}); 
}


int main(){
	int n ; 
	cin >> n ; 
	coins.resize(n); 
	for(ll& a : coins )cin >>  a; 
	memset(dp,-1,sizeof dp); 
	cout << solve(0,n-1,0)<<endl; 
}