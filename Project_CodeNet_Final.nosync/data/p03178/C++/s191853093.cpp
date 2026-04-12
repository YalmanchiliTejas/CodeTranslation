#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
long long Mod = 1000000007, D[10100][110];
int n, K, w[10100];
char p[10100];
int main(){
	scanf("%s", p);
	scanf("%d", &K);
	int i, j, k;
	for (i = 0; p[i]; i++);
	n = i;
	for (i = 0; i < n; i++)w[n - i - 1] = p[i] - '0';
	D[0][0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < K; j++) {
			for (k = 0; k < 10; k++) {
				D[i][(j + k) % K] = (D[i][(j + k) % K] + D[i - 1][j]) % Mod;
			}
		}
	}
	int s = 0;
	long long res = 0;
	for (i = n - 1; i >= 0; i--) {
		for (j = 0; j < w[i]; j++) {
			res = (res + D[i][(K - (s + j) % K) % K])%Mod;
		}
		s += w[i];
	}
	if (s%K == 0)res = (res + 1) % Mod;
	res = (res + Mod - 1) % Mod;
	printf("%lld\n", res);
}