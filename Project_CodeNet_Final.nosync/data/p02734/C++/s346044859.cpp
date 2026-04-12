#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp(a, b) make_pair(a, b)
#define ls (rt << 1)
#define rs (rt << 1 | 1) 
typedef pair<int, int> pii; 
const int mod = 998244353;
template <class T> T lowbit(T x){return ((x)&(-(x)));}
const int maxn = 3000 + 10;
int t, n, a[maxn], f[maxn][maxn], s, ans;
int main()
{
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= s; ++j)
		{
			f[i][j] = f[i - 1][j];
			if(j == a[i]) f[i][j] = (f[i][j] + i) % mod;
			if(j > a[i]) f[i][j] = (f[i][j] + f[i - 1][j - a[i]]) % mod;
			if(j == s) ans = (ans + f[i][j]) % mod;
		}
	printf("%d\n", ans);
	return 0;
}