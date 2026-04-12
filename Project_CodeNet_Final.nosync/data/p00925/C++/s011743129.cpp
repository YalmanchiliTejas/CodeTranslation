#define __USE_MINGW_ANSI_STDIO 0
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

VI a, b;
bool d[100010];
signed main(void)
{
	string s, t = "";
	int m;
	cin >> s >> m;
	REP(i, s.size()) {
		if(s[i] == '+') {
			a.PB(stoi(t));
			b.PB(1);
			t = "";
		} else if(s[i] == '*') {
			a.PB(stoi(t));
			b.PB(0);
			t = "";
		} else {
			t += s[i];
		}
	}
	a.PB(stoi(t));
	//for(int i: a) cout << i << " "; cout << endl;
	//for(int i: b) cout << i << " "; cout << endl;

	bool f1 = false, f2 = false;
	int c = a[0];
	REP(i, b.size()) {
		if(b[i]) {
			c += a[i+1];
		} else {
			c *= a[i+1];
		}
	}
	//cout << c << " ";
	if(c == m) f1 = true;

	VI e;
	bool con = false;
	c = 0;
	REP(i, b.size()) {
		if(!b[i]) {
			if(!con) c = a[i]*a[i+1];
			else c *= a[i+1];
			d[i] = d[i+1] = true;
			con = true;
		} else {
			e.PB(c);
			c = 0;
			con = false;
		}
	}
	e.PB(c);
	REP(i, a.size()) {
		if(!d[i]) e.PB(a[i]);
	}
	int ret = 0;
	for(int i: e) ret += i;
	//cout << ret << endl;
	//for(int i: e) cout << i << " "; cout << endl;
	if(ret == m) f2 = true;

	if(f1 && f2) cout << "U" << endl;
	else if(!f1 && !f2) cout << "I" << endl;
	else if(f1 && !f2) cout << "L" << endl;
	else if(!f1 && f2) cout << "M" << endl;
	else assert(false);

	return 0;
}