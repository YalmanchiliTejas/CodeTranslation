#include<iostream>
#include<string>
#include<cmath>
#include<array>
#include<algorithm>
//#include<deque>
#include<vector>
//#include<utility>
#include<set>
//#include<map>
//#include<list>

using namespace std;
using LLI = long long int;

//class UnionFind {
//public:
//	vector<int>data;
//	UnionFind(int size) :data(size, -1) {};
//	bool unionset(int x, int y) {
//		x = root(x), y = root(y);
//		if (x != y) {
//			if (data[y] < data[x]) {
//				swap(x, y);
//			}
//			data[x] += data[y];
//			data[y] = x;
//		}
//		return x != y;
//	}
//	bool findset(int x, int y) {
//		return root(x) == root(y);
//	}
//	int root(int x) {
//		return data[x] < 0 ? x : data[x] = root(data[x]);
//	}
//	int size(int x) {
//		return -data[root(x)];
//	}
//};

//int gcd(int x, int y) {
//	int tmp, r;
//	if (x < y) {
//		tmp = x;
//		x = y;
//		y = tmp;
//	}
//	r = x % y;
//	while (r != 0) {
//		x = y;
//		y = r;
//		r = x % y;
//	}
//	return y;
//}

//vector<vector<int>>sub;
//int dfs(int id) {
//	if (sub[id].size() == 0) {
//		return 1;
//	}
//	int minP = (int)1e9;
//	int maxP = 0;
//	for (int i : sub[id]) {
//		int P = dfs(i);
//		minP = min(minP, P);
//		maxP = max(maxP, P);
//	}
//	return minP + maxP + 1;
//}

const int n_max = 8;
array<array<bool, n_max>, n_max>graph;
int dfs(int v,int N,array<bool,n_max>visited) {
	int ret = 0;
	bool all_visited = true;
	for (int i = 0; i < N;i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}
	if (all_visited) {
		return 1;
	}
	for (int i = 0; i < N;i++) {
		if (graph[v][i] == false) {
			continue;
		}
		if (visited[i] == true) {
			continue;
		}
		visited[i] = true;
		ret += dfs(i,N,visited);
		visited[i] = false;
	}
	return ret;
}

int main(void) {
	int N, M;
	cin >> N >> M;


	for (int i = 0; i < M;i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}
	array<bool, n_max>visited;
	for (int i = 0; i < N;i++) {
		visited[i] = false;
	}
	visited[0] = true;
	cout << dfs(0,N,visited) << endl;

	return 0;
}