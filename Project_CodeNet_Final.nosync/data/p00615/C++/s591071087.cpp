#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n, m;
	while(cin >> n >> m, n || m)
	{
		vector<int> time;
		for(int i = 0; i < n; ++i)
		{
			int tl;
			cin >> tl;
			time.push_back(tl);
		}
		for(int i = 0; i < m; ++i)
		{
			int tr;
			cin >> tr;
			time.push_back(tr);
		}
		sort(time.begin(), time.end());
		int max_diff = time[0];
		for(int i = 0; i < time.size() - 1; ++i)
		{
			if(time[i + 1] - time[i] > max_diff)
			{
				max_diff = time[i + 1] - time[i];
			}
		}
		cout << max_diff << endl;
	}
}

int main()
{
	solve();
	return(0);
}