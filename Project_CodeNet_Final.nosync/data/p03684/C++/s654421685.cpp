#include<iostream>
#include<set>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;

using LL = long long;

int main()
{
	int N;
	cin >> N;

	vector<tuple<int, int>> points; // [x, y]
	vector<tuple<int, int>> vx, vy; // [value, index];
	for (int i = 0; i < N; ++i)
	{
		int x;
		int y;
		cin >> x >> y;
		points.push_back(make_tuple(x, y));
		vx.push_back(make_tuple(x, i));
		vy.push_back(make_tuple(y, i));
	}

	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());

	set<int> sx, sy;
	priority_queue<tuple<int, int>> q; // [-dist, index];
	vector<bool> used(N);

	LL result = 0;
	q.push(make_tuple(0, 0));
	while (!q.empty())
	{
		auto t = q.top();
		q.pop();
		int dist, index;
		tie(dist, index) = t;

		if (used[index]) { continue; }
		used[index] = true;

		result += (-1 * dist);
		auto cx = get<0>(points[index]);
		auto cy = get<1>(points[index]);
		sx.insert(cx);
		sy.insert(cy);

		vector<int> nexts;

		auto ix = lower_bound(vx.begin(), vx.end(), make_tuple(cx, index));
		if (ix != vx.begin())
		{
			nexts.push_back(get<1>(*(ix - 1)));
		}
		if (ix + 1 != vx.end())
		{
			nexts.push_back(get<1>(*(ix + 1)));
		}
		auto iy = lower_bound(vy.begin(), vy.end(), make_tuple(cy, index));
		if (iy != vy.begin())
		{
			nexts.push_back(get<1>(*(iy - 1)));
		}
		if (iy + 1 != vy.end())
		{
			nexts.push_back(get<1>(*(iy + 1)));
		}
		sort(nexts.begin(), nexts.end());
		nexts.erase(unique(nexts.begin(), nexts.end()), nexts.end());

		for (auto next : nexts)
		{
			if (used[next]) { continue; }
			q.push(make_tuple(
				-1 * min(abs(cx - get<0>(points[next])), abs(cy - get<1>(points[next]))),
				next));
		}
	}

	cout << result << endl;

#ifdef _DEBUG
	system("pause");
#endif
}
