#include<iostream>
#include<string>
#include<cmath>
#include<math.h>
//#include<array>
#include<algorithm>
//#include<queue>
#include<deque>
#include<vector>
//#include<utility>
//#include<set>
//#include<map>
//#include<list>
//#include<bitset>
//#include<iomanip>

using namespace std;
using LLI = long long int;
LLI N;

//array<int, 8>dir_x = { 0,0,1,1,1,-1,-1,-1 };
//array<int, 8>dir_y = { 1,-1,1,0,-1,1,0,-1 };
//array<int, 4>dir_x2 = { 0,0,1,-1 };
//array<int, 4>dir_y2 = { 1,-1,0,0 };
//char alp[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

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

//LLI gcd(LLI x, LLI y) {
//	LLI  r;
//	if (x < y) {
//		swap(x, y);
//	}
//	r = x % y;
//	while (r != 0) {
//		x = y;
//		y = r;
//		r = x % y;
//	}
//	return y;
//}
//LLI lcm(LLI x, LLI y) {
//	return x / gcd(x, y) * y;
//}

//long nCr(int n, int r) {
//	long ans = 1;
//	for (int i = n; i > n - r; i--) {
//		ans = ans * i;
//	}
//	for (int i = 1; i < r + 1; i++) {
//		ans = ans / i;
//	}
//	return ans;
//}
//long nHr(int n, int r) {
//	n = n + r - 1;
//	return nCr(n, r);
//}

//const int n_max = 8;
//array<array<bool, n_max>, n_max>graph;
//int dfs(int v,int N,array<bool,n_max>visited) {
//	int ret = 0;
//	bool all_visited = true;
//	for (int i = 0; i < N;i++) {
//		if (visited[i] == false) {
//			all_visited = false;
//		}
//	}	
//	if (all_visited) {
//		return 1;
//	}
//	for (int i = 0; i < N;i++) {
//		if (graph[v][i] == false) {
//			continue;
//		}
//		if (visited[i] == true) {
//			continue;
//		}
//		visited[i] = true;
//		ret += dfs(i,N,visited);
//		visited[i] = false;
//	}
//	return ret;
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

//#define debug(x) cerr << #x << " : " << x << endl
//#define debugv(x) cerr << #x << " : "; for(auto i:x) cerr << i << ", "; cerr<<endl

int main(void) {
	LLI X;
	cin >> X;
	if (X == 5 || X == 3 || X == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}