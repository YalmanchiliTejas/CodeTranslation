#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <complex>
#include <functional>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define all(v) v.begin(),v.end()
#define trav(x, v) for(auto &x : v)
#define sz(v) int((v).size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

void fail(){
	puts("Impossible");
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int h, w;
	cin >> h >> w;
	vector<string> ss(h);
	trav(s, ss) cin >> s;
	int cnt = 0;
	trav(s, ss) trav(c, s) cnt += c=='#';
	if(cnt != h+w-1) fail();
	vector<vector<int>> dp(h, vector<int>(w,-1));
	function<bool(int,int)> dfs = [&](int x, int y){
		if(x >= h || y >= w) return 0;
		if(dp[x][y] != -1) return dp[x][y];
		if(ss[x][y]=='.') return dp[x][y] = 0;
		if(x+1==h || y+1==w) return 1;
		return dp[x][y] = dfs(x+1,y)|dfs(x,y+1);
	};
	if(!dfs(0,0)) fail();
	puts("Possible");
}