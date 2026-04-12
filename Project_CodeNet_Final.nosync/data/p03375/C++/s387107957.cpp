#include<bits/stdc++.h>
#define For(i,l,r) for(int i = (l),i##end = (r);i <= i##end;i++)
#define Fordown(i,r,l) for(int i = (r),i##end = (l);i >= i##end;i--)
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;

template <typename T> inline bool chkmin(T &x,T y) { return y < x ? x = y,1 : 0; }
template <typename T> inline bool chkmax(T &x,T y) { return x < y ? x = y,1 : 0; }

const int INF = 0x3f3f3f3f;
const int N = 3e3 + 10;

int S[N][N],Sum[N],fac[N],inv[N];

inline int read() {
	int x = 0,flag = 1;
	char ch = getchar();
	while(!isdigit(ch) && ch != '-')ch = getchar();
	if(ch == '-')flag = -1,ch = getchar();
	while(isdigit(ch))x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * flag;
}

inline int fpm(int a,int b,int mod) {
	int res = 1;
	while(b) {
		if(b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod,b /= 2;
	}
	return res;
}

inline void init(int n,int mod) {
	fac[0] = 1;
	For(i,1,n) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = fpm(fac[n],mod - 2,mod);
	Fordown(i,n,1) inv[i - 1] = 1ll * inv[i] * i % mod;
}

inline int C(int n,int m,int mod) {
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {

	int n = read(),mod = read();
	init(n + 5,mod);
	S[0][0] = 1;
	For(i,1,n + 5) For(j,1,i + 5)
		S[i][j] = (S[i - 1][j - 1] + 1ll * S[i - 1][j] * j) % mod;
	int ans = 0;
	For(i,0,n) {
		int tot = 0,Prod = 1,val = fpm(2,n - i,mod);
		int Others = fpm(2,fpm(2,n - i,mod - 1),mod);
		For(j,0,i) {
			tot = (tot + 1ll * Prod * S[i + 1][j + 1]) % mod;
			Prod = 1ll * Prod * val % mod;
		}
		tot = 1ll * C(n,i,mod) * tot % mod * Others % mod;
		ans = (ans + (i & 1 ? -tot : tot)) % mod;
	}

	printf("%d\n",(ans + mod) % mod);

	return 0;
}