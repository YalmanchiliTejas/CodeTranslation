#include <bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	ll res = 0;
	for(int i=k+1; i<=n; i++) {
		ll x = (n - k) / i;
		res += (i - k) * x + min((ll)n, (x + 1) * i - 1) - (i * x + k) + 1;
		res -= k == 0;
	}
	printf("%lld", res);
	return 0;
}

// [k, i-1]
// [i+k, 2i-1]
// [2i+k, 3i-1]
// ...
// [xi+k, min(n, (x+1)i - 1)]

// xi+k <= n
// xi <= n - k
// x <= (n - k) / i