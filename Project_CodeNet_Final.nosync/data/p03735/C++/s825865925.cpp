#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
multiset<ll>se;
ll get()
{
	multiset<ll>::iterator it = se.begin();
	ll a = *it;
	it = se.end();
	it--;
	return (*it) - a;
}
int main()
{
	int num;
	scanf("%d", &num);
	ll min1 = 1000000000, max1 = 0, min2 = 1000000000, max2 = 0;
	ll mini = 1000000001, maxi = -1;
	int r1, r2;
	vector<pii>zv;
	for (int i = 0; i < num; i++)
	{
		ll za, zb;
		scanf("%lld%lld", &za, &zb);
		if (za > zb)swap(za, zb);
		min1 = min(min1, za), max1 = max(max1, za);
		min2 = min(min2, zb), max2 = max(max2, zb);
		if (mini > za)mini = za, r1 = i;
		if (maxi < zb)maxi = zb, r2 = i;
		zv.push_back(make_pair(za, zb));
	}
	ll ans = (max2 - min2)*(max1 - min1);
	if (r1 != r2)
	{
		vector<pii>v;
		for (int i = 0; i < num; i++)if (i != r1&&i != r2)v.push_back(zv[i]);
		se.insert(zv[r1].second);
		se.insert(zv[r2].first);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)se.insert(v[i].first);
		ll t = get();
		for (int i = 0; i < v.size(); i++)
		{
			multiset<ll>::iterator it = se.find(v[i].first);
			se.erase(it);
			se.insert(v[i].second);
			t = min(t, get());
		}
		ans = min(ans, t*(maxi - mini));
	}
	printf("%lld\n", ans);
}