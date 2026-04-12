#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[51];
int main()
{
	ll n;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	ll dap = 0;
	while (1)
	{
		int check = 0;
		ll ch = 0;
		for (int i = 1; i <= n; i++)
		{
			ch += (a[i] / n);
			if (a[i] < n)
				check++;
		}
		if (check == n)break;
		dap += ch;
		for (int i = 1; i <= n; i++)
		{
			a[i] = ch - (a[i] / n)+(a[i]%n);
		}
	}
	printf("%lld\n", dap);
}