#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
#define modulo 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9

bool graph[9][9];
int N, M;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = true;
		graph[v2][v1] = true;
	}
}

bool check_pass(vector<int> v) {
	bool flag = true;
	for (int i = 0; i < v.size() - 1 && flag == true; i++) flag = graph[v[i]][v[i + 1]];
	return flag;
}

void solve() {
	int ans = 0;
	vector<int> v;
	for (int i = 1; i <= N; i++) v.push_back(i);
	do {
		ans += check_pass(v);
	} while (next_permutation(v.begin() + 1, v.end()));
	cout << ans << endl;
}


int main() {
	input();
	solve();

	return 0;
}