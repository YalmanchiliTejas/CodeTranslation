#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 3100;

ll f[N][N];
int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i) if(n & 1) f[i][i] = a[i]; else f[i][i] = -a[i];
	for(int len = 2; len <= n; ++len) {
		for(int l = 1; l <= n; ++l) {
			int r = l + len - 1;
			if((n - len) & 1) f[l][r] = min(f[l + 1][r] - a[l], f[l][r - 1] - a[r]);
			else f[l][r] = max(f[l + 1][r] + a[l], f[l][r - 1] + a[r]);
		}
	}
	printf("%lld\n", f[1][n]);
}