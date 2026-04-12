#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;


int n;
vector<vector<int>> g;

int solve(int isTraveled,int pos) {
	int cnt = 0;
	if (isTraveled == (1 << n) - 1) {
		return 1;
	}
	for (int i = 0; i < n; i++) {
		
		if (g[pos][i] == 1 && (isTraveled >> i & 1) == 0) {
			cnt += solve(isTraveled +( 1 << i), i);
		}
	}
	return cnt;
}

int main() {
	int m;
	cin >> n >> m;
	
	g = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;

		b--;
		g[a][b] = 1;
		g[b][a] = 1;
	}

	int ans = solve(1, 0);
	cout << ans << endl;
	
}
