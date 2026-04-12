#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int par[100010];
vector<pair<pii, int>> A, B;

int Find(int a) {
	if (par[a] == a) return a;
	return par[a] = Find(par[a]);
}
void Union(int a, int b) {
	if (Find(a) == Find(b)) return;
	par[Find(b)] = Find(a);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		int x, y; cin >> x >> y;
		A.emplace_back(pii(x, y), i);
	}

	sort(A.begin(), A.end(), [&](auto x, auto y) {
		if (x.va.va == y.va.va) return x.va.vb < y.va.vb;
		return x.va.va < y.va.va;
	});
	for (int i=1; i<N; i++) {
		B.emplace_back(pii(A[i-1].vb, A[i].vb), A[i].va.va - A[i-1].va.va);
	}

	sort(A.begin(), A.end(), [&](auto x, auto y) {
		if (x.va.vb == y.va.vb) return x.va.va < y.va.va;
		return x.va.vb < y.va.vb;
	});
	for (int i=1; i<N; i++) {
		B.emplace_back(pii(A[i-1].vb, A[i].vb), A[i].va.vb - A[i-1].va.vb);
	}

	sort(B.begin(), B.end(), [&](auto x, auto y) {
		return x.vb < y.vb;
	});

	for (int i=1; i<=N; i++) par[i] = i;
	ll ans = 0;
	for (auto edge : B) {
		int u = edge.va.va, v = edge.va.vb;
		if (Find(u) == Find(v)) continue;
		Union(u, v); ans += edge.vb;
	}

	cout << ans;
}