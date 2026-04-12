#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll dap = n*n;
	for (int i = 1; i <= n; i++)
	{
		if (m < i) {
			ll gap = n / i*m;
			gap += max(min(n%i, m - 1),(ll)0);
			dap -= gap;
		}
		else
			dap -= n;
	}
	printf("%lld", dap);
}