/*
把所有有用的点i分为三类：
1、A[i] = B[i] = 1。设这类点为A点，有n个
2、A[i] = 1，B[i] = 0。设这类点为B点，有m个
3、A[i] = 0，B[i] = 1。设这类点为C点，有m个
其中n + m = A[i] = 1的数量 = B[i] = 1的数量
如果有一个swap(Ai，Aj)的操作，那么就连一条i -> j的有向边。观察形成的图，发现如下性质：
1、形成了若干个环，环上的点都是A点
2、形成了m条链，每条链的起点都是一个B点，每条链的终点都是一个C点。链上剩余的点都是A点。显然链长>= 2
3、由1、2可知，Sum{环长} + Sum{链长 - 2} = n
4、目标是使得图中除了每条链的起点外都变成1 
显然每个环和链是独立的。考虑每个环和链中交换的相对顺序
环上可以按照任意顺序交换
链上必须按照从终点走到起点的顺序交换
可以分别对环和链dp。环的dp可以直接优化到线性，链的dp可以用倍增NTT优化 
*/
 
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MOD(998244353);
typedef long long int LL;
 
inline int Mult(const int &a, const int &b)
{
	return (a * 1LL) * b % MOD;
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

constexpr int Add(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}
 
constexpr int Sub(int a, int b)
{
	return a - b < 0 ? a - b + MOD : a - b;
}
 
void exgcd(const int &a, const int &b, int &x, int &y)
{
	if (b == 0)
		x = 1, y = 0;
	else
		exgcd(b, a % b, y, x), y -= x * (a / b);
}
 
inline int inverse(const int &a)
{
	int invx, invy;
	exgcd(a, MOD, invx, invy);
	return (invx % MOD + MOD) % MOD;
}

namespace NTT
{
	const int Max_L(32768 + 5);
	int L, A[Max_L], B[Max_L], W[Max_L];
	void clear()
	{
		for (int i = 0;i <= L - 1;++i)
			A[i] = B[i] = 0;
	}
	void DFT(int *P)
	{
		for (int i = 0, j = 0;i <= L - 1;++i)
		{
			if (j > i)
				swap(P[i], P[j]);
			for (int l = (L >> 1);(j ^= l) < l;l >>= 1)
				;
		}
		for (int l = 2, m = 1, now, z;l <= L;l <<= 1, m <<= 1)
		{
			now = L / l;
			for (int i = 0;i <= L - 1;i += l)
				for (int k = 0, p = 0;k <= m - 1;++k, p += now)
				{
					z = Mult(P[i + m + k], W[p]);
					P[i + m + k] = Sub(P[i + k], z);
					P[i + k] = Add(P[i + k], z);
				}
		}
	}
	void NTT()
	{
		W[0] = 1, W[1] = power(3, (MOD - 1) / L);
		for (int i = 2;i <= L - 1;++i)
			W[i] = Mult(W[i - 1], W[1]);
		DFT(A), DFT(B);
		for (int i = 0;i <= L - 1;++i)
			A[i] = Mult(A[i], B[i]);
		W[1] = inverse(W[1]);
		for (int i = 2;i <= L - 1;++i)
			W[i] = Mult(W[i - 1], W[1]);
		DFT(A);
		int invL(inverse(L));
		for (int i = 0;i <= L - 1;++i)
			A[i] = Mult(A[i], invL);
	}
}

inline void update(int &a, const int &b)
{
	a = Add(a, b);
}

const int Max_L(10050);
int L, N, M, Fac[Max_L], Inv[Max_L], F[Max_L], G[2][Max_L], Ans;
char A[Max_L], B[Max_L];

struct Poly
{
	Poly(const int &_L = 0) : L(_L) {memset(P, 0, sizeof(P));}
	int L, P[Max_L];
	Poly operator*(const Poly &b) const
	{
		Poly c(min(L + b.L, N));
		NTT::clear();
		NTT::L = 1;
		while (NTT::L <= L + b.L)
			NTT::L <<= 1;
		for (int i = 0;i <= L;++i)
			NTT::A[i] = P[i];
		for (int i = 0;i <= b.L;++i)
			NTT::B[i] = b.P[i];
		NTT::NTT();
		for (int i = 0;i <= c.L;++i)
			c.P[i] = NTT::A[i];
		return c;
	}
};
Poly V;

Poly operator^(Poly a, int n)
{
	Poly Ret;
	Ret.P[0] = 1;
	while (n)
	{
		if (n & 1)
			Ret = Ret * a;
		a = a * a, n >>= 1;
	}
	return Ret;
}

inline int C(const int &n, const int &m)
{
	return Mult(Fac[n], Mult(Inv[m], Inv[n - m]));
}
 
int main()
{
	scanf("%s", A + 1), L = strlen(A + 1), scanf("%s", B + 1);
	Fac[0] = 1;
	for (int i = 1;i <= L + 1;++i)
		Fac[i] = Mult(Fac[i - 1], i);
	Inv[L + 1] = inverse(Fac[L + 1]);
	for (int i = L;i >= 0;--i)
		Inv[i] = Mult(Inv[i + 1], i + 1);
	for (int i = 1;i <= L;++i)
		if (A[i] == '1')
			N += (B[i] == '1'), M += (B[i] == '0');
	/*
	F[n] = Sum{C(n - 1, m - 1) * F[n - m] * (m - 1)!   |   1 <= m <= n}
	     = Sum{(n - 1)! / (n - m)! * F[n - m]   |   1 <= m <= n}
	*/
	F[0] = 1;
	for (int n = 1, Sum = 1;n <= N;++n)
	{
		F[n] = Mult(Sum, Fac[n - 1]);
		update(Sum, Mult(F[n], Inv[n]));
	}
	V.L = N;
	for (int x = 0;x <= N;++x)
		V.P[x] = Inv[x + 1];
	V = (V ^ M);
	for (int n = 0;n <= N;++n)
		update(Ans, Mult(V.P[n], Mult(Fac[n], Mult(C(N, n), F[N - n]))));
	printf("%d", Mult(Ans, Mult(Fac[M], Fac[N + M])));
	return 0;
}