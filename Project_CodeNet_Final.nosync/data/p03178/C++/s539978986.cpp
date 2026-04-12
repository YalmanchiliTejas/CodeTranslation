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
const int N = 1e4+5 ; 
const ll mod = 1e9+7 ; 
ll dp[N][105][2]; 
int n , D; 
string s; 
ll solve(int i, int rem , int b){
	if(i==n){
		if( !rem )
		return 1;
		return 0 ; 
	} 
	ll& r = dp[i][rem][b] ;
	if( r != - 1 )return r ;
	r = 0 ; 
	int digit = s[i]-'0' ; 
	if( b == 1 ){
		r += solve(i+1,(rem+digit)%D,1) ; 
		r%=mod ; 
		for(int x = 0 ; x < digit ; x++ ){
			r += solve(i+1,(rem+x)%D,0) ;
			r%=mod ;  
		}
	}else {
		for(int x = 0 ; x <= 9 ; x++ ){
			r += solve(i+1,(rem+x)%D,0) ; 
			r %= mod ; 
		}
	}
	return r ; 
}
int main(){ 
	cin >> s >> D ; 
	n = s.length() ; 
	dp[0][0][1]=1; 
	for(int i = 0 ; i < n ; i++ ){
			for(int r = 0 ; r < D ; r++ ){
				int digit = s[i]-'0' ; 
				dp[i+1][(r+digit)%D][1] += dp[i][r][1] ; 
				dp[i+1][(r+digit)%D][1] %= mod ; 
				for(int x =0 ; x < digit ; x++ )dp[i+1][(x+r)%D][0] += dp[i][r][1] , dp[i+1][(x+r)%D][0]%=mod; 
				for(int x = 0 ; x <= 9 ; x++ )dp[i+1][(x+r)%D][0]  += dp[i][r][0],dp[i+1][(x+r)%D][0]%=mod; 
		}
	}cout << (dp[n][0][0]-1+dp[n][0][1]+mod)%mod << endl; 
}