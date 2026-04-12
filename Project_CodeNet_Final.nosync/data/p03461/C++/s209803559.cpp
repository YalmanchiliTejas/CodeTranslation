#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}


using namespace std;

int d[15][15];
int N;
int g[305][305];
VI vy, vx;

int check[15][15];

int main () {
	make2(A, B);
	FOR(i,0,A) FOR(j,0,B) {
		make(x); d[i+1][j+1] = x;
	}
	vector<pair<PII, int > > v;
	FOR(a,0,101) FOR(b,0,101) {
		int c = -1000;
		FOR(x,1,A+1) FOR(y,1,B+1) {
			c = max(c, d[x][y]-a*x-b*y);
		}
		if (c < 0) continue;
		v.pb(mp(mp(a,b),c));
	}
	N = 2;
	FOR(i,0,305) FOR(j,0,305) g[i][j] = -3;
	int maxa = 0;
	int maxb = 0;
	FORE(i, v) maxa = max(maxa, i->st.st);
	FORE(i, v) maxb = max(maxb, i->st.nd);
	int S = 0; vx.pb(S);
	int T = 1; vy.pb(T);
	int act = 2;
	FOR(i,0,maxa) {
		g[vx.back()][act] = -1;
		vx.pb(act); 
		act++;
	}
	FOR(i,0,maxb) {
		g[act][vy.back()] = -2;
		vy.pb(act); 
		act++;
	}
	bool ok = true;
	FORE(i,v) {
		int a = i->st.st;
		int b = i->st.nd;
		int c = i->nd;
		g[vx[a]][vy[b]] = c;
		FOR(ii,1,A+1) FOR(jj,1,B+1) {
			if (ii*a +jj*b + c == d[ii][jj]) check[ii][jj] = 1; 
			if (ii*a +jj*b + c < d[ii][jj]) ok = false;
		}
	}
	FOR(i,1,A+1) FOR(j,1,B+1) {
		if (check[i][j] != 1 || !ok) {
			printf("Impossible\n");
			return 0;
		}
	}
	printf("Possible\n");
	int m = 0;
	FOR(i,0,act) FOR(j,0,act) {
		if (g[i][j] != -3) m++;
	}
	printf("%d %d\n", act, m);
	FOR(i,0,act) FOR(j,0,act) {
		if (g[i][j] == -1) {
			printf("%d %d X\n", i+1, j+1);
		}
		else if (g[i][j] == -2) {
			printf("%d %d Y\n", i+1, j+1);
		} else if (g[i][j] >= 0) {
			printf("%d %d %d\n", i+1, j+1, g[i][j]);
		}
	}
	printf("1 2\n");
}