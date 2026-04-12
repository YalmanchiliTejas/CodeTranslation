#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAXN = 2000 + 10;
int N, M;
char A[MAXN][MAXN];

int main() {
	register int i, j;
	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; ++i)
		scanf("%s", A[i] + 1);
	for(i = 1; i <= N; ++i)
		for(j = 1; j <= M; ++j) {
			if(A[i][j] == '#' && A[i][j + 1] == '#' && A[i + 1][j] == '#') return puts("Impossible"), 0;
			if(A[i][j] == '#' && A[i - 1][j] == '#' && A[i][j - 1] == '#') return puts("Impossible"), 0;
		}
	puts("Possible");
	return 0;
}