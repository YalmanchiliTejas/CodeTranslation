#include <bits/stdc++.h> 
using namespace std;

#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 

#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;
typedef unsigned long long ull;

/////////////////////////////////

int const MAX = 3e3 + 41;

int n, MOD;
int C[MAX][MAX];

int add(int a, int b) {
	a += b;
	while (a < 0) a += MOD;
	while (a >= MOD) a -= MOD;
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int bp(int x, ll d) {
	int res = 1;
	while (d) {
		if (d & 1) res = mult(res, x);
		x = mult(x, x);
		d >>= 1;
	}	
	return res;
}

int bp1(int x, ll d) {
	int res = 1;
	while (d) {
		if (d & 1) res = (ll) res * x % (MOD - 1);
		x = (ll) x * x % (MOD - 1);
		d >>= 1;
	}	
	return res;
}


int g[MAX][MAX];
int f[MAX];

void init() {
	fi(0, MAX - 1) {
		C[i][0] = 1;
		fj(1, i) {
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	g[0][0] = 1;
	fi(1, MAX - 1) {
		fj(0, MAX - 1) {
			g[i][j] = add(g[i][j], g[i - 1][j]);
			g[i][j] = add(g[i][j], mult(j, g[i - 1][j]));
			if (j) {
				g[i][j] = add(g[i][j], g[i - 1][j - 1]);				
			}
		}
	}
	fi(0, n) {
		int v1 = bp(2, bp1(2, n - i));
		fj(0, i) {
			int v2 = bp(2, (n - i) * j);
			int v3 = g[i][j];
			int v = mult(v1, mult(v2, v3));
			f[i] = add(f[i], v);
		}
	}
}

int ans;

void solve() {
	int s = 1;
	fi(0, n) {		
		ans = add(ans, mult(s, mult(C[n][i], f[i])));
		s = -s;	
	}
	printf("%d\n", ans);
	//
	fi(0, n) {
		err("i = %d f = %d\n", i, f[i]);
	}
	//
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d %d", &n, &MOD);
	init();	  
	solve();		

	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}