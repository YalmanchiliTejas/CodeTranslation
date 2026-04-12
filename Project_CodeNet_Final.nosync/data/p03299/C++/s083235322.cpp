/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 105;

int n;
int a[maxn];
int f[maxn][maxn], g[maxn][maxn];

inline int mul(int x, int y){return (1ll * x * y) % INF;}
inline int add(int x, int y){return (x + y) % INF;}
inline int sub(int x, int y){return (x - y + INF) % INF;}

inline int qpow(int x, int y){
	int ret = 1;
	for(; y; y >>= 1){
		if(y & 1)
			ret = mul(ret, x);
		x = mul(x, x);
	}
	return ret;
}

void solve(int l, int r){
	int mn = INF, ept = 0;
	f[l][r] = g[l][r] = 1;
	REP(i, l, r){
		mn = min(mn, a[i]);
	}
	REP(i, l, r){
		a[i] -= mn;
		if(!a[i]) ++ept;
	}
	for(int i = l; i <= r; ){
		if(a[i]){
			int j;
			for(j = i; a[j]; ++j);
			solve(i, j - 1);
			f[l][r] = mul(f[l][r], add(f[i][j - 1], g[i][j - 1]));
			g[l][r] = mul(g[l][r], g[i][j - 1]);
			i = j + 1;
		}
		else ++i;
	}
	g[l][r] = mul(g[l][r], 2);
	f[l][r] = mul(f[l][r], qpow(2, ept));
	f[l][r] = sub(f[l][r], g[l][r]);
	g[l][r] = mul(g[l][r], qpow(2, mn - 1));
	f[l][r] = add(f[l][r], g[l][r]);
	//printf("l = %d r = %d f = %d g = %d\n", l, r, f[l][r], g[l][r]);
	return;
}

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%d", a + i);
	}
	solve(0, n - 1);
	printf("%d\n", f[0][n - 1]);
	return 0;
}

