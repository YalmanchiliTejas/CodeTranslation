#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>

using namespace std;

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = n;i >= m;i--)
#define REPO(i, n) for(int i = 1;i <= n;i++)
#define ll long long
#define INF 999999999
#define MINF -999999999
#define ALL(n) n.begin(),n.end()
#define MP make_pair
#define F first
#define S second

int main() {
	int n, m, x[8] = { 1,2,3,4,5,6,7,8 }, ans = 0;
	bool l[10][10] = {};
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		l[a][b] = true;
		l[b][a] = true;
	}
	do {
		bool a = {};
		REP(i, n - 1) if (!l[x[i]][x[i + 1]]) a = true;
		if (!a) ans++;
	} while (next_permutation(x + 1, x + n));
	cout << ans << endl;
}