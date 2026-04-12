#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;

int main()
{
	LL a, b;
	scanf("%lld %lld", &a, &b);
	LL ans = 0;
	for(int i = b; i <= a; i++)
	{
		ans = ans + (a - i);
	}
	for(int i = b + 1; i <= a - b; i++)
	{
		int t = (a - i) / i;
		int qw = i - b;
		ans = ans + (t * qw);
		if(a % i >= b) {
			ans = ans + a % i - b + 1;
		}
	}
	if(b == 0) ans = ans - a;
	printf("%lld\n", ans);
}