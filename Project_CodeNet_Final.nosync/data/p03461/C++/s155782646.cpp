#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int A, B;
	cin >> A >> B;
	vector<vector<int> >d(A + 1, vector<int>(B + 1, 0));
	vector<vector<int> >noneed(A + 1, vector<int>(B + 1, 0));
	for (int i = 1; i <= A; i++) {
		for (int j = 1; j <= B; j++) {
			cin >> d[i][j];
		}
	}
	bool f;
	int mn = 100;
	int sc = 0;
	int xx, yy;
	int xmax = 0;
	bool ok = true;
	vector<pair<pair<int, int>, int> > vp;
	for (int a = 1; a <= A; a++) {
		for (int b = 1; b <= B; b++) {
			if (noneed[a][b] == 0) {
				xx = -1;
				mn = 10000;
				for (int x = 0; x <= 100; x++) {
					for (int y = 0; y <= 100; y++) {
						int z = d[a][b] - x*a - y*b;
						if (z < 0)break;
						f = true;
						sc = 0;
						for (int a2 = 1; a2 <= A; a2++) {
							for (int b2 = 1; b2 <= B; b2++) {
								if (d[a2][b2] > x*a2 + y*b2 + z) {
									f = false;
									break;
								}
								else if (noneed[a2][b2] == 0 && d[a2][b2] == x*a2 + y*b2 + z) {
									sc--;
								}
							}
							if (!f) {
								break;
							}
						}
						if (f) {
							if (mn > sc) {
								mn = sc;
								xx = x;
								yy = y;
							}
							//break;
						}
					}
				}
				if (xx == -1) {
					cerr << a << " " << b << endl;
					ok = false;
					break;
				}
				for (int a2 = 1; a2 <= A; a2++) {
					for (int b2 = 1; b2 <= B; b2++) {
						if (d[a2][b2] == xx*a2 + yy*b2 + d[a][b] - xx*a - yy*b) {
							noneed[a2][b2] = 1;
						}
					}
				}
				xmax = max(xx, xmax);
				vp.push_back(make_pair(make_pair(xx, yy), d[a][b] - xx*a - yy*b));
			}
		}
		if (!ok)break;
	}
	if (ok) {
		int v = 0;
		sort(vp.begin(), vp.end());
		vector<int> ymax(xmax + 1, -1);
		for (int i = 0; i < vp.size(); i++) {
			ymax[vp[i].first.first] = max(ymax[vp[i].first.first], vp[i].first.second);
			//cerr << vp[i].first.first << " " << vp[i].first.second << " " << vp[i].second << endl;
		}
		map<pair<int, int>, int> mp;
		vector<pair<pair<int, int>, int> >ed;
		mp[make_pair(0, 0)] = 0;
		for (int i = 0; i < xmax; i++) {
			v++;
			ed.push_back(make_pair(make_pair(v - 1, v), -1));
			mp[make_pair(v, 0)] = v;
		}
		for (int i = 0; i <= xmax; i++) {
			for (int j = 0; j < ymax[i]; j++) {
				v++;
				ed.push_back(make_pair(make_pair(mp[make_pair(i, j)], v), -2));
				mp[make_pair(i, j + 1)] = v;
			}
		}
		v++;
		int fc = v;
		for (int i = 0; i < vp.size(); i++) {
			ed.push_back(make_pair(make_pair(mp[make_pair(vp[i].first.first, vp[i].first.second)], fc), vp[i].second));
		}
		cout << "Possible" << endl;

		cout << fc + 1 << " " << (int)ed.size() << endl;
		for (int i = 0; i < ed.size(); i++) {
			cout << ed[i].first.first + 1 << " " << ed[i].first.second + 1 << " ";
			if (ed[i].second == -1) {
				cout << "X" << endl;
			}
			else if (ed[i].second == -2) {
				cout << "Y" << endl;
			}
			else {
				cout << ed[i].second << endl;
			}
		}
		cout << 1 << " " << fc + 1 << endl;
	}
	else {
		cout << "Impossible" << endl;
	}

}