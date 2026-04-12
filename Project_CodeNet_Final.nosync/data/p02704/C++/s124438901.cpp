#include <stdio.h>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

struct MaxFlowDinic {
	typedef long long cap_t;

	struct Edge
	{
		int next;
		int inv; /* inverse edge index */
		cap_t res; /* residual */
		cap_t save; /* save whatever you want. TODO: just remove if you don't need */
	};

	int n;
	vector<vector<Edge>> graph;

	vector<int> q, l, start;

	void init(int _n) {
		n = _n;
		graph.resize(n);
		for (int i = 0; i < n; i++) graph[i].clear();
	}
	void addNodes(int count) {
		n += count;
		graph.resize(n);
	}

	void addEdgeSave(int s, int e, cap_t cap, cap_t save) {
		Edge forward = { e, (int)graph[e].size() + (s == e ? 1 : 0), cap, save };
		Edge reverse = { s, (int)graph[s].size(), 0, -1 };
		graph[s].push_back(forward);
		graph[e].push_back(reverse);
	}

	void addEdge(int s, int e, cap_t cap, cap_t caprev = 0) {
		Edge forward = { e, (int)graph[e].size() + (s == e ? 1 : 0), cap, -1 };
		Edge reverse = { s, (int)graph[s].size(), caprev, -1 };
		graph[s].push_back(forward);
		graph[e].push_back(reverse);
	}

	bool assignLevel(int source, int sink) {
		int t = 0;
		l.assign(n, 0);
		l[source] = 1;
		q[t++] = source;
		for (int h = 0; h < t && !l[sink]; h++) {
			int cur = q[h];
			for (const auto &edge : graph[cur]) {
				int next = edge.next;
				if (l[next]) continue;
				if (edge.res > 0) {
					l[next] = l[cur] + 1;
					q[t++] = next;
				}
			}
		}
		return l[sink] != 0;
	}

	cap_t blockFlow(int cur, int sink, cap_t currentFlow) {
		if (cur == sink) return currentFlow;
		for (auto &i = start[cur]; i < (int)graph[cur].size(); i++) {
			int next = graph[cur][i].next;
			if (graph[cur][i].res == 0 || l[next] != l[cur] + 1)
				continue;
			if (cap_t res = blockFlow(next, sink, min(graph[cur][i].res, currentFlow))) {
				int inv = graph[cur][i].inv;
				graph[cur][i].res -= res;
				graph[next][inv].res += res;
				return res;
			}
		}
		return 0;
	}

	cap_t solve(int source, int sink)
	{
		if (source == sink) {
			// invalid case
			return -1;
		}
		q.resize(n);
		l.resize(n);
		cap_t ans = 0;
		while (assignLevel(source, sink)) {
			start.assign(n, 0);
			while (cap_t flow = blockFlow(source, sink, numeric_limits<cap_t>::max())) {
				ans += flow;
			}
		}
		return ans;
	}
};

// Finding actual instance:
// (capacity - edge.res) is the actual flow that is flown in this problem.
struct MaxFlowEdgeDemand {
	typedef MaxFlowDinic::cap_t cap_t;
	MaxFlowDinic mf;

	vector<cap_t> nodeSum;

	void init(int _n) {
		mf.init(_n + 2);
		nodeSum.resize(_n + 2);
	}

	void addNodes(int count) {
		mf.addNodes(count);
		nodeSum.resize(mf.n + 2);
	}

	void addEdgeSave(int s, int e, cap_t demand, cap_t capacity, cap_t save) {
		mf.addEdgeSave(s + 2, e + 2, capacity - demand, save);
		nodeSum[s + 2] -= demand;
		nodeSum[e + 2] += demand;
	}

	void addEdge(int s, int e, cap_t demand, cap_t capacity) {
		mf.addEdge(s + 2, e + 2, capacity - demand);
		nodeSum[s + 2] -= demand;
		nodeSum[e + 2] += demand;
	}

	// true if possible
	bool solveCirculation() {
		cap_t saturation = 0;
		for (int i = 2; i < (int)nodeSum.size(); i++) {
			auto cap = nodeSum[i];
			if (cap == 0) continue;
			if (cap < 0) {
				mf.addEdge(i, 1, -cap);
			}
			else if (cap > 0) {
				mf.addEdge(0, i, cap);
				saturation += cap;
			}
		}
		cap_t result = mf.solve(0, 1);
		return result == saturation;
	}

	// -1 if it is impossible to satisfy demand
	// return max flow.
	cap_t solveMax(int source, int sink) {
		mf.addEdge(sink + 2, source + 2, numeric_limits<cap_t>::max());
		cap_t saturation = 0;
		for (int i = 2; i < (int)nodeSum.size(); i++) {
			auto cap = nodeSum[i];
			if (cap == 0) continue;
			if (cap < 0) {
				mf.addEdge(i, 1, -cap);
			}
			else if (cap > 0) {
				mf.addEdge(0, i, cap);
				saturation += cap;
			}
		}
		cap_t result = mf.solve(0, 1);
		if (result != saturation) {
			return -1;
		}
		cap_t maxFlow = mf.solve(source + 2, sink + 2);
		return maxFlow;
	}
};

int N, S[505], T[505], u[505], v[505]; unsigned long long U[505], V[505], A[505][505];

int main()
{
	scanf ("%d", &N);
	for (int i = 0; i < N; i++) scanf ("%d", &S[i]);
	for (int i = 0; i < N; i++) scanf ("%d", &T[i]);
	for (int i = 0; i < N; i++) scanf ("%llu", &U[i]);
	for (int i = 0; i < N; i++) scanf ("%llu", &V[i]);

	if (N == 1){
		if (U[0] != V[0]) puts("-1");
		else printf ("%llu\n", U[0]);
		return 0;
	}

	for (int k = 0; k < 64; k++){
		for (int i = 0; i < N; i++){
			u[i] = (U[i] & (1ull << k)) > 0;
			v[i] = (V[i] & (1ull << k)) > 0;
		}

		MaxFlowEdgeDemand mf;
		mf.init(N * 2 + 2);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) mf.addEdge(i, j + N, 0, 1);
		for (int i = 0; i < N; i++){
			if (S[i] == 0){
				if (u[i] == 0) mf.addEdge(N * 2, i, 0, N - 1);
				else mf.addEdge(N * 2, i, N, N);
			}
			else{
				if (u[i] == 0);
				else mf.addEdge(N * 2, i, 1, N);
			}
		}
		for (int j = 0; j < N; j++){
			if (T[j] == 0){
				if (v[j] == 0) mf.addEdge(j + N, N * 2 + 1, 0, N - 1);
				else mf.addEdge(j + N, N * 2 + 1, N, N);
			}
			else{
				if (v[j] == 0);
				else mf.addEdge(j + N, N * 2 + 1, 1, N);
			}
		}

		auto res = mf.solveMax(N * 2, N * 2 + 1);
		if (res == -1){
			puts("-1");
			return 0;
		}

		for (int i = 0; i < N; i++){
			for (auto &e : mf.mf.graph[i+2]){
				if (N+2 <= e.next && e.next < N * 2+2 && !e.res) A[i][e.next - N-2] |= (1ull << k);
			}
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) printf ("%llu ", A[i][j]);
		puts("");
	}
	return 0;
}