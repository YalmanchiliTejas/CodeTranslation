#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

const int MAXN = 100000 + 10;

int N, M;
int x[MAXN], y[MAXN];
int A[MAXN * 10], B[MAXN * 10], C[MAXN * 10];
int Order[MAXN * 10];
int Fa[MAXN];

bool Cmpx(const int& a, const int& b)
{
	return x[a] < x[b];
}

bool Cmpy(const int& a, const int& b)
{
	return y[a] < y[b];
}

bool Cmpz(const int& a, const int& b)
{
	return C[a] < C[b];
}

int GetRoot(int i)
{
	return (Fa[i] == i) ? i : (Fa[i] = GetRoot(Fa[i]));
}

void Insert(int a, int b)
{
	A[M] = a;
	B[M] = b;
	C[M] = min(abs(x[a] - x[b]), abs(y[a] - y[b]));
	M ++;
}

void Work()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i ++)
	{
		scanf("%d%d", &x[i], &y[i]);
		Fa[i] = i;
	}
	
	int t = 5;

	for (int i = 0; i < N; i ++)
		Order[i] = i;
	sort(Order, Order + N, Cmpx);
	for (int i = 0; i < N; i ++)
		for (int j = 1; j < t && i + j < N; j ++)
			Insert(Order[i], Order[i + j]);
	sort(Order, Order + N, Cmpy);
	for (int i = 0; i < N; i ++)
		for (int j = 1; j < t && i + j < N; j ++)
			Insert(Order[i], Order[i + j]);
	

	for (int i = 0; i < M; i ++)
		Order[i] = i;
	sort(Order, Order + M, Cmpz);
	long long Ans = 0;
	for (int i = 0; i < M; i ++)
	{
		int a = GetRoot(A[Order[i]]);
		int b = GetRoot(B[Order[i]]);
		if (a != b)
		{
			Ans += (long long) C[Order[i]];
			Fa[GetRoot(A[Order[i]])] = GetRoot(B[Order[i]]);
		}
	}
	printf("%lld\n", Ans);
}

int main()
{
	Work();
	return 0;
}