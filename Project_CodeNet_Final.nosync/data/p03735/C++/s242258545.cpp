#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int64_t x[n], y[n];
	for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	int64_t ans;
	// ちがう
	{
		int64_t rmax = 0, rmin = 1e9, bmax = 0, bmin = 1e9;
		for(int i = 0; i < n; ++i) {
			rmax = max(rmax, min(x[i], y[i]));
			rmin = min(rmin, min(x[i], y[i]));
			bmax = max(bmax, max(x[i], y[i]));
			bmin = min(bmin, max(x[i], y[i]));
		}
		ans = (rmax - rmin) * (bmax - bmin);
	}
	// おなじ
	{
		int64_t rmax = 0, rmin = 1e9;
		pair<int64_t, int64_t> p[n];
		multiset<int64_t> b;
		for(int i = 0; i < n; ++i) {
			p[i] = {min(x[i], y[i]), max(x[i], y[i])};
			b.insert(min(x[i], y[i]));
			rmax = max(rmax, max(x[i], y[i]));
			rmin = min(rmin, min(x[i], y[i]));
		}
		sort(p, p + n);
		int64_t bdiff = *b.rbegin() - *b.begin();
		for(int i = 0; i < n; ++i) {
			int64_t xx, yy; tie(xx, yy) = p[i];
			int64_t bmax = *b.rbegin();
			// 絶対変える
			if(yy <= bmax) {
				b.erase(b.find(xx));
				b.insert(yy);
				int64_t bmin = *b.begin();
				bdiff = (bmax - bmin);
			// 変えないかも
			} else {
				bmax = yy;
				b.erase(b.find(xx));
				b.insert(yy);
				int64_t bmin = *b.begin();
				// 変える
				if((bmax - bmin) < bdiff) {
					bdiff = (bmax - bmin);
				// 変えない
				} else {
					b.erase(b.find(yy));
					b.insert(xx);
				}
			}
		}
		ans = min(ans, (rmax - rmin) * bdiff);
	}
	cout << ans << '\n';
	return 0;
}

