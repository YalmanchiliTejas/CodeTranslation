#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"

struct edge { int first,second,height; };
int dfs(const int now, const int from, vector<vector<edge>>&es) {



	int len = 0;
	for (auto& e : es[now]) {
		if (e.first == from)continue;
		else {
			if (e.height == -1) {
				e.height = dfs(e.first, now, es);
			}
				len = max(len, e.second + e.height);

		}
	}
	return len;
	
}

int main() {
	int N; cin >> N;
	vector < vector<edge>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c; cin >> a >> b >> c;
		edges[a].push_back(edge{ b, c,-1 });
		edges[b].push_back(edge{ a,c ,- 1});

	}
	vector<int>hs(N);
	for (int i = 0; i < N; ++i) {
		hs[i] = dfs(i, -1, edges);
		cout << hs[i] << endl;
	}
	return 0;
}