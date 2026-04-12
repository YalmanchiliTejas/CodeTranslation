#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <memory>
#include <sstream>
#include <iomanip>

using namespace std;

int n, m;
int ans = 0;

class node {
public:
	bool flag;
	vector<int> ptr;
	node() {
		flag = false;
	}
};


void f(vector<node>& graph, int i) {
	graph[i].flag = true;
	int k = 0;
	for (int j = 0; j < graph[i].ptr.size(); j++) {
		if (!graph[graph[i].ptr[j]].flag) {
			k++;
			f(graph, graph[i].ptr[j]);
		}
	}
	//端のとき
	if (k == 0) {
		bool tmp = true;
		for (int i = 0; i < n; i++) {
			if (!graph[i].flag) {
				tmp = false;
				break;
			}
		}
		if (tmp)ans++;
	}
	graph[i].flag = false;
	return;
}


int main() {
	cin >> n >> m;
	vector<node> graph(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].ptr.emplace_back(b-1);
		graph[b-1].ptr.emplace_back(a-1);
	}
	
	f(graph, 0);

	cout << ans << endl;

	return 0;
}
