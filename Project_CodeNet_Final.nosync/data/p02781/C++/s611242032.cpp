#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re register
#define debug printf("Now is Line : %d\n",__LINE__)
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define int long long
#define D double
#define inf 123456789
#define mod 1000000007
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define rep(i , a , b) for(int i = (a) , i##Limit = (b) ; i <= i##Limit ; ++ i)
#define drep(i , b , a) for(int i = (a) , i##Limit = (b) ; i >= i##Limit ; -- i)
#define Next(i, u) for(re int i = head[u]; i; i = e[i].next)
#define mem(k, p) memset(k, p, sizeof(k))
#define lb(x) (x)&(-(x))
#define ls k * 2
#define rs k * 2 + 1
#define maxn 2333
il int Mul(int a, int b) { return 1ll * a * b % mod; }
il int Inc(int a, int b) { return (a += b) >= mod ? a - mod : a; }
il int Dec(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
il int qpow(int a, int b) { int r = 1; while(b) { if(b & 1) r = Mul(r, a); a = Mul(a, a), b >>= 1; } return r; }
int n, m, dp[maxn][4][2];
char c[maxn];
il int dfs(int u, int use, int li) {
	if(use > m) return 0;
	if(u > n) return use == m;
	if(dp[u][use][li] != -1) return dp[u][use][li];
	int p = li == 1 ? c[u] - '0' : 9, ans = 0;
	rep(i, 0, p) ans += dfs(u + 1, use + (i != 0), li && i == p);
	return dp[u][use][li] = ans;
} 
signed main() {
	scanf("%s", c + 1), n = strlen(c + 1), m = read(), mem(dp, -1);
	cout << dfs(1, 0, 1);
	return 0;
}
