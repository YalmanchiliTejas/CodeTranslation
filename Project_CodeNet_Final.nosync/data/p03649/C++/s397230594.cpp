#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	vector<ll>v;
	for (int i = 0; i < num; i++)
	{
		ll z;
		scanf("%lld", &z);
		v.push_back(z);
	}
	ll ans = 0;
	for (;;)
	{
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		if (v[0] <= num - 1)break;
		if (v[0] <= num * 10)
		{
			for (;;)
			{
				ans++;
				v[0] -= num;
				for (int i = 1; i < num; i++)v[i]++;
				sort(v.begin(), v.end());
				reverse(v.begin(), v.end());
				if (v[0] <= num - 1)break;
			}
			break;
		}
		int t = 0;
		for (int i = 0; i < v.size(); i++)if (v[0] - v[i] <= num + 1)t = i + 1;
		ll x;
		if (t == num)x = v[t - 1] - num * 2;
		else x = (v[t - 1] - max((ll)num, v[t])) / (num + 1);
		x = max(x, 0LL);
		ans += x*t;
		for (int i = 0; i < t; i++)v[i] -= x*(num - (t - 1));
		for (int i = t; i < num; i++)v[i] += x*t;
		if (x == 0)
		{
			ans++;
			v[0] -= num;
			for (int i = 1; i < num; i++)v[i]++;
		}
	}
	printf("%lld\n", ans);
}