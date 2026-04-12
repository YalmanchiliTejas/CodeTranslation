#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, a[200003]; vector<pair<long long, long long> >vec;
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i]; }
	vec.push_back(make_pair(0, 0));
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i]; vec.push_back(make_pair(cnt, i));
	}
	vec.push_back(make_pair(100000000000000000LL, n + 1));
	sort(vec.begin(), vec.end());
	long long maxn = 0; long long L = 0;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].first != vec[i - 1].first) {
			maxn = max(maxn, vec[i - 1].second - vec[L].second);
			L = i;
		}
	}
	cout << maxn << endl;
	return 0;
}