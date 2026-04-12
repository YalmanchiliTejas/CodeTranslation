#include <iostream>
#include <algorithm> 
#include <cmath>
//#include <bitset>
//#include <deque>
#include <iterator>
#include <map> 
//#include <queue>
//#include <stack>
#include <string>
#include <vector>
#include <array>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>

using namespace std;

typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 

int n, m;
vector<vector<int>> v(8);
vector<bool> visited(8);

int dfs(int val, int count) {
	if (visited[val]) {
		return 0;
	}
	//cout << count << endl;
	if (count == n) {
		return 1;
	}
	visited[val] = 1;
	vector<bool> store = visited;
	int p = 0;
	for (auto x: v[val]) {
		p += dfs(x,count + 1);
		visited = store;
	}
	return p;
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout << dfs(0,1);
} 









