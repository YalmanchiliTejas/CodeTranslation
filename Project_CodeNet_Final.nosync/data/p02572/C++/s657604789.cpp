#include <cstdio>
#define LOOP(x) (x%1000000007)
#define ROOP(x,y) ((x+1000000007-y)%1000000007)
//#define LOOP(x) (x)
//#define ROOP(x,y) ((x-y))

long long a[200001];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	long long sum;
	for (i = 0; i < n; i++) {
		long long sv;
		scanf("%lld", &sv);
		a[i] = sv;
		sum = LOOP(sv + sum);
	}

	long long res = 0;	
	for (i = 0; i < n; i++) {
		sum = ROOP(sum,a[i]);
		res = LOOP(a[i] * sum + res);
	}
	printf("%lld\n", res);
	return 0;
}