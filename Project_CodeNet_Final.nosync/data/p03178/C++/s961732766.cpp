// verified : https://atcoder.jp/contests/dp/tasks/dp_s
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
const int N = 1e4+7 ;
//const int INF = 1e18 ;
const int MOD = 1e9 + 7 ;

string a , b ; // range inclusive [a,b] && (a < b)
int len ;
int d ;
int dp[N][101][2][2] ;

void pre(){
	len = sz(b) ;
	reverse(all(a)) ;
	while(sz(a)<sz(b)) a.pb('0') ;
	reverse(all(a)) ;
	ms(dp,-1) ;
	// do other stuff if required 
}

int go(int idx, int val, int lo, int hi){
	if(idx == len){
		return val == 0 ;
	}
	int& ans = dp[idx][val][lo][hi] ;
	if(~ans) return ans ;
	ans = 0 ;
	int l = a[idx]-'0' ;
	int r = b[idx]-'0' ;
	if(lo == 0) l = 0 ;
	if(hi == 0) r = 9 ;
	for(int i = l ; i <= r ; i++){
		int newlo = lo , newhi = hi ;
		if(i != l) newlo = 0 ;
		if(i != r) newhi = 0 ;
		// do dp here 
		ans = ans+go(idx+1,(val+i)%d, newlo, newhi)%MOD ;
	}
	return ans%MOD ;
}

void solve(){
	cin >> b >> d ;
	a = "1" ;
	pre() ;
	cout << go(0,0,1,1) ;

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
