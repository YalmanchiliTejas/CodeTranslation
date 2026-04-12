#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n, m;
	while(cin >> n >> m, n || m)
	{
		vector<int> Vec;
		int temp;
		for(int i = 0; i < n; ++i)
		{
			cin >> temp;
			Vec.push_back(temp);
		}
		for(int i = 0; i < m; ++i)
		{
			cin >> temp;
			Vec.push_back(temp);
		}
		sort(Vec.begin(), Vec.end());
		int Max = 0;
		int pos = 0;
		for(int i = 0; i < n + m; ++i)
		{
			Max = max(Vec[i] - pos, Max);
			pos = Vec[i];
		}
		cout << Max << endl;
	}
}

int main()
{
	solve();
	return(0);
}