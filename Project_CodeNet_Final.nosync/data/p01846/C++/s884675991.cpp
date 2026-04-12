#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[a]; if (a != v.size() - 1)cout << " "; else cout << endl; }
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
///(?´????????`)(?´????????`)(?´????????`)(?´????????`)(?´????????`)(?´????????`)///
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while (1) {
		string s;
		cin >> s;
		if (s[0] == '#')break;
		vector<string> v;
		string tmp;
		REP(i, s.size()) {
			if (s[i] == '/') {
				v.push_back(tmp);
				tmp = "";
			}
			else tmp += s[i];
		}
		v.push_back(tmp);
		int h = v.size();
		int w=0;
		REP(i, v[0].size()) {
			if (v[0][i] == 'b')w++;
			else w += (v[0][i] - '0');
		}
		vvi m(h, vi(w));
		REP(i, h) {
			int p = 0;
			REP(j, v[i].size()) {
				if (isdigit(v[i][j])) {
					REP(k, v[i][j] - '0') {
						m[i][p] = 0;
						p++;
					}
				}
				else {
					m[i][p] = 1;
					p++;
				}
			}
		}
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		m[c - 1][d - 1] = 1; m[a - 1][b - 1] = 0;
		REP(i, h) {
			int cnt = 0;
			if (i != 0)cout << '/';
			REP(j, w) {
				if (m[i][j] == 1) {
					if (cnt != 0)cout << cnt;
					cout << 'b';
					cnt = 0;
				}
				else cnt++;
			}
			if (cnt != 0)cout << cnt;
		}
		cout << endl;
	}
	return 0;
}