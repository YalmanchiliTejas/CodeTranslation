#include "bits/stdc++.h"
using namespace std;

struct root {
	int cost;
	int from;
	int to;
};

int Par[100000], Rank[100000];

void init(int N) {
	for (int i = 0; i < N; i++) {
		Par[i] = i;
		Rank[i] = 0;
	}
}

int Root(int N) {
	if (Par[N] == N) return N;
	return Par[N] = Root(Par[N]);
}

void unite(int A, int B) {
	A = Root(A), B = Root(B);
	if (Rank[A] < Rank[B]) Par[A] = B;
	else {
		Par[B] = A;
		if (Rank[A] == Rank[B]) Rank[A]++;
	}
}

bool same(int A, int B) {
	return Root(A) == Root(B);
}

int main() {
	int N;
	long long ans = 0;
	static pair<int, int> X[100000], Y[100000];
	cin >> N;
	init(N);
	for (int i = 0; i < N; i++) {
		cin >> X[i].first >> Y[i].first;
		X[i].second = i, Y[i].second = i;
	}
	sort(X, X + N);
	sort(Y, Y + N);
	vector<root> V;
	for (int i = 0; i < N - 1; i++) {
		root r;
		r.from = X[i].second;
		r.to = X[i + 1].second;
		r.cost = X[i + 1].first - X[i].first;
		V.push_back(r);
	}
	for (int i = 0; i < N - 1; i++) {
		root r;
		r.from = Y[i].second;
		r.to = Y[i + 1].second;
		r.cost = Y[i + 1].first - Y[i].first;
		V.push_back(r);
	}
	sort(V.begin(), V.end(), [&](root R1, root R2) {return R1.cost < R2.cost; });
	for (root R : V) {
		if (same(R.from, R.to)) continue;
		ans += R.cost;
		unite(R.from, R.to);
	}
	cout << ans;
}