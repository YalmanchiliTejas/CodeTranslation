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
int len, n, a[100000 + 5], b[100000 + 5];
int main() {
	scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] = -a[i];
        b[1] = a[1], len = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i] >= b[len]) b[++len] = a[i];
            else {
                int p = upper_bound(b + 1, b + 1 + len, a[i]) - b; // ×¢Òâ upper_bound
                b[p] = a[i];
            }
        }
        printf("%d\n", len);
	return 0;
}