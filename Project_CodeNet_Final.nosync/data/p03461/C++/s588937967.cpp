#include <bits/stdc++.h>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define For(i, j, k) for(int i = j; i <= k; i++)
#define Forr(i, j, k) for(int i = j; i >= k; i--)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int M = 12, N = 310;

int d[M][M], dis[M][M], A, B;
int f[N][N];

int main(){

	scanf("%d%d", &A, &B);
	For(i, 1, A) For(j, 1, B) scanf("%d", &d[i][j]), dis[i][j] = 1e9;
	For(i, 0, 100) For(j, 0, 100) For(u, 1, A) For(v, 1, B) 
		f[i][j] = max(f[i][j], d[u][v] - u * i - v * j);
	For(u, 1, A) For(v, 1, B) For(i, 0, 100) For(j, 0, 100)
		dis[u][v] = min(dis[u][v], f[i][j] + i * u + j * v);
	For(u, 1, A) For(v, 1, B) if(d[u][v] != dis[u][v]){
		puts("Impossible");
		return 0;
	}


	puts("Possible");
	int n = 101;
	printf("%d %d\n", n * 2, n * n + 2 * (n - 1));
	For(i, 1, n) For(j, 1, n) printf("%d %d %d\n", i, j + n, f[i - 1][j - 1]);
	For(i, 2, n) printf("%d %d X\n", i - 1, i);
	For(i, 2, n) printf("%d %d Y\n", i + n, i + n - 1);
	printf("%d %d\n", 1, n + 1);

	return 0;
}