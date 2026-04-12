#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < n; i++)
#define sz(c) ((int)c.size())

using ll = long long;

int main() {
	int n; scanf("%d", &n);
	vector<int> v(n);
	FOR(i, n) {
		scanf("%d", &v[i]);
	}

	vector<int> s2;
	FOR(i, n / 2) {
		s2.push_back(v[i] - v[sz(v) - 1 - i]);
	}
	vector<int> s3;
	s3.push_back(s2[0]);
	FOR(i, n / 2 - 1) s3.push_back(s2[i + 1] - s2[i]);
	s3.push_back(-s2.back());
	int not_eq_0 = 0;
	for (auto& x : s3) if (x != 0) not_eq_0++;

	const int n2 = n / 2;
	int q; scanf("%d", &q);
	FOR(_, q) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		auto add = [&](int l, int r, int x) {
			if (s3[l] != 0) not_eq_0--;
			if (s3[r] != 0) not_eq_0--;
			s3[l] += x;
			s3[r] -= x;
			if (s3[l] != 0) not_eq_0++;
			if (s3[r] != 0) not_eq_0++;

		};
		l--, r--;
		if (l < n2) {
			int cl = l;
			int cr = min(r, n2 - 1) + 1;
			add(cl, cr, x);
		}
		if (n2 <= r) {
			int cl = n - r - 1;
			int cr = min(n - l, n2);
			add(cl, cr, -x);
		}

		int y = (not_eq_0 == 0);
		printf("%d\n",y);
	}

	return 0;
}