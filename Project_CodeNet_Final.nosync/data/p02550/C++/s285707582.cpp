#include <bits/stdc++.h>
#define rei register int
#define int long long
using namespace std;
const int maxn = 100010;
int n,m,x;
int f[maxn][40],s[maxn][40];
signed main(){
	cin >> n >> x >> m;
	for(rei i = 0;i <= m - 1;++i)
	f[i][0] = 1ll*i * i % m,s[i][0] = f[i][0];
	for(rei j = 1;j <= 39;++j)
	 for(rei i = 1;i <= m - 1;++i)
	f[i][j] = f[f[i][j - 1]][j - 1],s[i][j] = s[f[i][j - 1]][j - 1] + s[i][j - 1];
	int ans(0),now(x); --n;
	for(rei i = 39;i >= 0;--i) if(((long long)1 << (long long)i) <= n){
		n -= ((long long)1 << (long long)i);
		ans += s[now][i],now = f[now][i];
	} ans += x; cout << ans << endl; return 0;
}