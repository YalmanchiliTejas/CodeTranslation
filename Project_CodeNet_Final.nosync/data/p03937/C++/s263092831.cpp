#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i=s;i<n;i++)
#define repe(i,s,n)for(ll i=s;i<=n;i++)

static const double PI = 3.14159265358979;
static const ll MOD = 1e9 + 7;
static const ll INF = (ll)1 << 62;

int main() {
	ll h, w; cin >> h >> w;
	char c[10][10] = {};
	bool v[10][10];

	repe(i, 0, h + 1) repe(j, 0, w + 1) c[i][j] = '.';

	repe(i, 1, h) {
		repe(j, 1, w) {
			cin >> c[i][j];
		}
	}
	repe(i, 1, h) {
		repe(j, 1, w) {
			if (c[i][j] == '#') {
				if (i == 1 && j == 1) {
					if (c[i + 1][j] == '#' && c[i][j + 1] == '.' || c[i][j + 1] == '#' && c[i + 1][j] == '.') {
					}
					else {
						cout << "Impossible" << endl;
						return 0;
					}
				}
				else if (i == h && j == w) {
					if (c[i - 1][j] == '#' && c[i][j - 1] == '.' || c[i][j - 1] == '#' && c[i - 1][j] == '.') {
					}
					else {
						cout << "Impossible" << endl;
						return 0;
					}
				}
				else {
					if ((c[i + 1][j] == '#' && c[i][j + 1] == '.' || c[i][j + 1] == '#' && c[i + 1][j] == '.') &&
						(c[i - 1][j] == '#' && c[i][j - 1] == '.' || c[i][j - 1] == '#' && c[i - 1][j] == '.'))
					{
					}
					else {
						cout << "Impossible" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "Possible" << endl;
	return 0;
}