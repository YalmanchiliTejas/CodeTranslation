#include<cstdio>
#include<algorithm>
using namespace std;
int n, m;
long long Mod = 1000000007, D[401000], S[401000];
char p[301000];
long long DD[401000][2][2];
int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	scanf("%s", p);
	int ck = 0;
	for (i = 0; p[i]; i++) {
		if (p[i] == 'R')ck |= 1;
		if (p[i] == 'B')ck |= 2;
	}
	if (ck!=3) {
		DD[1][0][0] = 1;
		DD[1][1][1] = 1;
		for (i = 2; i <= n; i++) {
			DD[i][0][0] = (DD[i - 1][0][0] + DD[i - 1][0][1]) % Mod;
			DD[i][0][1] = (DD[i - 1][0][0]) % Mod;
			DD[i][1][0] = (DD[i - 1][1][0] + DD[i - 1][1][1]) % Mod;
			DD[i][1][1] = (DD[i - 1][1][0]) % Mod;
		}
		printf("%lld\n", (DD[n][0][0] + DD[n][0][1] + DD[n][1][0]) % Mod);
		return 0;
	}
	if (n % 2 == 1) {
		puts("0");
		return 0;
	}
	if (p[0] == 'B') {
		for (i = 0; i < m; i++) {
			p[i] = 'R' + 'B' - p[i];
		}
	}
	int c = 0, Mn = 1e9;
	ck = 0;
	for (i = 0; i < m; i++) {
		if (p[i] == 'R') {
			c++;
			if (p[i + 1] == 'B') {
				if (!ck) {
					if (c % 2 == 0)Mn = min(Mn, c + 1);
					else Mn = min(Mn, c);
				}
				else {
					if (c % 2 == 1)Mn = min(Mn, c);
				}
				ck = 1;
			}
		}
		else c = 0;
	}

	int K = (Mn + 1) / 2;
	D[0] = 1;
	S[0] = 1;
	for (i = 1; i <= n; i++) {
		long long t = S[i - 1];
		if (i - K - 1 >= 0)t -= S[i - K - 1];
		D[i] = (t + Mod) % Mod;
		S[i] = (S[i - 1] + D[i]) % Mod;
	}
	long long res = D[n / 2];
	for (i = 1; i <= Mn && i<=n; i+=2) {
		res = (res + 1ll*i*D[(n - i - 1) / 2])%Mod;
	}
	printf("%lld\n", res);

}