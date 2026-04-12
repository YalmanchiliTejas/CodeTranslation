#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> TP;

struct Union_Find {
	vector<int> root, rank;
	Union_Find(int n) {
		root.resize(n), rank.resize(n);
		for (int i = 0; i < n; i++)root[i] = i, rank[i] = 1;
	}

	int getroot(int n) {
		if (n == root[n])return n;
		return root[n] = getroot(root[n]);
	}

	bool issame(int a, int b) {
		int P = getroot(a), Q = getroot(b);
		return P == Q;
	}

	void unite(int a, int b) {
		int P = getroot(a), Q = getroot(b);
		if (P == Q)return;
		if (rank[P] > rank[Q]) {
			root[Q] = P;
		}
		else {
			if (rank[P] == rank[Q]) {
				rank[Q]++;
			}
			root[P] = Q;
		}
	}

};

struct Edge {
	int from, to;
	ll cost;
};

ll getcost(P a, P b) {
	return min(abs(a.first - b.first), abs(a.second - b.second));
}

int N;
P pos[100000];
TP arx[100000], ary[100000];
vector<Edge> candidate;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos[i].first >> pos[i].second;
		arx[i] = TP(pos[i], i);
		ary[i] = TP(P(pos[i].second, pos[i].first), i);
	}
	sort(arx, arx + N), sort(ary, ary + N);

	for (int i = 0; i < N - 1; i++) {
		Edge NewE;
		NewE.from = arx[i].second, NewE.to = arx[i + 1].second;
		NewE.cost = getcost(arx[i].first, arx[i + 1].first);
		candidate.push_back(NewE);
	}

	for (int i = 0; i < N - 1; i++) {
		Edge NewE;
		NewE.from = ary[i].second, NewE.to = ary[i + 1].second;
		NewE.cost = getcost(ary[i].first, ary[i + 1].first);
		candidate.push_back(NewE);
	}

	sort(candidate.begin(), candidate.end(), [](Edge &a, Edge &b) {
		if (a.cost < b.cost)return true;
		else return false;
	});

	Union_Find uf(N);

	ll ans = 0;
	for (int i = 0; i < candidate.size(); i++) {
		Edge now = candidate[i];
		if (!uf.issame(now.from, now.to)) {
			ans += now.cost;
			uf.unite(now.from, now.to);
		}
	}

	cout << ans << endl;

	return 0;
}