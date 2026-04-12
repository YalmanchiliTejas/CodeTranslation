#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
char c[55][55];
int main() {
	int h, w;
	cin >> h >> w;
	ll count = 0;
	vector<P>p;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c[i][j];
			if (c[i][j] == '#') {
				p.push_back(make_pair(i, j));
				count++;
			}
		}
	}

	bool ok = true;
	for (int i = 0; i < count; i++) {
		if (i != count - 1) {
			if (p[i].first == p[i + 1].first) {
				for (int j = p[i].second; j <= p[i].second; j++) {
					if (c[p[i].first][j] == '.') {
						ok = false;
					}
				}
			}

			else {
				if (p[i].second != p[i + 1].second) {
					ok = false;
				}
			}
		}
	}
	if (ok) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	return 0;
}