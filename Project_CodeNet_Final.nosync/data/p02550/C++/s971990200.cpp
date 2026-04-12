#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int main()
{
	ll n, x, m; cin >> n >> x >> m;
	vector<int> parent(m+1);
	for(int i = 0; i <=m; ++i) parent[i] = i;
	ll pre = x;
	ll remain = n - 1;
	parent[x] = -1;
	ll ans = x;
	while(remain)
	{
		ll next = (pre * pre) % m;

		if(parent[next] == next)
		{
			parent[next] = pre;
		}
		else
		{
			break;
		}
		
		ans += next;
		--remain;
		pre = next;
	}
	if(!remain) cout << ans;
	else
	{
		//find length of cycle;
		
		ll cycleLen = 1;
		ll cycleTotal = pre;
		ll startPos = pre;
		ll next = (pre * pre) % m;

		while(next != startPos)
		{
			cycleTotal += next;
			next = (next * next) % m;
			++cycleLen;
		}
		ll times = remain / cycleLen;
		remain = remain % cycleLen;
		ans += (cycleTotal * times);

		next = (next * next) % m;
		while(remain)
		{
			ans += next;
			next = (next * next) % m;
			--remain;
		}
		cout << ans;
	}

	return 0;
}