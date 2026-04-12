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
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

VI g[100010];
int cnt[100010];
signed main(void)
{
	int n;
	cin >> n;
	REP(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].PB(b);
		g[b].PB(a);
		cnt[a]++;
		cnt[b]++;
	}

	set<int> s;
	REP(i, n) if(cnt[i] == 1) s.insert(i);

	bool used[100010] = {false};
	while(s.size()) {
		int h = *s.begin(); s.erase(s.begin());
		REP(i, g[h].size()) {
			if(used[g[h][i]]) continue;
			used[h] = used[g[h][i]] = true;
			REP(j, g[h].size()) if(!used[g[h][j]]) {
				cnt[g[h][j]]--;
				if(cnt[g[h][j]] == 0) {cout << "First" << endl; return 0;}
				if(cnt[g[h][j]] == 1) {s.insert(g[h][j]);}
			}
			REP(j, g[g[h][i]].size()) if(!used[g[g[h][i]][j]]) {
				cnt[g[g[h][i]][j]]--;
				if(cnt[g[g[h][i]][j]] == 0) {cout << "First" << endl; return 0;}
				if(cnt[g[g[h][i]][j]] == 1) {s.insert(g[g[h][i]][j]);}
			}
			break;
		}
	}
	cout << "Second" << endl;
	return 0;
}
