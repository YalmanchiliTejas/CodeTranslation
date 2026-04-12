#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<ll, ll> P;
int main() {
	int N;
	cin >> N;
	vector<P> ball(N);
	ll MAX = 0, MIN = INF;
	for (int i = 0; i < N; i++) {
		cin >> ball[i].first >> ball[i].second;
		if (ball[i].first > ball[i].second) swap(ball[i].first, ball[i].second);
		MAX = max(MAX, ball[i].second);
		MIN = min(MIN, ball[i].first);
	}
	sort(ball.begin(), ball.end());
	ll Rmax = 0, Rmin = INF, Bmax = 0, Bmin = INF;
	for (int i = 0; i < N; i++) {
		Rmax = max(Rmax, ball[i].second);
		Rmin = min(Rmin, ball[i].second);
		Bmax = max(Bmax, ball[i].first);
		Bmin = min(Bmin, ball[i].first);
	}
	ll ans = (Rmax - Rmin)*(Bmax - Bmin);
	Bmax = 0, Bmin = INF;
	ll b = INF;
	for (int i = 0; i + 1 < N; i++) {
		Bmax = max(Bmax, ball[i].second);
		Bmin = min(Bmin, ball[i].second);
		b = min(b, max(Bmax, ball[N - 1].first) - min(Bmin, ball[i + 1].first));
	}
	ans = min(ans, (MAX - MIN)*b);
	cout << ans << endl;
}