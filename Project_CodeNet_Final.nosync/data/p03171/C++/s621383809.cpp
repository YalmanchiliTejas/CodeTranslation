#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define fast ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL)
#define F(i,a,b) for(int i= (int)(a); i<=(int)(b);i++)
#define RF(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define what_is(x) cerr << #x << " is " << x << endl;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define pii pair<int,int>
#define vii vector<int,int>
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
ll a[3001] ;
ll dp[3001][3001] ;

ll fun(int s,int e){
	if(s>e) return 0 ;
	if(s==e) return a[s] ;
	if(dp[s][e] != -1)
	return dp[s][e] ;
//	dp[s][e] = max(min(fun(s-1,e-1)+a[s]-a[e],fun(s-2,e)+a[s]-a[s-1]), min(fun(s-1,e-1)+a[e]-a[s],fun(s,e-2)+a[e]-a[e-1])) ; 
	ll x =min(fun(s+1,e-1)+a[s]-a[e], fun(s+2,e)+a[s]-a[s+1]);
	ll y =min(fun(s+1,e-1)+a[e]-a[s], fun(s,e-2)+a[e]-a[e-1]);
	dp[s][e]=max(x,y);
	return dp[s][e] ;
}

int main(){
	fast ;
	int N ;
	cin >> N ;
	F(i,1,N) cin >> a[i] ;
	ms(dp,-1) ;
	cout << fun(1,N) << endl ;

}
