#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <cassert>
#include <time.h>
#include <numeric>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(v) (int)v.size()
#define ll long long int
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fill(a,v) memset(a,v,sizeof(a));
#define all(v) v.begin(),v.end()
#define rep(i, a, b) for(int i = a; i < b; i++)


#define trarr(a,n) forn(i,0,n) cerr<<a[i]<<" \n"[i==n-1];
#define trmat(g,n,m) forn(i,0,n)forn(j,0,m) cerr<<g[i][j]<<" \n"[i==m-1];
#define tr(...) cerr<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.ff<<", "<<p.ss<<')';return out;}
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = acos(-1);
const ld EPS = 1e-9;
const int inf = 1e9+10;
const ll INF = 1e18+10;
const int P = 1e9+7;
const int N = 3e3+10;

void solve(int _t){
	int n;
	cin >> n;
	ll a[n];
	rep(i, 0, n) cin >> a[i];
	ll dp[N][N][2] = {0ll};
	rep(i, 0, n) rep(j, 0, n){
		dp[i][j][0] = 0;
		dp[i][j][1] = INF;
	}
	rep(i, 0, n){
		dp[i][i][0] = a[i];
		dp[i][i][1] = -a[i];
	}
	rep(l, 2, n+1){
		rep(i, 0, n-l+1){
			int j = i+l-1;
			dp[i][j][0] = max({a[i]+dp[i+1][j][1], a[j]+dp[i][j-1][1]});
			dp[i][j][1] = min({dp[i+1][j][0]-a[i], dp[i][j-1][0]-a[j]});
		}
	}
	cout<<dp[0][n-1][0]<<endl;
}	
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	// cin >> t;
	rep(test, 1, t+1){
		solve(test);
	}
	return 0;
}