#include <math.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <functional>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#include <climits>
using namespace std ;
#define ld long double
#define _ ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL);
#define inp(a) for(auto& i : a) cin >> i;
#define out(a) for(auto i : a){cout << i << ' ';}cout << endl;
#define dbg(x) cerr << #x << " is " << x << endl;
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pii pair<int,int>
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
#define LOCAL
//#define int long long
const int N = 2e5+7 ;
const int INF = 1e9 ;
const int MOD = INF + 7 ;
string s ;
vector<vi> g ;
//int res ;
//vector<bool> vis ;
int n , m ;

/* solution 1 complete search
int dfs(int x, int cnt){
	if(cnt == sz(vis)){
		return 1 ;
	}
	int ans = 0 ;
//	vis[x] = true ;
	for(int i : g[x]){
		if(!vis[i]){
			vis[i] = true ; 
			dfs(i,cnt+1) ;
			vis[x] = false ;
		}
	}
	
	return ans ;
}
*/
// solution2 dp 
int dp[9][1<<9] ;

int dfs(int x, int cnt){
	if(dp[x][cnt] >= 0 ) return dp[x][cnt] ;
	if(cnt == (1 << n ) -1) return 1 ; // if all vetex are visited 
	
	int res = 0 ;
	for(int i : g[x]){
		if((cnt >> i) & 1) continue ;
		res += dfs(i, cnt | (1 << i)) ;
	}
	return dp[x][cnt] = res ;
}
int32_t main(){_
//	int n,k,m ;
	cin >> n >> m ;
	g = vector<vector<int> > (n,vector<int>()) ;
//	vis = vector<bool>(n) ;
	
	for(int i = 0 ; i< m ; i++){
		int x , y ;
		cin >> x >> y ;
		x-- ; y-- ;
		g[x].pb(y) ;
		g[y].pb(x) ;
	}
	ms(dp,-1) ;
	cout << dfs(0,1) << endl ;
}



