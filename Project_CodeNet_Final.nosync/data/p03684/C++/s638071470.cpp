#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

class adjacency_list
{
public:
	adjacency_list(size_t n)
		: g(n)
	{}

	void add_edge(int src, int dst, long long weight)
	{
		g[src].push_back({ dst, weight });
	}

	long long prim_minimum_spanning_tree() const
	{
		const int n = g.size();
		long long ans = 0;
		vector<bool> visited(n, false);
		priority_queue<edge> q;

		q.push({ 0, 0 });
		while (!q.empty()) {
			auto e = q.top();
			q.pop();
			if (visited[e.dst]) {
				continue;
			}
			visited[e.dst] = true;
			ans += e.weight;
			for (auto &f : g[e.dst]) {
				if (!visited[f.dst]) {
					q.push(f);
				}
			}
		}
		return ans;
	}
private:

	struct edge
	{
		int dst;
		long long weight;

		bool operator<(const edge &other) const
		{
			return tie(other.weight, dst) < tie(weight, other.dst);
		}
	};

private:
	vector<vector<edge>> g;
};

int main()
{
	int N;
	cin >> N;
	adjacency_list g(N);
	vector<tuple<int, int, int>> v(N);  // (id, x, y)
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		v[i] = tie(i, x, y);
	}
	// sort by x
	sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
		return get<1>(a) < get<1>(b);
	});
	for (int i = 0; i < N; ++i) {
		if (0 < i) {
			int a = get<0>(v[i - 1]);
			int b = get<0>(v[i]);
			int w = abs(get<1>(v[i - 1]) - get<1>(v[i]));
			g.add_edge(a, b, w);
			g.add_edge(b, a, w);
		}
		if (i + 1 < N) {
			int a = get<0>(v[i]);
			int b = get<0>(v[i + 1]);
			int w = abs(get<1>(v[i]) - get<1>(v[i + 1]));
			g.add_edge(a, b, w);
			g.add_edge(b, a, w);
		}
	}

	// sort by y
	sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
		return get<2>(a) < get<2>(b);
	});
	for (int i = 0; i < N; ++i) {
		if (0 < i) {
			int a = get<0>(v[i - 1]);
			int b = get<0>(v[i]);
			int w = abs(get<2>(v[i - 1]) - get<2>(v[i]));
			g.add_edge(a, b, w);
			g.add_edge(b, a, w);
		}
		if (i + 1 < N) {
			int a = get<0>(v[i]);
			int b = get<0>(v[i + 1]);
			int w = abs(get<2>(v[i]) - get<2>(v[i + 1]));
			g.add_edge(a, b, w);
			g.add_edge(b, a, w);
		}
	}
	
	cout << g.prim_minimum_spanning_tree() << endl;
}
