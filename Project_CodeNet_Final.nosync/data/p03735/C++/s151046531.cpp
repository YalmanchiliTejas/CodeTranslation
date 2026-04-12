#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;
#define int long long
vector <pair <int, int> > v;
signed main() {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, i));
		v.push_back(make_pair(b, i));
	}
	sort(v.begin(), v.end());
	int l = 0;
	int r = 0;
	int ll = 0;
	int rr = v.size() - 1;
	set <int> sss;
	for (int i = 0; i < v.size(); ++i) {
		if (sss.count(v[i].second) && ll == 0) {
			ll = i;
		}
		sss.insert(v[i].second);
		if (sss.size() == n) {
			r = i;
			break;
		}
	}
	if (ll == 0) ll = r + 1;
	int ans = (v[r].first - v[l].first) * (v[rr].first - v[ll].first);
	if (v[0].second == v.back().second) {
		cout << ans << endl;
		return 0;
	}
	ll = 0;
	rr = v.size() - 1;
	sss.clear();
	sss.insert(v.front().second);
	sss.insert(v.back().second);
	int doo = 0;
	for (int i = 1; i < v.size(); ++i) {
		if (sss.size() == n) {
			doo = i - 1;
			break;
		}
		if (sss.count(v[i].second)) {
			doo = i - 1;
			break;
		}
		sss.insert(v[i].second);
	}
	r = v.size() - 2;
	for (int l = doo + 1; l >= 1; --l) {
		while (!sss.count(v[r].second)) {
			sss.insert(v[r].second);
			--r;
		}
		sss.erase(v[l - 1].second);
		ans = min(ans, (v[r].first - v[l].first) * (v[rr].first - v[ll].first));
	}
	cout << ans << endl;
}