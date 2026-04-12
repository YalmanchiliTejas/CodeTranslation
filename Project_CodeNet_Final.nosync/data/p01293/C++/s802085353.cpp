#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
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
		char trump;
		cin >> trump;
		if (trump == '#')break;
		vector<vector<string>> c(4, vector<string>(13));
		int ns = 0, ew = 0;
		int start = 0;
		REP(i, 4) {
			REP(j, 13) {
				cin >> c[i][j];
				if (c[i][j][0] == 'T')c[i][j][0] = '9' + 1;
				if (c[i][j][0] == 'J')c[i][j][0] = '9' + 2;
				if (c[i][j][0] == 'Q')c[i][j][0] = '9' + 3;
				if (c[i][j][0] == 'K')c[i][j][0] = '9' + 4;
				if (c[i][j][0] == 'A')c[i][j][0] = '9' + 5;
			}
		}
		REP(i, 13) {
			char led = c[start][i][1];
			int flag = 0;
			REP(j, 4) {
				if (c[j][i][1] == trump)flag = 1;
			}
			int win = 0, cmax = -1;
			if (flag) {
				REP(j, 4) {
					if (c[j][i][1] == trump) {
						if (cmax < c[j][i][0] - '0') {
							win = j;
							cmax = c[j][i][0] - '0';
						}
					}
				}
			}
			else {
				REP(j, 4) {
					if (c[j][i][1] == led) {
						if (cmax < c[j][i][0] - '0') {
							win = j;
							cmax = c[j][i][0] - '0';
						}
					}
				}
			}
			start = win;
			if (win == 0 || win == 2)ns++;
			else ew++;
		}

		if (ns > ew) {
			cout << "NS " << ns - 6 << endl;
		}
		else {
			cout << "EW " << ew - 6 << endl;
		}
	}
	return 0;
}