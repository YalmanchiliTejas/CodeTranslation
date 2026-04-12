#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define REPI(i, s, e) for (int i = (s); i <= (e); i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

#define dump(x) (cout << #x << " = " << x << endl)
#define dump2(x, y) (cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl)

typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	int m;
	cin >> m;
	rep(t, m) {
		int budget, year, n;
		cin >> budget >> year >> n;
		int ans = 0;
		rep(i, n) {
			int type, cost;
			double rate;
			cin >> type >> rate >> cost;

			if (type == 1) {
				int A = budget;
				rep(j, year) {
					int B  = A * rate;
					int zandaka = A+B - cost;
					A = zandaka;
				}
				ans = max(ans, A);
			} else {
				int A = budget;
				int risi = 0;
				rep(j, year) {
					int B  = A * rate;
					int zandaka = A - cost;
					A = zandaka;
					risi += B;
				}
				A += risi;
				ans = max(ans, A);
			}
		}
		cout << ans << endl;
	}
	return 0;
}