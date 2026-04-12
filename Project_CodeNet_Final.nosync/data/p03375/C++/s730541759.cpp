#include <bits/stdc++.h>
using namespace std;
template<class T> void read(T& x)
{
	char c = getchar(); T p = 1, n = 0;
	while(c < '0' || c > '9') {if(c == '-') p = -1; c = getchar();}
	while(c >= '0' && c <= '9'){n = n * 10 + c - '0'; c = getchar();}
	x = p * n;
}
template<class T,class U>void read(T&x,U&y){read(x),read(y);}
template<class T,class U,class V>void read(T&x,U&y,V&z){read(x),read(y),read(z);}
const int maxn = 5e3 + 5;
int C[maxn][maxn], f[maxn][maxn];
int power(int a, int b, int p){int r = 1;for(; b;b >>= 1, a = 1ll * a * a % p)if(b & 1)r = 1ll * r * a % p; return r;}
int main()
{
	int n, m; read(n, m);
	C[0][0] = 1;
	for(int i = 1; i <= n; C[i][0] = 1, ++i) for(int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m;
	f[0][0] = 1;
	for(int i = 1; i <= n; f[i][0] = 1, ++i) for(int j = 1; j <= i; ++j)
		f[i][j] = (f[i - 1][j - 1] + 1ll * f[i - 1][j] * (j + 1) % m) % m;
	int sum = 0;
	for(int i = 0, q = 1; i <= n; ++i, q = m - q)
	{
		int ret = 0, p = power(2, n - i, m);
		for(int j = 0; j <= i; ++j)
			(ret += 1ll * f[i][j] * power(p, j, m) % m) %= m;
		ret = 1ll * ret * power(2, power(2, n - i, m - 1), m) % m;
		ret = 1ll * ret * C[n][i] % m;
		ret = 1ll * ret * q % m;
		(sum += ret) %= m;
	}
	printf("%d\n", sum);
	return 0;
}