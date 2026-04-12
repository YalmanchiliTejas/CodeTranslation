#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=n-1;i>=m;--i)
#define ALL(v) v.begin(),v.end()
#define PB(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	bool g[8][8];
	REP(i, n)REP(j, n)g[i][j] = false;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = true;
		g[b][a] = true;
	}
	vector<int> v(n);
	REP(i, n) {
		v[i] = i;
	}
	int cnt = 0;
	int f = 1;
	REP(i, n - 1) {
		if (!g[v[i]][v[i + 1]])f = 0;
	}
	if (f)cnt++;
	while(next_permutation(ALL(v))) {
		if (v[0] != 0)break;
		int flag = 1;
		REP(i, n-1) {
			if (!g[v[i]][v[i + 1]])flag = 0;
		}
		if (flag)cnt++;
	}
	cout << cnt << endl;
	return 0;
}
