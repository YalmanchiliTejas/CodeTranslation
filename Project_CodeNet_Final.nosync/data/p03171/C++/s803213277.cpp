#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[3010], K;
long long D[3010][3010];
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%d", &w[i]);
	for (int L = 1; L <= n; L++) {
		for (i = 1; i <= n - L + 1; i++) {
			j = i + L - 1;
			if (L == 1) {
				D[i][j] = w[i];
				continue;
			}
			D[i][j] = max(w[i] - D[i + 1][j], w[j] - D[i][j - 1]);
		}
	}
	printf("%lld\n", D[1][n]);
}