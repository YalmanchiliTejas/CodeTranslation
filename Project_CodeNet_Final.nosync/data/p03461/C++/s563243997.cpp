#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#define RG register
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)
#define clear(x, y) memset(x, y, sizeof(x))

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while(ch != '-' && (!isdigit(ch))) ch = getchar();
	if(ch == '-') w = -1, ch = getchar();
	while(isdigit(ch)) data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int _A_(15), N(110);
int d[_A_][_A_], f[N][N], A, B;

int main()
{
	A = read(), B = read();
	for(RG int i = 1; i <= A; i++)
		for(RG int j = 1; j <= B; j++)
			d[i][j] = read();
	for(RG int i = 0; i <= 100; i++)
		for(RG int j = 0; j <= 100; j++)
			for(RG int p = 1; p <= A; p++)
				for(RG int q = 1; q <= B; q++)
					f[i][j] = std::max(f[i][j], d[p][q] - i * p - j * q);
	for(RG int i = 1; i <= A; i++)
		for(RG int j = 1; j <= B; j++)
		{
			int min = 1e9;
			for(RG int p = 0; p <= 100; p++)
				for(RG int q = 0; q <= 100; q++)
					min = std::min(min, f[p][q] + i * p + j * q);
			if(min != d[i][j]) return puts("Impossible"), 0;
		}
	puts("Possible\n202 10401");
	for(RG int i = 1; i <= 100; i++)
		printf("%d %d X\n", i, i + 1);
	for(RG int i = 102; i < 202; i++)
		printf("%d %d Y\n", i, i + 1);
	for(RG int i = 0; i <= 100; i++)
		for(RG int j = 0; j <= 100; j++)
			printf("%d %d %d\n", i + 1, 202 - j, f[i][j]);
	puts("1 202");
	return 0;
}
