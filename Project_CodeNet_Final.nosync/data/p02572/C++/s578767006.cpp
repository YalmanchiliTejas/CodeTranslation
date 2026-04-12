#include <cstdio>
#define maxn 200005
#define MOD 1000000007LL
using namespace std;

typedef long long LL;

LL a[maxn];

int main(int argc, char** argv)
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%lld", a + i);
	LL sum = a[0], res = 0LL;
	for(int i=1; i<n; i++)
	{
		res += sum * a[i];
		sum += a[i];
		res %= MOD, sum %= MOD;
	}
	printf("%lld\n", res);
	return 0;
}