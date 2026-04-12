#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)



typedef long long ll;
template<int um> class UF { // from kmjp
public:
	vector<int> par;
	UF() { par = vector<int>(um, 0); rep(i, 0, um) par[i] = i; }
	int operator[](int x) { return par[x] == x ? x : par[x] = operator[](par[x]); }
	void operator()(int x, int y)
	{
		x = operator[](x); y = operator[](y);
		if (x != y) par[x] = y;
	}
};
//-----------------------------------------------------------------
int N, M;
tuple<int, int, int> buf[404040];
int D[4040][4040];
UF<4040> uf;
vector<pair<int, int>> E[4040];
//-----------------------------------------------------------------
void dfs(int st, int cur, int par, int ma) {
	D[st][cur] = ma;

	for (auto p : E[cur]) if (p.first != par) dfs(st, p.first, cur, max(ma, p.second));
}
//-----------------------------------------------------------------
int main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		buf[i] = make_tuple(c, a, b);
	}
	sort(buf, buf + M);

	ll sm = 0;
	rep(i, 0, M) {
		int a = get<1>(buf[i]);
		int b = get<2>(buf[i]);
		int c = get<0>(buf[i]);

		if (uf[a] != uf[b]) {
			uf(a, b);
			E[a].push_back(make_pair(b, c));
			E[b].push_back(make_pair(a, c));
			sm += c;
		}
	}

	rep(i, 1, N + 1) dfs(i, i, -1, 0);

	int Q; cin >> Q;
	rep(i, 0, Q) {
		int s, t;
		scanf("%d %d", &s, &t);

		ll ans = sm - D[s][t];
		printf("%lld\n", ans);
	}
}