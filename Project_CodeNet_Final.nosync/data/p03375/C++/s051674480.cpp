#include<cctype>
#include<cstdio>
using namespace std;
#define getchar() (SS == TT && (TT = (SS = BB) + fread(BB,1,1 << 15,stdin),TT == SS) ? EOF : *SS++)
char BB[1 << 15],*SS = BB,*TT = BB;
inline int read()
{
	register int x = 0;
	register char ch = getchar();
	for(;!isdigit(ch);ch = getchar());
	for(;isdigit(ch);ch = getchar())
		x = x * 10 + (ch ^ 48);
	return x;
}
inline void print(int x)
{
	char ch = x % 10 + '0';
	if(x > 9)
		print(x / 10);
	putchar(ch);
}

int mod;
inline int add(int a,int b)
{
	a += b;
	return a >= mod ? a - mod : a;
}
inline int qpow(long long a,int b,int p = mod)
{
	register long long ans = 1;
	while(b)
	{
		if(b & 1) ans = ans * a % p;
		a = a * a % p,b >>= 1;
	}
	return ans;
}

const int N = 3010;
int n;
long long s[N][N],c[N][N],ans;

inline void init()
{
	c[0][0] = s[0][0] = 1;
	for(register int i = 1;i <= n + 1;i++)
	{
		c[i][0] = 1;
		for(register int j = 1;j <= i;j++)
			s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % mod,
			c[i][j] = add(c[i - 1][j - 1],c[i - 1][j]);
	}
}

int main()
{
	n = read(),mod = read();
	init();

	for(register int i = 0;i <= n;i++)
	{
		register long long _2 = qpow(2,n - i);

		long long mul = i & 1 ? mod - 1 : 1,res = 0;
		mul = mul * c[n][i] % mod * qpow(2,qpow(2,n - i,mod - 1)) % mod;

		register long long _2j = 1;
		for(register int j = 0;j <= i;j++)
			res = (res + s[i + 1][j + 1] * _2j) % mod,
			_2j = _2j * _2 % mod;

		ans = (ans + res * mul) % mod;
	}
	print(ans);
}