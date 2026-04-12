#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define REP(i, s, e) for ( int i = s; i <= e; i++ )  

string b;
string p[4] = {"0xxxxxxx","110yyyyx10xxxxxx","1110yyyy10yxxxxx10xxxxxx","11110yyy10yyxxxx10xxxxxx10xxxxxx"};

int dp[8010][4][33][2];
int dfs(int x,int pat,int pos,int done){
	int &res = dp[x][pat][pos][done];
	if( res != -1 ) return res;
	int ans = 0;
	if( pos == p[pat].size() ){
		if( !done ) return 0;
		if( x == b.size() ) return 1;
		ans += dfs(x,0,0,1);
		ans += dfs(x,1,0,0);
		ans += dfs(x,2,0,0);
		ans += dfs(x,3,0,0);
		ans %= 1000000;
		return ans;
	}
	if( x == b.size() ) return 0;
	for(int num = '0' ; num <= '1' ; num++){
		if( b[x] != 'x' && b[x] != num ) continue;
		int nextDone = done;
		if( p[pat][pos] == 'y' && num == '1' ) nextDone = 1;
		if( p[pat][pos] != 'x' && p[pat][pos] != 'y' && p[pat][pos] != num ) continue;
		ans += dfs(x+1,pat,pos+1,nextDone);
	}
	ans %= 1000000;
	return res = ans;
}
int main(){
	int N;
	while(cin >> N && N){
		memset(dp,-1,sizeof(dp));
		b = "";
		for(int i = 0 ; i < N ; i++){
			string s;
			cin >> s;
			b += s;
		}
		int ans = 0;
		ans += dfs(0,0,0,1);
		ans += dfs(0,1,0,0);
		ans += dfs(0,2,0,0);
		ans += dfs(0,3,0,0);
		ans %= 1000000;
		cout << ans << endl;
	}
	
}