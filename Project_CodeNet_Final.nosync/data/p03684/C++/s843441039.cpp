#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<pair<long long, int>> x;
	vector<pair<long long, int>> y;
	for (auto i = 0; i < N; ++i)
	{
		auto tempX = 0ll;
		auto tempY = 0ll;
		cin >> tempX >> tempY;

		x.push_back(make_pair(tempX, i));
		y.push_back(make_pair(tempY, i));
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	vector<vector<pair<long long, int>>> g(N);
	for (auto i = 0; i < N - 1; ++i)
	{
		auto& prev = x[i];
		auto& next = x[i + 1];
		auto diff = next.first - prev.first;
		g[prev.second].push_back(make_pair(diff, next.second));
		g[next.second].push_back(make_pair(diff, prev.second));
	}
	for (auto i = 0; i < N - 1; ++i)
	{
		auto& prev = y[i];
		auto& next = y[i + 1];
		auto diff = next.first - prev.first;
		g[prev.second].push_back(make_pair(diff, next.second));
		g[next.second].push_back(make_pair(diff, prev.second));
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	q.push(make_pair(0, 0));
	set<int> used;
	auto result = 0ll;
	while (!q.empty())
	{
		auto p = q.top();
		q.pop();

		if (used.find(p.second) != used.end())
		{
			continue;
		}

		result += p.first;
		used.insert(p.second);
		for (auto& e : g[p.second])
		{
			if (used.find(e.second) != used.end())
			{
				continue;
			}

			q.push(e);
		}
	}

	cout << result << endl;

	return 0;
}