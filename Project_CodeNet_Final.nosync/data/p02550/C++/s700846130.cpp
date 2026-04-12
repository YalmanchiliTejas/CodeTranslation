#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int32_t main()
{
	//freopen("input.txt", "r", stdin);
	IOS;
	
	int n; cin >> n;
	int x; cin >> x;
	int m; cin >> m;

	unordered_set<int> cache;
	vector<int> path;

	int ans = x, curr = x;
	cache.insert(x);
	path.push_back(x);

	for(int i = 1 ; i < n ; i++)
	{
		int t = (curr*curr)%m;
		if(cache.find(t) != cache.end())
		{
			curr = t;
			// cout << curr << '\n';
			break;
		}
		curr = t;
		ans += t;
		cache.insert(curr);
		path.push_back(curr);
	}

	int sum = 0, index = -1;
	for(int i = 0 ; i < path.size() ; i++)
	{
		if(path[i] == curr)
		{
			index = i;
			// cout << index << '\n';
			break;
		}
	}

	if(index == -1)
	{
		cout << ans << '\n';
		return 0;
	}

	for(int i = index ; i < path.size() ; i++)
	{
		sum += path[i];
	}
	int nums = path.size() - index;
	int done = n - path.size();
	int factor = done/nums;
	int rem = done%nums;

	ans += (factor*sum);
	while(rem--)
	{
		ans += path[index];
		++index;
	}

	cout << ans << '\n';
	return 0;
}