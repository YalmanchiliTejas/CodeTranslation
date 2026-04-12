#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 2005;
const int p[10][3] = {{0, 1, 2}, {0, 1, 3}, {0, 1, 4}, {0, 2, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}};
const int q[10][3] = {{3, 4}, {2, 4}, {2, 3}, {1, 4}, {1, 3}, {1, 2}, {0, 4}, {0, 3}, {0, 2}, {0, 1}};

inline void umax(int &x, int y){ x = max(x, y); }

class Upd{
public:
	int x, y, v;
	Upd(int x_, int y_, int v_): x(x_), y(y_), v(v_){}
};

int n, dlt, mx, ans; 
int a[maxn * 3], cmx[maxn];
int dp[maxn][maxn];
vector<Upd> upd;

inline void p2p(int x, int y, int z){
	upd.PB(Upd(x, y, max(mx, dp[z][z] + 1)));
	return;
}

inline void r2r(int x, int z){
	FOR(k, 0, n){
		upd.PB(Upd(k, z, dp[x][k] + 1));
	}
	return;
}

inline void r2p(int z){
	FOR(k, 0, n){
		upd.PB(Upd(k, z, cmx[k]));
	}
	return;
}

inline void update(Upd u){
	int x = u.x, y = u.y, v = u.v;
	int res = max(dp[x][y], v);
	dp[x][y] = dp[y][x] = res;
	umax(cmx[x], res);
	umax(cmx[y], res);
	umax(mx, res);
	return;
}

inline void init(){
	dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0;
	cmx[a[0]] = cmx[a[1]] = mx = 0;
	return;
}

inline void print(){
	FOR(i, 0, n){
		FOR(j, 0, n)
			printf("%d ", dp[i][j] + dlt);
		puts("");
	}
	return;
}

int main(){	
	scanf("%d", &n);
	FOR(i, 0, n * 3)
		scanf("%d", a + i), --a[i];
	
	if(n == 1){
		printf("%d\n", a[0] == a[1] && a[1] == a[2]);
		return 0;
	}	
	
	mx = -0x3f3f3f3f;
	FOR(i, 0, n) FOR(j, 0, n)
		dp[i][j] = -0x3f3f3f3f;
	FOR(i, 0, n)
		cmx[i] = -0x3f3f3f3f;
	init();
	
	REP(i, 0, n - 2){
		
		int x = a[i * 3 + 2], y = a[3 * i + 3], z = a[3 * i + 4];
		if(x == y && y == z){
			++dlt;
			continue;
		}
		upd.clear();
		
		p2p(x, y, z);
		p2p(x, z, y);
		p2p(y, z, x);
		
		if(x == y)
			r2r(x, z);
		if(x == z)
			r2r(x, y);
		if(y == z)
			r2r(y, x);
		r2p(x);
		r2p(y);
		r2p(z);
		
		FOR(j, 0, upd.size()){
			update(upd[j]);
		}
	}
	
	FOR(i, 0, n) FOR(j, 0, n){
		umax(ans, dp[i][j] + dlt + (i == j && i == a[3 * n - 1]));
	}
	
	printf("%d\n", ans);
	return 0;
}
