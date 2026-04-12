#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<pair<int, int>, int> encoder;

int encode(const pair<int, int> &p) {
	if(!encoder.count(p)) encoder.insert({p, encoder.size()});
	return encoder[p];
}

vector<vector<int>> make_graph(const vector<string> &field) {
	const int h = field.size();
	const int w = field[0].size();

	int V = 0;
	for(const auto &row : field) {
		V += count(row.begin(), row.end(), '.');
	}

	constexpr int dx[4] = {1, -1, 0, 0};
	constexpr int dy[4] = {0, 0, 1, -1};

	vector<vector<int>> graph(V);
	for(int y = 0; y < h; ++y) {
		for(int x = 0; x < w; ++x) {
			if(field[y][x] == '.') {
				auto &es = graph[encode({x, y})];

				for(int d = 0; d < 4; ++d) {
					const int nx = x + dx[d];
					const int ny = y + dy[d];

					if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
					if(field[ny][nx] == '#') continue;

					es.emplace_back(encode({nx, ny}));
				}
			}
		}
	}
	return graph;
}

int input_index() {
	int x, y;
	cin >> y >> x;
	return encode({x, y});
}

vector<int> input_matrix(int h, int w) {
	vector<int> res(encoder.size());
	for(int y = 0; y < h; ++y) {
		for(int x = 0; x < w; ++x) {
			int value;
			cin >> value;
			if(value) res[encode({x, y})] = value;
		}
	}
	return res;
}

vector<int> bfs(int s, const vector<vector<int>> &graph) {
	const int n = graph.size();
	vector<int> dist(n, numeric_limits<int>::max());
	queue<int> que;
	dist[s] = 0;
	que.push(s);

	while(!que.empty()) {
		const int v = que.front();
		que.pop();

		for(const auto &to : graph[v]) {
			if(dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				que.push(to);
			}
		}
	}
	return dist;
}

void get_path(int v, vector<int> &path, const vector<vector<int>> &graph, const vector<int> &dist) {
	path.emplace_back(v);

	if(dist[v] == 0) return;
	for(const auto &to : graph[v]) {
		if(dist[to] + 1 == dist[v]) {
			get_path(to, path, graph, dist);
			return;
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int h, w, m;
	cin >> h >> w >> m;

	vector<string> field(h);
	for(auto &row : field) cin >> row;

	const auto graph = make_graph(field);
	const auto continue_cost = input_matrix(h, w);
	const auto turn_on_cost = input_matrix(h, w);
	const auto turn_off_cost = input_matrix(h, w);

	const int n = encoder.size();
	vector<vector<int>> dist;
	dist.reserve(n);
	for(int i = 0; i < n; ++i) {
		dist.emplace_back(bfs(i, graph));
	}

	vector<int> min_cost(n, 0);
	vector<int> last_time(n, -1);

	int current = input_index();
	min_cost[current] = turn_on_cost[current];
	last_time[current] = 0;

	int t = 0;
	while(--m) {
		const int next = input_index();
		vector<int> path;
		get_path(current, path, graph, dist[next]);

		for(unsigned i = 1; i < path.size(); ++i) {
			const int v = path[i];
			++t;
			if(last_time[v] == -1) {
				min_cost[v] = turn_on_cost[v];
			}
			else {
				min_cost[v] += min(turn_off_cost[v] + turn_on_cost[v], continue_cost[v] * (t - last_time[v]));
			}
			last_time[v] = t;
		}

		current = next;
	}

	int ans = 0;
	for(int v = 0; v < n; ++v) {
		if(last_time[v] != -1) ans += min_cost[v] + turn_off_cost[v];
	}

	cout << ans << endl;

	return EXIT_SUCCESS;
}