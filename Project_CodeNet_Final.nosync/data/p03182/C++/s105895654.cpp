#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

vector<int> l[200005];
vector<pair<int,int>> r[200005];
ll dp[200005], st[800005], lp[800005];

void prop(int p, bool leaf) {
	if(lp[p]) {
		st[p] += lp[p];
		if(!leaf) {
			lp[2*p] += lp[p];
			lp[2*p+1] += lp[p];
		}
		lp[p] = 0;
	}
}

void add(int L, int R, int i, int j, ll num, int p) {
	if(R < i or L > j) return;
	if(L >= i and R <= j) {
		lp[p] += num;
		prop(p, L == R);
		return ;
	}

	int M = (L+R)/2;
	prop(2*p, L == M);
	prop(2*p+1, M+1 == R);

	add(L, M, i, j, num, 2*p);
	add(M+1, R, i, j, num, 2*p+1);

	st[p] = max(st[2*p], st[2*p+1]);
}

ll query(int L, int R, int i, int j, int p) {
	if(R < i or L > j) return -1e18;
	if(L >= i and R <= j) return st[p];

	int M = (L+R)/2;

	prop(2*p, L == M);
	prop(2*p+1, M+1 == R);

	return max(query(L, M, i, j, 2*p), query(M+1, R, i, j, 2*p+1));
}

int main() {
	int n,a,b,c,m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		l[a].push_back(c);
		r[b+1].push_back(mp(a,c));
	}

	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int x : l[i])
			add(0, n, 0, i-1, x, 1);
		for(auto& x : r[i])
			add(0, n, 0, x.ff-1, -x.ss, 1);


		dp[i] = query(0, n, 0, i-1, 1);
		add(0, n, i, i, dp[i], 1);

		ans = max(ans, dp[i]);
	}

	printf("%lld\n", ans);

    return 0;
}
