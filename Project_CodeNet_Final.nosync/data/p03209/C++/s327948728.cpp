
/*
*/
#include<bits/stdc++.h> 
#define Pair pair<int, int>
#define MP(x, y) make_pair(x, y)
#define fi first
#define se second
#define int long long 
#define LL long long 
#define rg register 
#define pt(x) printf("%d ", x);
#define Fin(x) {freopen(#x".in","r",stdin);}
#define Fout(x) {freopen(#x".out","w",stdout);}
using namespace std;
const int MAXN = 1e6 + 10, INF = 1e9 + 10, mod = 1e18 + 7;
const double eps = 1e-9;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int N, X, f[MAXN], g[MAXN];
int add(int x, int y) {
	return x + y;
}
main() {
	N = read(); X = read();
    f[0] = 1; g[0] = 1;
    for(int i = 1; i <= N; i++) f[i] = add(f[i - 1] * 2 % mod, 3), g[i] = add(g[i - 1] * 2, 1);// cout << g[i] << endl;
	int ans = 0; 
	for(int i = N; i >= 1; i--) {
		if(X <= f[i] && X >= (f[i - 1] + 2)) {
			if(X == f[i]) {
				cout << ans + g[i]; return 0;
			}
			if(X == f[i - 1] + 2) {
				cout << ans + g[i - 1] + 1; return 0;
			} else {
				ans += g[i - 1] + 1;
				X -= f[i - 1] + 2;
			}
		}
		else X--;
	}
	cout << ans + max((int)0, X > 0 ? (int)1 : (int)0); 
	return 0;
}
/*
2 3
*/