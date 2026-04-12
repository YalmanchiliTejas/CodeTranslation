#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int n, temp;
deque<int> q;

int32_t main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		q.push_back(temp);
		
		while (q.size() > 2 and q.back() <= q[q.size() - 2] and \
			q[q.size() - 2] >= q[q.size() - 3])
		{
			temp = q.back() - q[q.size() - 2] + q[q.size() - 3];
			q.pop_back(); q.pop_back(); q.pop_back(); q.push_back(temp);
		}
	}
	
	int res = 0, i = 1;
	
	while (!q.empty())
	{
		if (q.front() >= q.back())
		{
			res += i * q.front();
			q.pop_front();
		}
		else
		{
			res += i * q.back();
			q.pop_back();
		}
		i = -i;
	}
	
	cout << res << "\n";
	
	return 0;
}
