#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vi isdark(n,-1);
	vi d(m);
	REP(i, m) {
		cin >> d[i];
		d[i]--;
		isdark[d[i]] = i;
	}
	vvi v(n, vi(k));
	REP(i, n)REP(j, k) {
		cin >> v[i][j]; v[i][j]--;
	}
	vvi g(1 << m);
	REP(i, 1 << m) {
		REP(j, k) {
			int next = 0;
			REP(l, m) {
				if (i&(1 << l)) {
					int tmp = v[d[l]][j];
					if (isdark[tmp] >= 0)next |= (1 << isdark[tmp]);
				}
			}
			g[i].push_back(next);
		}
	}
	queue<int> q;
	q.push((1 << m )- 1);
	vi dist(1 << m, INF);
	dist[(1 << m) - 1] = 0;
	while (!q.empty()) {
		int p = q.front(); q.pop();
		REP(i, k) {
			if (dist[g[p][i]] > dist[p] + 1) {
				dist[g[p][i]] = dist[p] + 1;
				q.push(g[p][i]);
			}
		}
	}
	cout << dist[0] << endl;
}

