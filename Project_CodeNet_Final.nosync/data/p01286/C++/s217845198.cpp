#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Edge {
public:
	long long int to;
	long long int max_flow;
	long long int rev;
};

class Dinic {
	int V;
	bool directed;
public:
	vector<vector<Edge>>edge;
	vector<int>depth;
	vector<int>index;
	Dinic(int n, bool D) {
		n++;
		V = n;
		edge.resize(V);
		depth.resize(V);
		index.resize(V);
		directed = D;
		return;
	}
	void Add_Edge(int l, int r, int max_flow) {
		edge[l].push_back({ r,max_flow,(int)edge[r].size() });
		if (directed) {
			edge[r].push_back({ l,0,(int)edge[l].size() - 1 });
		}
		else {
			edge[r].push_back({ l,max_flow,(int)edge[l].size() - 1 });
		}
		return;
	}
	void Check_Depth(int s) {
		for (int i = 0; i < V; i++) {
			depth[i] = INT_MAX;
		}
		depth[s] = 0;
		queue<int>Q;
		Q.push(s);
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : edge[cn]) {
				if (i.max_flow > 0 && depth[i.to] == INT_MAX) {
					depth[i.to] = depth[cn] + 1;
					Q.push(i.to);
				}
			}
		}
		return;
	}
	long long int max_flow(int v, int g, long long int ret) {
		if (v == g) {
			return ret;
		}
		for (int i = index[v]; i < edge[v].size(); i++) {
			if (edge[v][i].max_flow > 0 && depth[v] < depth[edge[v][i].to]) {
				long long int d = max_flow(edge[v][i].to, g, min(ret, edge[v][i].max_flow));
				if (d > 0) {
					edge[v][i].max_flow -= d;
					edge[edge[v][i].to][edge[v][i].rev].max_flow += d;
					return d;
				}
			}
		}
		return 0;
	}
	long long int Solve(int s, int g) {
		long long int ret = 0;
		while (1) {
			Check_Depth(s);
			if (depth[g] == INT_MAX) {
				return ret;
			}
			for (int i = 0; i < V; i++) {
				index[i] = 0;
			}
			long long int add = 0;
			while ((add = max_flow(s, g, INT_MAX)) > 0) {
				ret += add;
			}
		}
		return ret;
	}
};

int main() {
	int H, W, C, M, NW, NC, NM;
	cin >> H >> W >> C >> M >> NW >> NC >> NM;
	while (H != -1) {
		int st = H + W + C + M;
		int gl = st + 1;
		int WF = gl + 1;
		int WS = WF + 1;
		int CF = WS + 1;
		int CS = CF + 1;
		int MF = CS + 1;
		int MS = MF + 1;
		int dif = MS + 1;
		Dinic dn(MS+H+W+C+M, true);
		for (int i = 0; i < H + W + C + M; i++) {
			dn.Add_Edge(i, dif + i, 1);
		}
		for (int i = 0; i < H; i++) {
			dn.Add_Edge(st, i, 1);
		}
		for (int i = H + W + C; i < H + W + C + M; i++) {
			dn.Add_Edge(i+dif, gl, 1);
			dn.Add_Edge(CS, i, 1);
		}
		for (int i = 0; i < H; i++) {
			dn.Add_Edge(i+dif, WF, 1);
		}
		dn.Add_Edge(WF, WS, NW);
		for (int i = H; i < H + W; i++) {
			dn.Add_Edge(i+dif, CF, 1);
		}
		dn.Add_Edge(CF, CS, NC);
		for (int i = H + W; i < H + W + C; i++) {
			dn.Add_Edge(WS, i, 1);
			dn.Add_Edge(i+dif, MF, 1);
		}
		dn.Add_Edge(MF, MS, NM);
		dn.Add_Edge(MS, gl, NM);
		for (int i = H; i < H + W; i++) {
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				int N;
				cin >> N;
				N--;
				dn.Add_Edge(N+dif, i, 1);
			}
		}
		for (int i = H + W; i < H + W + C; i++) {
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				int N;
				cin >> N;
				N--;
				N += H;
				dn.Add_Edge(N+dif, i, 1);
			}
		}
		for (int i = H + W + C; i < H + W + C + M; i++) {
			int num;
			cin >> num;
			for (int j = 0; j < num; j++) {
				int N;
				cin >> N;
				N--;
				N += H + W;
				dn.Add_Edge(N+dif, i, 1);
			}
		}
		cout << dn.Solve(st, gl) << endl;
		cin >> H >> W >> C >> M >> NW >> NC >> NM;
	}
	return 0;
}
