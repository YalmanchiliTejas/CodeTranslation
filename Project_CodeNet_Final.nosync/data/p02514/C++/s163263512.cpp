
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>

#include <algorithm>

using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,s,n) for(int i=(s); i<(n); i++)
#define ALLOF(c) c.begin(), c.end()

#define INF ((int)1e8)

struct E { int to, time; };
bool operator < (const E &lhs, const E &rhs) { return lhs.time > rhs.time; }

int dijkstra(vector< vector<E> > &g, int start, int goal)
{
	priority_queue<E> q;
	E init = { start, 0 }; q.push(init);
	
	bool visited[10000] = { false, };

	while (!q.empty())
	{
		E ce = q.top(); q.pop();
		int cur = ce.to;
		int time = ce.time;

		if (visited[cur])
			continue;
		visited[cur] = true;

		if (cur == goal)
			return time;

		REP(i, g[cur].size())
		{
			if (!visited[g[cur][i].to])
			{
				E next = { g[cur][i].to, time + g[cur][i].time };
				q.push(next);
			}
		}
	}
	return INF;
}

struct P { int j, x, y; };

int main()
{
	while(true)
	{
		int w, h; cin >> w >> h;
		if (w == 0) break;

		vector< P > m;
		int maxindex = 0;

		int start, goal;
		{
			int xxx = 0;
			REP(y, h) REP(x, w)
			{
				char t[16]; scanf("%s", t);
				if (t[0] == '.') continue;
				P p = {0, x, y};
				if (t[0] == 'S') { p.j = 0; start = m.size(); }
				else if (t[0] == 'G') { p.j = -1; goal = m.size(); }
				else { p.j = atoi(t); }
				m.push_back(p);
				maxindex = max(maxindex, p.j);
			}
			m[goal].j = maxindex + 1;
		}

		vector< vector<E> > g(m.size());

		REP(i, m.size()) REP(j, m.size())
		{
			if (m[i].j + 1 == m[j].j)
			{
				E e = { j, abs(m[j].x - m[i].x) + abs(m[j].y - m[i].y) };
				g[i].push_back(e);
			}
		}
		int cost = dijkstra(g, start, goal);
		cout << cost << endl;

	}

}