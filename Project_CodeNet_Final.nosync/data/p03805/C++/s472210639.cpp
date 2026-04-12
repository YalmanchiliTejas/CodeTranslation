//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int g[10][10];
signed main(void)
{
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a][b] = g[b][a] = 1;
	}

	VI v;
	REP(i, n) v.PB(i);
	int ans = 0;
	do {
		bool flag = true;
		if(v[0] != 0) continue;
		FOR(i, 1, n) {
			if(g[v[i]][v[i-1]] != 1) {
				flag = false;
			}
		}
		if(flag) {
			ans++;
			//for(int i: v) cout << i << " "; cout << endl;
		}
	} while(next_permutation(ALL(v)));

	cout << ans << endl;
	return 0;
}
