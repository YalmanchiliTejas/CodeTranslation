#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define MP(a,b) make_pair(a,b)
typedef long long LL;
typedef pair<int, int> PI;
typedef pair<int, PI> PII;
typedef vector<int> VI;
const LL MOD = 1000000007LL;
int Par[100000];
int Rank[100000];
void init(int n) {
	rep(i, n) {
		Par[i] = i;
		Rank[i] = 0;
	}
}
int find(int x) {
	if (Par[x] == x) {
		return x;
	}
	else {
		return Par[x] = find(Par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (Rank[x] < Rank[y]) {
		Par[x] = y;
	}
	else {
		Par[y] = x;
		if (Rank[x] == Rank[y]) Rank[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}
int x[100000], y[100000];
int main() {
	int N;
	cin >> N;
	vector<PI> vx, vy;
	rep(i, N) {
		cin >> x[i] >> y[i];
		vx.push_back(MP(x[i], i));
		vy.push_back(MP(y[i], i));
	}
	sort(ALL(vx));
	sort(ALL(vy));
	priority_queue<PII, vector<PII>, greater<PII>> Q;
	rep(i, N - 1) {
		Q.push(MP(abs(vx[i].first - vx[i + 1].first), MP(vx[i].second, vx[i + 1].second)));
		Q.push(MP(abs(vy[i].first - vy[i + 1].first), MP(vy[i].second, vy[i + 1].second)));
	}
	init(N);
	LL ans = 0;
	while (!Q.empty()) {
		PII p = Q.top(); Q.pop();
		int a = p.second.first, b = p.second.second;
		if (!same(a, b)) {
			unite(a, b);
			ans += p.first;
		}
	}
	cout << ans << endl;
}