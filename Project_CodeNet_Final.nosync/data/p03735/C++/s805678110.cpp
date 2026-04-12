#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
	int N;
	cin >> N;
	vector<P> val;
	vector<ll> xs;
	for (int i = 0, x; i < N * 2; i++) {
		cin >> x;
		val.emplace_back(x, i / 2);
		xs.push_back(x);
	}
	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	for (int i = 0; i < N * 2; i++) {
		val[i].first = lower_bound(xs.begin(), xs.end(), val[i].first) - xs.begin();
	}
	sort(val.begin(), val.end());
	vector<int> cnt(N);
	int li = 0, ri = N * 2 - 1;
	while (!cnt[val[li].second]) cnt[val[li++].second]++;
	fill(cnt.begin(), cnt.end(), 0);
	while (!cnt[val[ri].second]) cnt[val[ri--].second]++;
	fill(cnt.begin(), cnt.end(), 0);
	ll res = 1000000000000000000ll;
	int var = 0, l = 0, r = 0;
	while (r <= N * 2) {
		if (var == N) {
			res = min(res, xs[val[r - 1].first] - xs[val[l].first]);
			cnt[val[l].second]--;
			if (cnt[val[l].second] == 0) var--;
			l++;
		}
		else {
			if (r < N * 2) {
				cnt[val[r].second]++;
				if (cnt[val[r].second] == 1) var++;
			}
			r++;
		}
	}
	cout << min((xs.back() - xs.front()) * res, (xs.back() - xs[val[li].first]) * (xs[val[ri].first] - xs.front())) << endl;
	return 0;
}
