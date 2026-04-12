#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct edge {
	int to, cost;
	edge(int to_, int cost_) : to(to_), cost(cost_) {};
};
bool operator<(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}
using namespace std;
template<class Type>
std::vector<Type> shortest_path_dijkstra(std::vector<std::vector<edge> > &G, int s) {
	std::priority_queue<edge> que; que.push(edge(s, 0));
	std::vector<Type> ret(G.size(), std::numeric_limits<Type>::max()); ret[s] = 0;
	while (!que.empty()) {
		edge u = que.top(); que.pop();
		for (edge e : G[u.to]) {
			if (ret[e.to] > ret[u.to] + e.cost) {
				ret[e.to] = ret[u.to] + e.cost;
				que.push(edge(e.to, -ret[e.to]));
			}
		}
	}
	return ret;
}
std::vector<int> shortest_path_tree(std::vector<std::vector<edge> > &G, int s) {
	std::priority_queue<edge> que; que.push(edge(s, 0));
	std::vector<long long> ret(G.size(), std::numeric_limits<long long>::max()); ret[s] = 0;
	std::vector<int> res(G.size());
	while (!que.empty()) {
		edge u = que.top(); que.pop();
		for (edge e : G[u.to]) {
			if (ret[e.to] > ret[u.to] + e.cost) {
				ret[e.to] = ret[u.to] + e.cost;
				res[e.to] = u.to;
				que.push(edge(e.to, -ret[e.to]));
			}
		}
	}
	return res;
}
int n, a, b, w;
int main() {
	cin >> n;
	vector<vector<edge> > G(n);
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> w;
		G[a].push_back(edge(b, w));
		G[b].push_back(edge(a, w));
	}
	vector<int> v1 = shortest_path_dijkstra<int>(G, 0);
	int pos1 = max_element(v1.begin(), v1.end()) - v1.begin();
	vector<int> v2 = shortest_path_dijkstra<int>(G, pos1);
	int pos2 = max_element(v2.begin(), v2.end()) - v2.begin();
	vector<int> v3 = shortest_path_dijkstra<int>(G, pos2);
	vector<int> v4 = shortest_path_tree(G, pos1);
	vector<int> path = { pos2 };
	int pos = pos2;
	while (pos != pos1) {
		pos = v4[pos];
		path.push_back(pos);
	}
	vector<int> v5 = v2;
	for (int i = 0; i < n; i++) v5[i] = max(v5[i], v3[i]);
	for (int i = 0; i < n; i++) cout << v5[i] << endl;
	return 0;
}