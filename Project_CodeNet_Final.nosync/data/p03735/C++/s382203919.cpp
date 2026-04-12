#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

ii P[200002];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> P[i].f >> P[i].s;
		if (P[i].f > P[i].s) swap(P[i].f, P[i].s);
	}
	auto cmps = [](const ii & a, const ii & b) { return a.s < b.s; };
	ll ans = (ll)(max_element(P, P+N)->f - min_element(P, P+N)->f) * (max_element(P, P+N, cmps)->s - min_element(P, P+N, cmps)->s);
	
	sort(P, P+N);
	ll a = max_element(P, P+N, cmps)->s - P[0].f;
	int l = P[0].s, h = P[N-1].f;
	for (int i = 1; i < N; ++i) {
		l = min(P[i - 1].s, l), h = max(P[i - 1].s, h);
		ans = min(a * (h - min(P[i].f, l)), ans);
	}
	cout << ans;
}