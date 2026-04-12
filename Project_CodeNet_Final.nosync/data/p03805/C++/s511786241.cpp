#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define INF 2 << 29
using Graph = vector<vector<int>>;

int n, m;
vector<bool> visit(8);
Graph graph(8);

int solve(int x) {
	visit[x] = true;

	//base case
	bool f = true;
	rep(i, n) if (!visit[i]) f = false;
	if (f) return 1;

	int ans = 0;
	//search non-visited node
	for(auto i : graph[x]) {
		if (visit[i] == false) {
			ans += solve(i);
			visit[i] = false;
		}
	}
	return ans;
}

int main() {
	cin >> n >> m;
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	cout << solve(0) << endl;

}