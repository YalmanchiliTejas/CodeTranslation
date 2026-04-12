#include <bits/stdc++.h>

#define exec_time() (1.0 * clock()/CLOCKS_PER_SEC)
#define fst first
#define snd second

typedef long long LL;
typedef std::pair<int, int> Pii;

template <typename T> inline bool maximum(T &a, T b) { return a < b? a = b, 1 : 0; }
template <typename T> inline bool minimum(T &a, T b) { return a > b? a = b, 1 : 0; }
template <typename T>
T read(T &x, T f = 0)
{
	char c = getchar(); x = 0;
	for(; !isdigit(c); c = getchar())
		f |= c == '-';
	for(;  isdigit(c); c = getchar())
		x = x*10 + c-'0';
	return x = f? -x : x;
}

const int N = 1e2 + 1;

int A, B;
int d[N + 5][N + 5], f[N + 5][N + 5];

void Init()
{
	read(A), read(B);
	for(int x = 1; x <= A; ++x)
		for(int y = 1; y <= B; ++y) read(d[x][y]);

	return ;
}

bool check()
{
	for(int x = 1; x <= A; ++x)
		for(int y = 1; y <= B; ++y){
			int dist = ~0U >> 1;

			for(int a = 0; a < N; ++a)
				for(int b = 0; b < N; ++b)
					minimum(dist, f[a][b] + x*a + y*b);

			if(dist != d[x][y]) return false;
		}
	return true;
}

void Exec()
{
	for(int x = 1; x <= A; ++x)
		for(int y = 1; y <= B; ++y)
			for(int a = 0; a < N; ++a)
				for(int b = 0; b < N; ++b)
					maximum(f[a][b], d[x][y] - x*a - y*b);
	if(!check()) puts("Impossible");
	else
	{
		puts("Possible");
		printf("%d %d\n", N*2, 2*(N-1) + N*N);
		for(int i = 1; i < N; ++i){
			printf("%d %d X\n", i, i + 1);
			printf("%d %d Y\n", i + N + 1, i + N);
		}
		for(int a = 0; a < N; ++a)
			for(int b = 0; b < N; ++b)
				printf("%d %d %d\n", a + 1, N + b + 1, f[a][b]);
		printf("%d %d\n", 1, N + 1);
	}

	return ;
}

int main()
{
	Init();
	Exec();

	return 0;
}