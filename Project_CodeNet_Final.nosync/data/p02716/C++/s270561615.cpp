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
#include <bitset>
using namespace std ;
#define ld long double
#define int long long
#define ii pair<int,int>
#define FAST_IO ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL); clock_t beg = clock()
#define dbg(x) cerr << #x << " is " << x << endl;
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
const int N = 3e5+7 ;
//const int INF = 1e18 ;
//const int MOD = 1e9 + 7 ;
int dp[N][2] ;

void solve(){
	int n ;
	cin >> n ;
	vi a(n) ;
	for(auto& x : a) cin >> x ;
	dp[2][0] = a[0] ;
	dp[2][1] = a[1] ;
	for(int i = 3 ; i <= n ; i++){
		if(i&1){
			dp[i][1] = a[i-1]+max({dp[i-2][0],dp[i-2][1],dp[i-3][0],dp[i-3][1]})   ;
			dp[i][0] = dp[i-1][1];
		}
		else{
			dp[i][1] = a[i-1]+ max({dp[i-1][0], dp[i-2][0], dp[i-2][1]})  ;
			dp[i][0] = a[i-2]+ dp[i-2][0] ;
		}
	}
	cout << max(dp[n][1], dp[n][0]) ;
}

int32_t main(){
	FAST_IO ;
	int t = 1 ;
//	cin >> t ;
	while(t--){
		solve() ;
	}
    cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
}
