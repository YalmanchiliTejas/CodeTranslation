#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n, k, res;
int main() {
	scanf("%lld%lld", &n, &k);
	if(k == 0)printf("%lld\n", n * n);
	else {
		for(LL b = k + 1; b <= n; b++) {
			res += (b - k) * (n / b) + max(n % b - k + 1LL, 0LL);
		}
		printf("%lld\n", res);
	}
}