#include<cstdio>
using namespace std;

typedef long long LL;
const int mod = 1e9 + 7;

int main()
{
	LL sum = 0, res = 0;
	int N, T;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &T);
		res += sum * T;
		sum += T;

		res %= mod;
		sum %= mod;
	}
	printf("%lld\n", res);
}