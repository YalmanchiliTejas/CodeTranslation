#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll, ll> P;
P p[200000];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	multiset<ll> B, R;
	for(int i = 0; i < N; i++) {
		ll X, Y;
		cin >> X >> Y;
		if(X > Y) swap(X, Y);
		p[i] = { X, Y };
		B.insert(X);
		R.insert(Y);
	}
	sort(p, p + N);

	ll Rmax = *R.rbegin(), Rmin = *R.begin(), Bmax = *B.rbegin(), Bmin = *B.begin();
	ll ans = (Rmax - Rmin) * (Bmax - Bmin);

	for(int i = 0; i < N - 1; i++) {
		ll X = p[i].first, Y = p[i].second;
		B.erase(B.find(X));
		B.insert(Y);
		R.erase(R.find(Y));
		R.insert(X);
		Rmax = *R.rbegin(), Rmin = *R.begin(), Bmax = *B.rbegin(), Bmin = *B.begin();

		ans = min(ans, (Rmax - Rmin) * (Bmax - Bmin));
	}

	cout << ans << endl;
}