#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
pair <int, int> P[Maxn];
int n, maxi_pos, mini_pos, mini1 = 0x3f3f3f3f, maxi1, maxi2, mini2 = 0x3f3f3f3f;
long long ans;
map <int, int> Ma;
int main()
{
	scanf("%d", &n);
	P[0].first = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &P[i].first, &P[i].second);
		if (P[i].first > P[i].second) swap(P[i].first, P[i].second);
	}
	sort(P + 1, P + 1 + n, [](pair <int, int> x, pair <int, int> y){return x.second < y.second;});
	
	for (int i = 1; i <= n; i++)
	{
		mini1 = min(mini1, P[i].first);
		maxi1 = max(maxi1, P[i].first);
		mini2 = min(mini2, P[i].second);
		maxi2 = max(maxi2, P[i].second);
	}
	ans = (maxi1 - mini1) * (long long) (maxi2 - mini2);
	for (int i = 1; i <= n; i++)
		if (P[i].first < P[mini_pos].first) mini_pos = i;
	for (int i = 1; i <= n; i++)
		if (i != mini_pos && P[i].second > P[maxi_pos].second) maxi_pos = i;
	Ma[P[mini_pos].second]++, Ma[P[maxi_pos].first]++;
	for (int i = 1; i <= n; i++)
		if (i != maxi_pos && i != mini_pos)
			Ma[P[i].first]++;
	ans = min(ans, (long long) (P[maxi_pos].second - P[mini_pos].first) * (Ma.rbegin() -> first - Ma.begin() -> first));
	for (int i = 1; i <= n; i++)
		if (i != maxi_pos && i != mini_pos)
		{
			Ma[P[i].first]--;
			if (!Ma[P[i].first]) Ma.erase(P[i].first);
			Ma[P[i].second]++;
			ans = min(ans, (long long) (P[maxi_pos].second - P[mini_pos].first) * (Ma.rbegin() -> first - Ma.begin() -> first));
		}
	mini_pos = maxi_pos = 0;
	Ma.clear();
	for (int i = 1; i <= n; i++)
		if (P[i].second > P[maxi_pos].second) maxi_pos = i;
	for (int i = 1; i <= n; i++)
		if (i != maxi_pos && P[i].first < P[mini_pos].first) mini_pos = i;
	Ma[P[mini_pos].second]++, Ma[P[maxi_pos].first]++;
	for (int i = 1; i <= n; i++)
		if (i != maxi_pos && i != mini_pos)
			Ma[P[i].first]++;
	ans = min(ans, (long long) (P[maxi_pos].second - P[mini_pos].first) * (Ma.rbegin() -> first - Ma.begin() -> first));
	for (int i = 1; i <= n; i++)
		if (i != maxi_pos && i != mini_pos)
		{
			Ma[P[i].first]--;
			if (!Ma[P[i].first]) Ma.erase(P[i].first);
			Ma[P[i].second]++;
			ans = min(ans, (long long) (P[maxi_pos].second - P[mini_pos].first) * (Ma.rbegin() -> first - Ma.begin() -> first));
		}
	printf("%lld", ans);
	return 0;
}