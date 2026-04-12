#include <math.h>
#include <assert.h>
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
#include <array>
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
//const int N = 3e5+7 ;
const int INF = 1e18 ;
//const int MOD = 1e9 + 7 ;

int getLis(vi& a){
	int n = sz(a) ;
	vi dp(n+1,INF) ;
	for(int i = 0 ; i < n ; i++){
		auto it = upper_bound(all(dp),a[i])-dp.begin() ;
		dp[it] = a[i] ;
	}
	return lower_bound(all(dp),INF)-dp.begin() ;
}

void solve(){
	int n ;
	cin >> n ;
	vi a(n) ;
	for(auto& x : a) cin >> x ;
	reverse(all(a)) ;
	cout << getLis(a) ;
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
