#include <stdio.h>
#include <vector>

using namespace std;

const int N = 4 * 100004;
const long long inf = 1000000000;
const int M = 1000000007;

struct edge {
	int to, from;
	long long weight;
};

vector<edge> edges[N];
int n, m;

int heap[N];
int inHeap[N];
int heapSize = 0;

long long d[2][N];
long long f[2][N];
long long cnt[2][N];

void addEdge(int from, int to, long long weight) {
	edge e; e.to = to; e.weight = weight;
	e.from = from;
	edges[from].push_back(e);
}

void exchangeHeap(int x, int y) {
	int h = heap[x];
	heap[x] = heap[y];
	heap[y] = h;

	inHeap[heap[x]] = x;
	inHeap[heap[y]] = y;
}

void heapUp(int x, int c) {
	x = inHeap[x];
	int pred = x / 2;
	if (pred >= 1 && d[c][heap[pred]] > d[c][heap[x]]) {
		exchangeHeap(pred, x);
		heapUp(heap[pred], c);
	}
}

void downHeap(int x, int c) {

	x = inHeap[x];

	int first = x * 2;
	int second = x * 2 + 1;
	int best = -1;

	if (first <= heapSize && d[c][heap[x]] > d[c][heap[first]]) {
		best = first;
	}

	if (second <= heapSize && d[c][heap[x]] > d[c][heap[second]] && d[c][heap[first]] > d[c][heap[second]]) {
		best = second;
	}

	if (best != -1) {
		exchangeHeap(x, best);
		downHeap(heap[best], c);
	}
}

void Relax(edge e, long long distance, int c) {
	if (d[c][e.to] == distance + e.weight && f[c][e.to] == 0) {
		cnt[c][e.to] = (cnt[c][e.to] + cnt[c][e.from]) % M;
	}
	if (d[c][e.to] > distance + e.weight && f[c][e.to] == 0) {
		d[c][e.to] = distance + e.weight;
		
		cnt[c][e.to] = cnt[c][e.from];
		heapUp(e.to, c);
	}
}

void Dijkstra(int s, int t, int c) {
	for (int i = 0; i <= n; i++) {
		inHeap[i] = i;
		heap[i] = i;
		d[c][i] = inf * inf;
		f[c][i] = 0;
	}
	d[c][s] = 0;
	cnt[c][s] = 1;
	heapSize = n;
	heapUp(s, c);

	while (true) {
		int x = heap[1];
		//printf("!%d %d %d\n", x, d[c][x], cnt[c][x]);
		exchangeHeap(1, heapSize);
		heapSize--;
		if (heapSize == 0) break;
		downHeap(heap[1], c);
		f[c][x] = 1;
		for (int i = 0; i < edges[x].size(); i++) {
			Relax(edges[x][i], d[c][x], c);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int s, t;
	scanf("%d%d", &s, &t);
	for (int i = 0; i < m; i++) {
		int x, y;
		long long w;
		scanf("%d%d%lld", &x, &y, &w);
		addEdge(x, y, w);
		addEdge(y, x, w);
	}

	Dijkstra(s, t, 0);
	Dijkstra(t, s, 1);

	long long shortest = d[0][t];
	int totalCount = 0;

	for (int i = 1; i <= n; i++) {
		//printf("!%d %d %d\n", i, d[0][i], d[1][i]);
		if (d[0][i] == d[1][i] && shortest == d[0][i] + d[1][i]) {
			long long h = ((long long)cnt[0][i] * (long long)cnt[1][i]) % M;
			totalCount = (totalCount + (h * h) % M) % M;
		}

		for (int j = 0; j < edges[i].size(); j++) {
			if ((
					d[0][i] <= d[1][edges[i][j].to] &&
					d[0][i] + edges[i][j].weight > d[1][edges[i][j].to] ||
					d[0][i] >= d[1][edges[i][j].to] &&
					d[0][i] < edges[i][j].weight + d[1][edges[i][j].to]
				) && d[0][i] + edges[i][j].weight + d[1][edges[i][j].to] == shortest) {
				
				long long h = ((long long)cnt[0][i] * (long long)cnt[1][edges[i][j].to]) % M;

				totalCount = (totalCount + (h * h) % M) % M;
			
			}
		}

	}

	//printf("%lld %d\n", cnt[0][t], totalCount);
	long long ans = ((long long)(cnt[0][t]) * (long long)(cnt[0][t])) % M - totalCount;
	//long long ans = (long long)(cnt[0][t]) % M - totalCount;
	while (ans < 0) {
		ans += M;
	}
	//printf("%d %d\n", d[0][t], d[1][s]);
	printf("%lld\n", ans);

	return 0;
}

/*

8 13
4 2
7 3 9
6 2 3
1 6 4
7 6 9
3 8 9
1 2 2
2 8 12
8 6 9
2 5 5
4 2 18
5 3 7
5 1 515371567
4 8 6

===========================================

4 4
1 3
1 2 1
2 3 1
3 4 1
4 1 1

7 8
1 7
1 2 1
2 4 1
1 3 1
3 4 1
4 5 1
4 6 1
6 7 1
5 7 1

*/