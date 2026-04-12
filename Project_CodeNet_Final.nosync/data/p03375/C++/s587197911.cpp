
#include <cstdio>

using namespace std;
const int Max_N(3050);

int N, MOD, Fac[Max_N], Inv[Max_N], power2[Max_N * Max_N], power2_phi[Max_N * Max_N], S2[Max_N][Max_N], Ans;

inline int Mult(int a, int b)
{
	return a * 1LL * b % MOD;
}

inline int Add(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}

inline int Sub(int a, int b)
{
	return a - b < 0 ? a - b + MOD : a - b;
}

void exgcd(int a, int b, int &x, int &y)
{
	if (b == 0)
		x = 1, y = 0;
	else
		exgcd(b, a % b, y, x), y -= x * (a / b);
}

inline int inverse(int a)
{
	int invx, invy;
	exgcd(a, MOD, invx, invy);
	return (invx % MOD + MOD) % MOD;
}

int power(int a, int n)
{
	int Ret(1);
	while (n)
	{
		if (n & 1)
			Ret = Mult(Ret, a);
		a = Mult(a, a), n >>= 1;
	}
	return Ret;
}

/*
¿¼ÂÇÈÝ³â£¬Ã¶¾ÙÄÄÐ©Ô­ÁÏ±»¼ÓÈëµ½²»³¬¹ýÒ»ÍëÀ­ÃæÖÐÈ¥ÁË
È»ºó°ÑÕâÐ©Ô­ÁÏ·Ö³ÉÈô¸É×é£¬°üÀ¨Ò»¸ö¿ÉÒÔÎª¿ÕµÄÌØÊâ×é±íÊ¾Ã»±»¼ÓÈë£¬³ýÁËÌØÊâ×éµÄÃ¿Ò»×é±»Í¬Ê±¼ÓÈëµ½ÁËÒ»ÍëÀ­ÃæÖÐ
Ans = Sum{(-1)^i * C(N, i) * Sum{(S2(i, j) + S2(i, j + 1) * (j + 1)) * 2^(2^(N - i)) * (2^(N - i))^j   |   0 <= j <= i}   |   0 <= i <= N} 
*/

inline int Com(int n, int m)
{
	return Mult(Fac[n], Mult(Inv[m], Inv[n - m]));
}

int main()
{
	scanf("%d%d", &N, &MOD);
	power2[0] = power2_phi[0] = 1;
	for (int i = 1;i <= N * N;++i)
	{
		power2[i] = Add(power2[i - 1], power2[i - 1]);
		power2_phi[i] = (power2_phi[i - 1] + power2_phi[i - 1]) % (MOD - 1);
	}
	S2[0][0] = 1;
	for (int i = 1;i <= N;++i)
		for (int j = 1;j <= i;++j)
			S2[i][j] = Add(S2[i - 1][j - 1], Mult(S2[i - 1][j], j));
	Fac[0] = 1;
	for (int i = 1;i <= N;++i)
		Fac[i] = Mult(Fac[i - 1], i);
	Inv[N] = inverse(Fac[N]);
	for (int i = N - 1;i >= 0;--i)
		Inv[i] = Mult(Inv[i + 1], i + 1);
	for (int i = 0, Sum;i <= N;++i)
	{
		Sum = 0;
		for (int j = 0, inv2 = inverse(2), pow2 = power(2, power2_phi[N - i]);j <= i;++j)
			Sum = Add(Sum, Mult(Add(S2[i][j], Mult(S2[i][j + 1], j + 1)), Mult(power2[(N - i) * j], pow2)));
		Sum = Mult(Sum, Com(N, i));
		if (i & 1)
			Ans = Sub(Ans, Sum);
		else
			Ans = Add(Ans, Sum);
	}
	printf("%d", Ans);
	return 0;
}