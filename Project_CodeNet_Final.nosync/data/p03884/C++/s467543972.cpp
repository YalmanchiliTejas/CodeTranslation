#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 601;
const char sb[10] = "AVITSEF";

ll c[N], k;
int an;
char ans[5555];

int main() {
	scanf("%lld", &k);
	c[0] = 1;
	for (int i = 1; i < N; i++) c[i] = c[i - 1] * (i + 7) / i;
	an = 0;
	for (int i = N - 1; i >= 0; i--) {
		ll f = k / c[i];
		for (int j = 0; j < f; j++) ans[an++] = 'L';
		for (int j = 0; j < 7; j++) ans[an++] = sb[j];
		k -= f * c[i];
	}
	for (int i = an - 1; i >= 0; i--) printf("%c", ans[i]); printf("\n");
	return 0;
}
