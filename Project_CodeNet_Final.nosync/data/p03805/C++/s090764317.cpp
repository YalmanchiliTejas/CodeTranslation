#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
 
#define FOR(idx, begin, end) for(int idx = (begin); idx < (end); ++idx)
#define DMP(x) cerr << #x << ": " << x << "\n"
 
using namespace std;
typedef long long lint;
const int MOD = 1000000007;
 
int main() {
 
	cin.tie(0);
 
	int N, M;
	cin >> N >> M;
 
	vector<int> visited(N, 0);
 
	vector<int> a(M), b(M);
	FOR(i, 0, M) cin >> a[i] >> b[i];
 
	vector<vector<int>> path(N, vector<int>(N, 0));
	FOR(i, 0, M) {
		path[a[i] - 1][b[i] - 1] = true;
		path[b[i] - 1][a[i] - 1] = true;
	}
 
	int ans = 0;
 
	stack<pair<int, vector<int>>> node;
	node.push({0, visited});
 
	while (!node.empty()) {
		
		auto now = node.top();
		now.second[now.first] = 1;
		node.pop();
 
		FOR(i, 0, N) {
			if (now.second[i] == 0 && path[now.first][i] == 1) {
 
				node.push({i, now.second});
			}
		}
 
		FOR(i, 0, N) {
 
			if (now.second[i] == 0) break;
			if (i == N - 1) ans++;
		}
	
	}
 
	cout << ans;
 
	return 0;
}