#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define R register
int n, K;
long long Ans, tmp;
int main()
{
	scanf("%d %d", &n, &K);
	for(R int i = K + 1; i <= n; i++)
	{
		tmp = Ans;
		R int t = n / i;
		Ans += 1ll * t * (i - K);
		t = n % i;
		if(t >= K) Ans += t - K + 1;
	}
	if(K == 0) Ans -= n;
	printf("%lld\n", Ans);
	return 0;
}