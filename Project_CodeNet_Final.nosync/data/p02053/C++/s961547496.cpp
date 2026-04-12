#include "bits/stdc++.h"

using namespace std;

void solve(void)
{
	int h, w;
	cin >> h >> w;
	vector<int> ps, qs;
	for (int i = 0; i < h; i++)
	{
		string g;
		cin >> g;
		for (int j = 0; j < w; j++)
		{
			if (g[j] == 'B')
			{
				ps.push_back(i+j);
				qs.push_back(i+w-j);
			}
		}
	}
	sort(ps.begin(), ps.end());
	sort(qs.begin(), qs.end());
	int ans = max(ps.back()-ps.front(), qs.back() - qs.front());
	cout << ans << endl;
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}


