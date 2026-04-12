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

int a[15][15];
signed main(void)
{
	while(true) {
		string s;
		cin >> s;
		if(s == "#") break;

		int y = 0, x = 0;
		REP(i, s.size()) {
			int tmp;
			if('1' <= s[i] && s[i] <= '9') tmp = s[i]-'0';
			else if(s[i] == 'b') {tmp = 0; a[y][x] = 1; x++;}
			else {y++; x=0; continue;}
			while(tmp--) {a[y][x] = 0; x++;}
			//cout << i << " " << x << " " << y << endl;
		}

		int b, c, d, e;
		cin >> b >> c >> d >> e;
		a[b-1][c-1] = 0;
		a[d-1][e-1] = 1;

		/*REP(i, y+1) {
			REP(j, x) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}*/

		string ans = "";
		REP(i, y+1) {
			int cnt = 0;
			REP(j, x) {
				if(a[i][j]) {
					if(cnt != 0) ans += (char)('0' + cnt);
					ans += 'b';
					cnt = 0;
				}	else {
					cnt++;
				}
			}
			if(cnt != 0) ans += (char)('0' + cnt);
			if(i != y) ans += '/';
		}
		cout << ans << endl;
	}

	return 0;
}