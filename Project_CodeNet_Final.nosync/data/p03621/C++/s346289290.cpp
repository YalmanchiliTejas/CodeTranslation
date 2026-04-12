#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define mod 998244353
#define MAXN 10005 

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

char s1[MAXN],s2[MAXN]; 
int n,f[MAXN][MAXN],fac[MAXN],ifac[MAXN];

int mul (int a,int b){return 1ll * a * b % mod;}
int add (int a,int b){return a + b >= mod ? a + b - mod : a + b;}
int qkpow (int a,int b){int res = 1;for (;b;b >>= 1,a = 1ll * a * a % mod) if (b & 1) res = 1ll * res * a % mod;return res;}
int binom (int a,int b){return 1ll * fac[a] * ifac[b] % mod * ifac[a - b] % mod;}

signed main(){
	scanf ("%s%s",s1 + 1,s2 + 1),n = strlen (s1 + 1);
	fac[0] = 1;for (Int i = 1;i <= n;++ i) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[n] = qkpow (fac[n],mod - 2);for (Int i = n;i;-- i) ifac[i - 1] = 1ll * ifac[i] * i % mod;
	int sum1 = 0,sum2 = 0;//sum1表示可以传递的中间节点个数，sum2表示可以作为链头的个数 
	for (Int i = 1;i <= n;++ i) if (s1[i] == '1' && s2[i] == '1') ++ sum1;else if (s1[i] > s2[i]) ++ sum2;
	f[0][0] = 1;
	for (Int i = 0;i <= sum1;++ i)
		for (Int j = 0,cur;j <= sum2;++ j){
			if (!(cur = f[i][j])) continue;
			f[i + 1][j] = add (f[i + 1][j],mul (cur,mul (i + 1,j)));
			f[i][j + 1] = add (f[i][j + 1],mul (cur,mul (j + 1,j + 1)));
		}
	int ans = 0;
	for (Int i = 0;i <= sum1;++ i) ans = add (ans,mul (binom (sum1 + sum2,i),mul (binom (sum1,i),mul (fac[i],mul (fac[i],f[sum1 - i][sum2])))));
	write (ans),putchar ('\n');
	return 0;
}