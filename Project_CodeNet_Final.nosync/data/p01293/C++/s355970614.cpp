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

pair<char, int> c[4][13];
signed main(void)
{
	while(1) {
		char t;
		cin >> t;
		if(t == '#') break;
		REP(i, 4) REP(j, 13) {
			string a;
			cin >> a;
			int tmp = -1;
			if('2' <= a[0] && a[0] <= '9') tmp = a[0] - '0' - 1;
			else if(a[0] == 'A') tmp = 13;
			else if(a[0] == 'T') tmp = 9;
			else if(a[0] == 'J') tmp = 10;
			else if(a[0] == 'Q') tmp = 11;
			else if(a[0] == 'K') tmp = 12;
			//cout << tmp << " ";
			c[i][j] = {a[1], tmp};
		}
		//cout << endl;

		int fir = 0, ns = 0, ew = 0;
		REP(i, 13) {
			char l = c[fir][i].first;
			bool tr = false;
			int ma = 0, id = -1;
			REP(j, 4) {
				//cout << c[j][i].first << " " << c[j][i].second << endl;
				if(c[j][i].first == t && (!tr || (tr && ma < c[j][i].second))) {
					tr = true;
					ma = c[j][i].second;
					id = j;
				} else if(!tr && c[j][i].first == l && ma < c[j][i].second) {
					ma = c[j][i].second;
					id = j;
				}
			}
			if(id == 0 || id == 2) ns++;
			else ew++;
			//cout << "win:" << id << endl;
			fir = id;
		}
		//cout << endl;
		if(ns > ew) cout << "NS " << ns-6 << endl;
		else cout << "EW " << ew-6 << endl;
	}

	return 0;
}