#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int NMAX = 60;

int N, M;
int inNode[NMAX * NMAX], outNode[NMAX * NMAX];
char grid[NMAX][NMAX];

struct FlowEdge {
	int x, y, flow, capacity;
	FlowEdge *rev;
	FlowEdge(int x, int y, int flow, int capacity, FlowEdge *rev = NULL):
		x(x),
		y(y),
		flow(flow),
		capacity(capacity),
		rev(rev) {
	}
};
vector<FlowEdge *> FN[4 * NMAX * NMAX];

void addFlowEdge(int x, int y, int capacity) {
	FlowEdge *newEdge = new FlowEdge(x, y, 0, capacity);
	FlowEdge *revEdge = new FlowEdge(y, x, 0, 0, newEdge);
	newEdge->rev = revEdge;
	FN[x].push_back(newEdge);
	FN[y].push_back(revEdge);
}

bool bfsWitness[4 * NMAX * NMAX];
FlowEdge *from[4 * NMAX * NMAX];
bool hasAugumentingPath(int source, int sink) {
	memset(bfsWitness, 0, sizeof bfsWitness);
	queue<int> Q;
	Q.push(source);
	bfsWitness[source] = 1;
	from[source] = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (auto it: FN[now]) {
			if (bfsWitness[it->y] || it->flow >= it->capacity)
				continue;
			bfsWitness[it->y] = 1;
			from[it->y] = it;
			Q.push(it->y);
			if (it->y == sink)
				goto _breakLoop;
		}
	}
_breakLoop:
	return bfsWitness[sink];
}

int main() {
//	assert(freopen("debug.in", "r", stdin));
// assert(freopen("debug.out", "w", stdout));

	int i, j;

	cin >> N >> M;
	while (N != 0 || M != 0) {
		for (i = 1; i <= N; ++i)
			cin >> (grid[i] + 1);

		int lastNode = N * M + 1;
		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= M; ++j) {
				inNode[(i - 1) * M + j] = lastNode++;
				outNode[(i - 1) * M + j] = lastNode++;
				addFlowEdge(inNode[(i - 1) * M + j], (i - 1) * M + j, 1);
				addFlowEdge((i - 1) * M + j, outNode[(i - 1) * M + j], 1);
			}
		}

		for (i = 1; i <= N; ++i) {
			for (j = 1; j <= M; ++j) {
				for (int d = 0; d < 4; ++d) {
					int newX = i + dx[d];
					int newY = j + dy[d];
					if (newX < 0 || newX > N || newY < 0 || newY > M || grid[newX][newY] != '.')
						continue;
					addFlowEdge(outNode[(i - 1) * M + j], inNode[(newX - 1) * M + newY], 1);
				}
			}
		}

		FN[1][1]->capacity = 2;
		FN[inNode[1]][0]->capacity = 0;
		FN[N * M][1]->capacity = 0;
		FN[inNode[N * M]][0]->capacity = 2;

		int maxFlow = 0;
		while (hasAugumentingPath(1, N * M)) {
			FlowEdge *currEdge = from[N * M];
			while (currEdge) {
				++currEdge->flow;
				--currEdge->rev->flow;
				currEdge = from[currEdge->x];
			}
			++maxFlow;
		}

		if (maxFlow < 2) {
			cout << "NO\n";
			goto _continue;
		}

		for (i = 1; i < lastNode; ++i)
			for (auto it: FN[i])
				it->flow = 0;

		FN[1][1]->capacity = 1;
		FN[inNode[1]][0]->capacity = 1;
		FN[N * M][1]->capacity = 1;
		FN[inNode[N * M]][0]->capacity = 1;

		FN[(N - 1) * M + 1][1]->capacity = 2;
		FN[inNode[(N - 1) * M + 1]][0]->capacity = 0;
		FN[M][1]->capacity = 0;
		FN[inNode[M]][0]->capacity = 2;

		maxFlow = 0;
		while (hasAugumentingPath((N - 1) * M + 1, M)) {
			FlowEdge *currEdge = from[M];
			while (currEdge) {
				++currEdge->flow;
				--currEdge->rev->flow;
				currEdge = from[currEdge->x];
			}
			++maxFlow;
		}

		if (maxFlow < 2)
			cout << "NO\n";
		else
			cout << "YES\n";


_continue:
		for (i = 1; i < lastNode; ++i)
			for (auto it: FN[i])
				delete it;
		for (i = 1; i < lastNode; ++i)
			FN[i].clear();
		cin >> N >> M;
	}

	return 0;
}

