#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main ()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v;

	for (int i=0; i<n; ++i)
	{
		int x;
		cin >> x;
		v.push_back(make_pair(i, x));
	}

	sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });

	//        m
	//     1 [2] 3
	//  0    [2] 3
	//  0 [1]    3
	//  0 [1] 2   

	vector<int> ans(n);
	int m = n >> 1;
	for (int i=0; i<n; ++i)
	{
		if (i < m)
		{
			ans[v[i].first] = v[m].second;
		}
		else
		{
			ans[v[i].first] = v[m-1].second;
		}
	}

	for (auto a : ans)
	{
		cout << a << endl;
	}
	return 0;
}