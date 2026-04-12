#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype

template <class T>
int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define popcount __builtin_popcount

const double EPS = 1e-8;
typedef long long ll;
typedef pair<int, int> pint;


int dijkstra(map<int, vector<pint> >& edge, int s, int t)
{
	map<int, int> d;
	priority_queue<pint, vector<pint>, greater<pint> > q;
	q.push(pint(0, s));
	d[s] = 0;
	while (!q.empty())
	{
		pint e = q.top();
		q.pop();
		int dis = e.first;
		int from = e.second;

		if (d[from] < dis)
			continue;
		else if (from == t)
			return dis;

		for (int i = 0; i < edge[from].size(); ++i)
		{
			int to = edge[from][i].second;
			int nextDis = dis + edge[from][i].first;
			if (!d.count(to) || nextDis < d[to])
			{
				q.push(pint(nextDis, to));
				d[to] = nextDis;
			}
		}
	}

	return -1;
}
int manha(pint a, pint b)
{
	return abs(a.first-b.first) + abs(a.second-b.second);
}
int id(pint pos)
{
	return pos.first * 1000 + pos.second;
}
int main()
{
	int w, h;
	while (cin >> w >> h, w | h)
	{
		map<int, vector<pint> > pos;
		int gx, gy, m = 0;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				string s;
				cin >> s;
				if (s[0] == 'S')
					pos[0].push_back(pint(j, i));
				else if (s[0] == 'G')
				{
					gx = j;
					gy = i;
				}
				else if (isdigit(s[0]))
				{
					int t = atoi(s.c_str());
					pos[t].push_back(pint(j, i));
					m = max(m, t);
				}
			}
		}
		++m;
		pos[m].push_back(pint(gx, gy));

		map<int, vector<pint> > edge;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < pos[i].size(); ++j)
				for (int k = 0; k < pos[i+1].size(); ++k)
					edge[id(pos[i][j])].push_back(pint(manha(pos[i][j], pos[i+1][k]), id(pos[i+1][k])));

		cout << dijkstra(edge, id(pos[0][0]), id(pos[m][0])) << endl;
	}

	return 0;
}