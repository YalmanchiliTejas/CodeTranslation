
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long int LL;
const int MOD(998244353);

inline void update(int &a, const int &b)
{
	((a += b) >= MOD) ? (a -= MOD) : 0;
}

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

//F[i][j]表示i行j列的答案，且要求每一行都非空，Ans = Sum{C(N, i) * F[i][M]}
//按照列dp。从第j列转移到第j + 1列的时候，考虑新出现了k行，满足它们在j + 1列第一次出现。这样dp可以保证A不同 
//k = 0时，若第j列为空，方案数为1；若非空，只与第j列最上面一行和最下面一行有关，方案数为C(i + 1, 2)
//k > 0时，方案数即1 <= x0 <= x1 < x2 < ... < xk <= xk+1 <= i + k的解数，差分一下可以求出解数为C(i + k + 2, k + 2)
//NTT优化dp即可

namespace NTT
{
	const int Max_L(16384 + 5);
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
		int z;
		for (int l = 2, m = 1;l <= L;l <<= 1, m <<= 1)
			for (int i = 0;i <= L - 1;i += l)
				for (int k = 0;k <= m - 1;++k)
				{
					z = Mult(P[i + m + k], W[L / l * k]);
					P[i + m + k] = ((P[i + k] - z) % MOD + MOD) % MOD;
					update(P[i + k], z);
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
		W[0] = 1, W[1] = inverse(W[1]);
		for (int i = 2;i <= L - 1;++i)
			W[i] = Mult(W[i - 1], W[1]);
		DFT(A);
		int invL = inverse(L);
		for (int i = 0;i <= L - 1;++i)
			A[i] = Mult(A[i], invL);
	}
}

const int Max_N(8050);
const int Max_M(205);

int N, M, F[Max_N][Max_M], Fac[Max_N], Inv[Max_N];

inline int C(const int &n, const int &m)
{
	return (n < m) ? 0 : Mult(Fac[n], Mult(Inv[m], Inv[n - m]));
}

int main()
{
	scanf("%d%d", &N, &M);
	NTT::L = 1;
	while (NTT::L <= N + N)
		NTT::L <<= 1;
	Fac[0] = 1;
	for (int i = 1;i <= max(N, M) + 2;++i)
		Fac[i] = Mult(Fac[i - 1], i);
	Inv[max(N, M) + 2] = inverse(Fac[max(N, M) + 2]);
	for (int i = max(N, M) + 1;i >= 0;--i)
		Inv[i] = Mult(Inv[i + 1], i + 1);
	F[0][0] = 1;
	for (int j = 1;j <= M;++j)
	{
		for (int i = 0;i <= N;++i)
			update(F[i][j], Mult(F[i][j - 1], (1 + C(i + 1, 2)) % MOD));
		NTT::clear();
		for (int i = 0;i <= N;++i)
			NTT::A[i] = Mult(F[i][j - 1], Inv[i]);
		for (int k = 1;k <= N;++k)
			NTT::B[k] = Inv[k + 2];
		NTT::NTT();
		for (int k = 1;k <= N;++k)
			update(F[k][j], Mult(Fac[k + 2], NTT::A[k]));
	}
	int Ans(0);
	for (int i = 0;i <= N;++i)
		update(Ans, Mult(C(N, i), F[i][M]));
	printf("%d", Ans);
	return 0;
}