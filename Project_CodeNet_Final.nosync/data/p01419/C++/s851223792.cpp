#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define INF INT_MAX/2

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int, int, int> tiii; // node, cost, parent
typedef long long ll;

struct Comp
{
	bool operator() (tiii a, tiii b)
	{
		return get<1>(a) > get<1>(b);
	}
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int find_index(vector<int> a, int x)
{
	if (a.size() == 0) return -1;

	int l = 0;
	int r = a.size();
	while (l + 1 != r)
	{
		int mid = (l + r) / 2;
		if (a[mid] <= x)
			l = mid;
		else
			r = mid;
	}
	if (a[l] == x)
		return l;
	else
		return -1;
}

int main()
{
	int R, C, M; cin >> R >> C >> M;

	vs grids(R);
	rep(y, 0, R) cin >> grids[y];

	vvi consume(R, vi(C, 0));
	rep(y, 0, R) rep(x, 0, C) cin >> consume[y][x];

	vvi turnon(R, vi(C, 0));
	rep(y, 0, R) rep(x, 0, C) cin >> turnon[y][x];

	vvi turnoff(R, vi(C, 0));
	rep(y, 0, R) rep(x, 0, C) cin >> turnoff[y][x];



	vi order;
	int _x, _y; cin >> _y >> _x;
	int bak = _y * C + _x;
	order.push_back(bak);
	rep(_m, 1, M)
	{
		int y, x; cin >> y >> x;
		int s = y * C + x;

		vi dist(R*C, INF);
		vi back(R*C, -INF);
		priority_queue<tiii, vector<tiii>, Comp> que;
		que.push(tiii(bak, 0, -1));
		dist[bak] = 0;
		while (!que.empty())
		{
			tiii t = que.top(); que.pop();

			int node = get<0>(t);
			int cost = get<1>(t);

			if (back[node] != -INF) continue;
			back[node] = get<2>(t);

			if (node == s) break;

			rep(i, 0, 4)
			{
				int xx = (node % C) + dx[i];
				int yy = (node / C) + dy[i];

				if (xx < 0 || C <= xx) continue;
				if (yy < 0 || R <= yy) continue;
				if (grids[yy][xx] == '#') continue;

				int ss = yy * C + xx;

				if (cost + 1 < dist[ss])
				{
					dist[ss] = cost + 1;
					que.push(tiii(ss, cost + 1, node));
				}
			}
		}

		vi tmp;
		int to = s;
		while (0 <= to)
		{
			tmp.push_back(to);
			to = back[to];
		}
		rep(i, 1, tmp.size()) order.push_back(tmp[tmp.size() - 1 - i]);

		bak = s;
	}



	vvi list(R*C);
	rep(i, 0, order.size()) list[order[i]].push_back(i);

	ll ans = 0;

	vi onoff(R*C, 0);
	ll pluscost = 0;
	rep(i, 0, order.size())
	{
		if (i != 0) ans += pluscost;

		int node = order[i];
		int y = node / C;
		int x = node % C;

		if (onoff[node] == 0) ans += (ll)turnon[y][x];

		int index = find_index(list[node], i);

		if (list[node].size() - 1 == index)
		{
			// last
			ans += (ll)turnoff[y][x];
			if (onoff[node] == 1) pluscost -= (ll)consume[y][x];
			onoff[node] = 0;
			continue;
		}

		if (consume[y][x] * (list[node][index + 1] - list[node][index]) < turnon[y][x] + turnoff[y][x])
		{
			// tukeppa
			if (onoff[node] == 0) pluscost += (ll)consume[y][x];
			onoff[node] = 1;
		}
		else
		{
			ans += (ll)turnoff[y][x];
			if (onoff[node] == 1) pluscost -= (ll)consume[y][x];
			onoff[node] = 0;
		}
	}
	cout << ans << endl;
}