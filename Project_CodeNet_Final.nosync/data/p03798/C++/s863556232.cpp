#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
#define REP(i, n)           for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (int)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef long long           ll;
typedef pair<ll, ll>        P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
char getNextChar(char ansPrev, char ansNow, char call)
{
	char stChar;
	if (ansNow == 'S') {
		if (call == 'o') {
			stChar = (ansPrev == 'S') ? 'S' : 'W';
		} else {
			stChar = (ansPrev == 'S') ? 'W' : 'S';
		}
	} else {
		if (call != 'o') {
			stChar = (ansPrev == 'S') ? 'S' : 'W';
		} else {
			stChar = (ansPrev == 'S') ? 'W' : 'S';
		}
	}
	return stChar;
}

bool check(string &s, string &ans)
{
	REPN(i, 1, s.size() - 1) {
		ans += getNextChar(ans[i - 1], ans[i], s[i]);
	}

	int i = s.size() - 1;
	char stChar = getNextChar(ans[i - 1], ans[i], s[i]);
	if (ans[0] != stChar) {
		return false;
	}

	stChar = getNextChar(ans[i], ans[0], s[0]);
	return ans[1] == stChar;
}

int main()
{
	int N;
	string s;
	cin >> N >> s;
	string ans;

	ans = "SW";
	if (check(s, ans)) {
		cout << ans << endl;
		return 0;
	}
	ans = "SS";
	if (check(s, ans)) {
		cout << ans << endl;
		return 0;
	}
	ans = "WS";
	if (check(s, ans)) {
		cout << ans << endl;
		return 0;
	}
	ans = "WW";
	if (check(s, ans)) {
		cout << ans << endl;
		return 0;
	}

	cout << -1 << endl;
	return 0;
}

