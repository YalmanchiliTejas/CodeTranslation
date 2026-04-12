#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

P p[100000], q[100000];
vector<P>E[100000];
bool used[100000];
void add_edge(int from, int to, int cost) {
	E[from].push_back(P(cost, to));
	E[to].push_back(P(cost, from));
}
int main() {
	int n; scanf("%d", &n);
	rep(i, n) {
		scanf("%d%d", &p[i].first, &q[i].first);
		p[i].second = i; q[i].second = i;
	}
	sort(p, p + n); sort(q, q + n);
	rep(i, n - 1) {
		add_edge(p[i].second, p[i + 1].second, p[i + 1].first - p[i].first);
		add_edge(q[i].second, q[i + 1].second, q[i + 1].first - q[i].first);
	}
	priority_queue<P, vector<P>, greater<P>>que;
	que.push(P(0, 0));
	ll cnt = 0;
	while (!que.empty()) {
		P p = que.top(); que.pop();
		if (used[p.second])continue;
		used[p.second] = true; cnt += p.first;
		for (P u : E[p.second]) {
			if (!used[u.second])que.push(u);
		}
	}
	cout << cnt << endl;
}