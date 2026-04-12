#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;

#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MAX_V 100000

#define MOD 1000000007L
#define INF 100000000000

const int VMAX = 100;

bool dist[VMAX][VMAX] = {};

signed main() {
	int V, E;
	cin >> V >> E;

	for (size_t i = 0; i < E ; i++) {
		for (size_t j = 0; j < E ; j++) {
			dist[i][j] = false;
			dist[j][i] = false;
		}
	}

	for (int i = 0; i < E; ++i) {
		int s, t;
		cin >> s >> t;
		dist[s - 1][t - 1] = true;
		dist[t - 1][s - 1] = true;
	}
	std::vector<int> v = {};
	for (size_t i = 0; i < V; i++) {
		v.push_back(i);
	}

	int c = 0;
  do {
		if (v[0] != 0) {
			continue;
		}
		bool ok = true;
		for (size_t i = 1; i < V && ok; i++) {
			ok = dist[v[i - 1]][v[i]];
		}
		c += ok;
  } while (std::next_permutation(v.begin(), v.end()));
	cout << c << endl;
}
