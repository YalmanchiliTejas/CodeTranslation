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
void dfs(int n, vector<int>a,
	vector<vector<int>>ab, int count,int def) {
	if (count == def) {
		ans++;

	}
	else {
		for (int i = 0; i < a.size(); i++) {
			if (ab[n][i] == 1 && a[i] == 0) {
				a[i]++;
				count++;
				dfs(i, a, ab, count, def);
				count--;
				a[i] = 0;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(8, vector<int>(8,0));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		map[a][b]++;
		map[b][a]++;
	}
	int count = 1;
	vector<int>path(8,0);
	path[0] = 1;
	dfs(0, path, map, count,n);
	cout << ans << endl;
}
