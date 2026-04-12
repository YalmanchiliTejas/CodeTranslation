#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

typedef long long LL;
using namespace std;

int n, K;
LL res = 0;
int main() 
{
	while(~scanf("%d%d", &n, &K)) {
		res = 0;
		for (int i = 1; i <= n; i++) {
			int x = n / i, y = n % i;
			int now = max(0, i - K);
			if(y != 0) res = res + 1LL * now * x + max(0, y - (K == 0 ? K : K - 1));
			else res = res + 1LL * now * x;
		}
		printf("%lld\n", res);
	}
	return 0;
}

