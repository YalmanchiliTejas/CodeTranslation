#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<map>
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define Endl endl
#define F first
#define S second

namespace mp = boost::multiprecision;

using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

ll ans = 0;
void dfs(int n,  int count, vector<int>path,
	vector<vector<int>>map) {
	if (count == path.size()) {
		ans++;
	}
	else {
		for (int i = 1; i < path.size(); i++) {
			if (map[n][i] == 1 && path[i] == 0) {
				path[i]++;
				count++;
				dfs(i,count, path, map);				
				path[i] = 0;
				count--;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(n, vector<int>(n,0));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		map[a][b]++;
		map[b][a]++;
	}

	vector<int>path(n,0);
	path[0] = 1;
	dfs(0, 1, path, map);
	cout << ans << endl;
}
