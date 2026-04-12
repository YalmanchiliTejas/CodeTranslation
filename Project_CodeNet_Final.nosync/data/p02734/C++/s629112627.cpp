#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3005, P = 998244353;

typedef long long LL;

int n, S, a[N], f[N];

int ans = 0;

int main() {
	scanf("%d%d", &n, &S);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) {
		if (S - a[i] > 0) ans = (ans + (LL) (n - i + 1) * f[S - a[i]]) % P;
		else if (S == a[i]) ans = (ans + (LL) i * (n - i + 1)) % P;
		
		for (int j = S; j > a[i]; j--) 
			(f[j] += f[j - a[i]]) %= P;
		(f[a[i]] += i) %= P;
	}

	printf("%d\n", ans);
	return 0;
}