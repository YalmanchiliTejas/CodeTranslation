#include<bits/stdc++.h>
#define int long long
#define il inline 
#define rep(i, l, r) for(register int i = l; i <= r; ++ i)
using namespace std;
const int maxn = 2333, mod = 1000000007;
inline int read()
{
	register char cc = getchar(); register int cn(0), flus(1);
	while(cc < '0' || cc > '9') {if(cc == '-') flus = - flus; cc = getchar();}
	while(cc >= '0' && cc <= '9') {cn = cn * 10 + cc - '0'; cc = getchar();}
	return cn * flus;
}
string s,t,p;
il int Mul(int a, int b) { return 1ll * a * b % mod; }
il int Inc(int a, int b) { return (a += b) >= mod ? a - mod : a; }
il int Dec(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
il int qpow(int a, int b) { int r = 1; while(b) { if(b & 1) r = Mul(r, a); a = Mul(a, a), b >>= 1; } return r; }
int n, m, dp[maxn][4][2];
char c[maxn];
il int dfs(int u, int use, int li) 
{
	if(use > m) return 0;
	if(u > n) return use == m;
	if(dp[u][use][li] != -1) return dp[u][use][li];
	int p = li == 1 ? c[u] - '0' : 9, ans = 0;
	rep(i, 0, p) ans += dfs(u + 1, use + (i != 0), li && i == p);
	return dp[u][use][li] = ans;
} 
signed main() 
{
	scanf("%s", c + 1), n = strlen(c + 1), m = read(), memset(dp, -1, sizeof(dp));
	cout << dfs(1, 0, 1);
	return 0;
}
