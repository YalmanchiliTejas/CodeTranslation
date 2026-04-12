#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstdlib>
#include <numeric>
#include <cstdbool>
#include <map> 
#include<set>
#include<queue>

typedef long long ll;


#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1000000000000000;
const ll inf = -1e18;
typedef pair<int, int> P;
ll ma = 1000000000 + 7;
ll h, w, n,k,m; string s,t;
char maze[60][60];
int dis[101][101];
int nm[8][8];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int gcd(int x, int y) {
	if (x % y == 0) return y;
	return gcd(y, x % y);

}
int dfs(int v,int N,int vis[8]) {
	bool avis = true;
	rep(i,N) {
		if (vis[i] == false) {
			avis = false;
		}
	}
	if (avis) {
		return 1;
	}
	int ret = 0;
	rep(i,N) {
		if (nm[v][i] == 0) continue;
		if(vis[i]) continue;
		vis[i] = true;
		ret += dfs(i,N,vis);
		vis[i] = false;
	}
	return ret;
}
int main() {
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		nm[a-1][b-1]++;
		nm[b-1][a-1]++;
	}
	int vis[8];
	rep(i,n) {
		vis[i] = false;
	}
	vis[0] = true;
	cout << dfs(0,n,vis) << endl;
}


