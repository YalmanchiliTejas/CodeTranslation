#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<=(end);i++)
#define REP(i, n) FOR(i,1,n)
#define IFOR(i, begin, end) for(int i=(end);i>=(begin);i--)
#define IREP(i, n) IFOR(i,1,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())

#define ll long long
using namespace std;

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;

int main()
{
	ll H, W;
	cin >> H >> W;

	vector<string> a(H + 1);

	FOR(j, 0, H - 1) {
		cin >> a[j];
	}


	int routestartprev = -1;
	int routeendprev = -1;
	if (a[0][0] == '.' || a[H - 1][W - 1] == '.') {
		cout << "Impossible" << endl;
		return 0;
	}
	FOR(i, 0, H - 1) {
		int routestart = -1;
		int routeend = -1;
		if (i == 0) {
			FOR(j, 0, W - 1) {
				if (a[i][j] == '#') {
					if (routestart == -1) routestart = j;
					if (routeend != -1) {
						cout << "Impossible" << endl;
						return 0;
					}
				} else {
					if (routestart > -1 && routeend == -1) routeend = j - 1;
				}
			}
			if (routestart == -1) {
				cout << "Impossible" << endl;
				return 0;
			}
			else if (routeend == -1) routeend = W - 1;
			routestartprev = routestart;
			routeendprev = routeend;
		}

		else {
				// cout<<i<<routeendprev<<endl;
			if (routeendprev > 0) {
				FOR(j, 0, routeendprev - 1) {
					if (a[i][j] == '#') {
						cout << "Impossible" << endl;
						return 0;

					}

				}
			}
			if (a[i][routeendprev] == '#') routestart = routeendprev;
			else {
				cout << "Impossible" << endl;
				return 0;

			}
			FOR(j, routestart, W - 1) {
				if (a[i][j] == '#' && routeend > -1) {
					cout << "Impossible" << endl;
					return 0;

				}
				if (a[i][j] == '.' && routeend == -1) {
					routeend = j - 1;

				}
			}
			if (routestart == -1) {
				cout << "Impossible" << endl;
				return 0;
			}
			else if (routeend == -1) routeend = W - 1;
			routestartprev = routestart;
			routeendprev = routeend;

		}
	}


	cout << "Possible" << endl;
	return 0;
}