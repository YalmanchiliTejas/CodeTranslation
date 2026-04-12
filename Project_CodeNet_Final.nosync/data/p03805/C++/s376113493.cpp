#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <numeric>
#include <math.h>
#include <algorithm>
#include <functional>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define full(c) c.begin(), c.end()
typedef unsigned long long int ull;
using namespace std;

struct Node{
	int id;
	vector <int> next;
};
void dfs(vector<Node> &node, int src, int &cnt, int n){
	static vector<int> rt;
	static vector<bool> flag(n + 1, false);
	rt.push_back(src);
	flag[src] = true;
	for (int nx : node[src].next){
		if (flag[nx] == false) dfs(node, nx, cnt, n);
	}
	flag[src] = false;
	if (rt.size() == n) cnt++;
	rt.pop_back();
}
int main(){
	int k, i, n, m, cnt = 0;
	cin >> n >> m;
	vector <Node> node(n + 1);
	for (i = 0; i <= n; i++) node[i].id = i;
	for (i = 0; i<m; i++){
		int a, b;
		cin >> a >> b;
		node[a].next.push_back(b);
		node[b].next.push_back(a);
	}
	dfs(node, 1, cnt, n);
	cout << cnt << endl;
	return 0;
}

