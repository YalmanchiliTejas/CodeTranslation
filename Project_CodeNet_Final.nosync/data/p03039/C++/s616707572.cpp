//==========================Head files==========================
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<iostream>
#include<map>
#define LL long long
#define db double
#define mp make_pair
#define pr pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define ms(i, j) memset(i, j, sizeof i)
using namespace std;
//==========================Templates==========================
inline int read() {
    int x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9'){x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
inline LL readl() {
    LL x = 0, f = 1; char c = getchar();
    while(c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9'){x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
int power(int a, int b) {
	int ans = 1;
	while (b) {
		if(b & 1) ans = ans * a;
		b >>= 1; a = a * a;
	}
	return ans;
}
int power_mod(int a, int b, int mod) {
	a %= mod;
	int ans = 1;
	while (b) {
		if(b & 1) ans = (ans * a) % mod;
		b >>= 1, a = (a * a) % mod;
	}
	return ans;
}
LL powerl(LL a, LL b) {
	LL ans = 1ll;
	while (b) {
		if(b & 1ll) ans = ans * a;
		b >>= 1ll;a = a * a;
	}
	return ans;
}
LL power_modl(LL a, LL b, LL mod) {
	a %= mod;
	LL ans = 1ll;
	while (b) {
		if(b & 1ll) ans = (ans * a) % mod;
		b >>= 1ll, a = (a * a) % mod;
	}
	return ans;
}
LL gcdl(LL a, LL b) {return b == 0 ? a : gcdl(b, a % b);}
LL abssl(LL a) {return a > 0 ? a : -a;}
int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
int abss(int a) {return a > 0 ? a : -a;}
//==========================Main body==========================
#define LD "%I64d"
#define D "%d"
#define pt printf
#define sn scanf
#define pty printf("YES\n")
#define ptn printf("NO\n")
//==========================Code here==========================
const LL MO = 1e9 + 7, MAXN = 200000 + 5;
LL n, m, k;
vector<LL > qzh1[MAXN]; // i + j
vector<LL > qzh2[MAXN]; // i - j
LL jc[MAXN], jc_inv[MAXN];
    LL ksm(LL a, LL b) {
        LL ans = 1, bs = a;
        while (b) {
            if (b & 1) ans = (ans * bs) % MO;
            bs = (bs * bs) % MO;
            b >>= 1;
        }
        return ans;
    }
    LL C(LL n, LL m) {
        if (m > n) return 0;
        return jc[n] * jc_inv[m] % MO * jc_inv[n - m] % MO;
    }
LL inc(LL a, LL b) {
	return ((a + b) % MO + MO) % MO;
}
LL mul(LL a, LL b) {
	return a % MO * b % MO;
}
LL get(LL k, LL x, LL y, LL a, LL b) {
	if (x - 1 < 0 || y - 1 < 0) return 0;
	if (x > n || y > m) return 0;
	if (k == 1)
		return inc(inc(inc(qzh1[a][b], -qzh1[x - 1][b]), -qzh1[a][y - 1]), qzh1[x - 1][y - 1]);
	if (k == 2)
		return inc(inc(inc(qzh2[a][b], -qzh2[x - 1][b]), -qzh2[a][y - 1]), qzh2[x - 1][y - 1]);
} 
int main() {
	cin >> n >> m >> k;
	for (LL i = 0; i <= n; ++i) qzh1[i].resize(m + 2), qzh2[i].resize(m + 2);
	jc[0] = 1, jc_inv[0] = 1;
    for (LL i = 1; i <= n * m; ++i) jc[i] = jc[i - 1] * i % MO, jc_inv[i] = ksm(jc[i], MO - 2);
	for (LL i = 1; i <= n; ++i)
	for (LL j = 1; j <= m; ++j) {
		qzh1[i][j] = ((qzh1[i - 1][j] + qzh1[i][j - 1] - qzh1[i - 1][j - 1]) % MO + MO + i + j) % MO;
		qzh2[i][j] = ((qzh2[i - 1][j] + qzh2[i][j - 1] - qzh2[i - 1][j - 1]) % MO + MO + ((i - j) % MO + MO) % MO) % MO;
	}
	LL ans = 0;
	for (LL i = 1; i <= n; ++i)
	for (LL j = 1; j <= m; ++j) {
		LL tmp = 0;
		tmp = inc(tmp, mul(mul(i + j, i), j)); // 左上
		tmp = inc(tmp, -get(1, 1, 1, i, j)); // 左上
		
		tmp = inc(tmp, get(1, i, j, n, m)); // 右下 
		tmp = inc(tmp, -mul(n - i + 1, mul(m - j + 1, i + j))); // 右下 
		
		tmp = inc(tmp, -mul(n - i, mul(j - 1, i - j)));// 左下
		tmp = inc(tmp, get(2, i + 1, 1, n, j - 1));// 左下
		
		tmp = inc(tmp, mul(m - j, mul(i - 1, i - j)));// 右上
		tmp = inc(tmp, -get(2, 1, j + 1, i - 1, m));// 右上
		
		ans = inc(ans, mul(tmp, C(n * m - 2, k - 2)));
	}
	cout << ans * ksm(2, MO - 2) % MO;
	return 0;
}