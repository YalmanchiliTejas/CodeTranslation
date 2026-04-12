#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;
const long double EPS = 1e-7;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<set<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--;
		R--;
		edge[L].insert(R);
		edge[R].insert(L);
	}
	queue<int>Q;
	int three = 0;
	for (int i = 0; i < N; i++) {
		if (edge[i].size() == 1)Q.push(i);
		else if (edge[i].size() >= 3)three++;
	}
	while (three) {
		if (Q.empty()) {
			cout << "First\n";
			return 0;
		}
		vector<vector<int>>parent(N);
		set<int>nxq;
		while (!Q.empty()) {
			int cn = Q.front();
			int node = 0;
			int n = cn;
			int nx = n;
			int depth = 0;
			Q.pop();
			while (edge[nx].size() < 2) {
				node++;
				n = nx;
				nx = *edge[n].begin();
				edge[n].erase(nx);
				edge[nx].erase(n);
			}
			if (edge[nx].size() == 2)three--;
			if (node % 2) {
				edge[n].insert(nx);
				edge[nx].insert(n);
				if (edge[nx].size() == 3)three++;
				parent[nx].push_back(n);
			}
			if (edge[nx].size() == 2)nxq.insert(nx);
			if (!three) {
				node = 0;
				for (auto i : edge)if (i.size() == 2)node++;
				if (node % 2)cout << "First\n";
				else cout << "Second\n";
				return 0;
			}
		}
		//for (auto i : nxq) {
		//	if (edge[i].size() == 2) {
		//		for (auto j : parent[i])Q.push(j);
		//	}
		//	if (edge[i].size() == 1)Q.push(i);
		//}
		for (int i = 0; i < N; i++) {
			if (edge[i].size() == 1)Q.push(i);
		}
		if (clock() > CLOCKS_PER_SEC * 1900 / 1000) {
			cout << "First\n";
			return 0;
		}
	}
	int node = 0;
	for (auto i : edge)if (i.size() == 2)node++;
	if (node % 2)cout << "First\n";
	else cout << "Second\n";
	return 0;
}
