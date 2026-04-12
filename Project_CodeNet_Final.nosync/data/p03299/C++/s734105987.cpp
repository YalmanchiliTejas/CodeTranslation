
#include <cstdio>
#include <algorithm>

using namespace std;
const int Max_N(105);
const int MOD(1000000000 + 7);

constexpr int Mult(int a, int b)
{
	return a * 1LL * b % MOD;
}

constexpr int Add(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}

inline void upd(int &a, int b)
{
	a = Add(a, b);
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

int N, H[Max_N], V, F[Max_N][3], power2[Max_N];

int solve(int l, int r)
{
	int u = ++V, Min = H[l];
	for (int i = l;i <= r;++i)
		Min = min(Min, H[i]);
	for (int i = l;i <= r;++i)
		H[i] -= Min;
	int start, v, G[Max_N][3] = {};
	if (!H[l])
		G[l][0] = G[l][1] = 1, G[l][2] = 0, start = l + 1;
	else
		for (int x = l;x <= r;++x)
			if (!H[x])
			{
				start = x, v = solve(l, --x);
				G[x][2] = F[v][2];
				G[x][0] = G[x][1] = Add(F[v][0], F[v][1]);
				break;
			}
	for (int i = start, x;i <= r;++i)
		if (!H[i])
		{
			upd(G[i][2], Mult(G[i - 1][2], 2));
			upd(G[i][2], Add(G[i - 1][0], G[i - 1][1]));
			upd(G[i][0], G[i - 1][1]), upd(G[i][1], G[i - 1][0]);
		}
		else
		{
			for (x = i;x <= r;++x)
				if (x == r || !H[x + 1])
					break;
			v = solve(i, x);
			upd(G[x][2], Mult(G[i - 1][2], Add(F[v][2], Mult(2, Add(F[v][0], F[v][1])))));
			for (int c = 0;c <= 1;++c)
			{
				upd(G[x][2], Mult(G[i - 1][c], Add(F[v][2], Add(F[v][0], F[v][1]))));
				upd(G[x][c ^ ((x - i + 1) & 1)], Mult(G[i - 1][c], Add(F[v][0], F[v][1])));
			}
			i = x;
		}
	F[u][2] = G[r][2];
	if (Min == 1)
		F[u][0] = G[r][(r - l) & 1], F[u][1] = G[r][((r - l) & 1) ^ 1];
	else
		F[u][0] = F[u][1] = Mult(Add(G[r][0], G[r][1]), power(2, Min - 2));
	return u;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1;i <= N;++i)
		scanf("%d", H + i);
	power2[0] = 1;
	for (int i = 1;i <= N;++i)
		power2[i] = Add(power2[i - 1], power2[i - 1]);
	solve(1, N);
	printf("%d", Add(Add(F[1][0], F[1][1]), F[1][2]));
	return 0;
}