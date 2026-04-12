#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const LL MOD = 1000000007LL;
vector<P> ball;
int main() {
	int N;
	cin >> N;
	int Rmin = 1 << 30, Rmax = -(1 << 30);
	int Bmin = 1 << 30, Bmax = -(1 << 30);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		Rmin = min(Rmin, x);
		Rmax = max(Rmax, x);
		Bmin = min(Bmin, y);
		Bmax = max(Bmax, y);
		ball.emplace_back(x, y);
	}
	LL ans = (LL)(Rmax - Rmin)*(Bmax - Bmin);
	sort(ball.begin(), ball.end());
	int Min = 1 << 30, Max = -(1 << 30);
	int b = 1 << 30;
	for (int i = 0; i + 1 < N; i++) {
		Min = min(Min, ball[i].second);
		Max = max(Max, ball[i].second);
		b = min(b, max(Max, ball[N - 1].first) - min(Min, ball[i + 1].first));
	}
	ans = min(ans, (LL)(max(Rmax, Bmax) - min(Rmin, Bmin))*b);
	cout << ans << endl;
}