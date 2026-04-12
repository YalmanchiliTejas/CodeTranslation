#include <bits/stdc++.h>
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define RVC(i, S) for (int i = 0; i < S.size(); ++i)
#define mp make_pair
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> VI;

const int N = 100005;
int n, rk[N], m, fa[N];
pii pts[N];

struct Edge{
	int u, v, w;
} E[N << 1];

bool cmpx(int a, int b){
	return pts[a].fi < pts[b].fi;
}


bool cmpy(int a, int b){
	return pts[a].se < pts[b].se;
}

bool cmpw(Edge a, Edge b){
	return a.w < b.w;
}

int Find(int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}

int main(){
	scanf("%d", &n);
	REP(i, 1, n) scanf("%d%d", &pts[i].fi, &pts[i].se);
	REP(i, 1, n) rk[i] = i;
	sort(rk + 1, rk + n + 1, cmpx);
	REP(i, 1, n - 1){
		int u = rk[i], v = rk[i + 1];
		E[++m] = (Edge){u, v, pts[rk[i + 1]].fi - pts[rk[i]].fi};
	}
	sort(rk + 1, rk + n + 1, cmpy);
	REP(i, 1, n - 1){
		int u = rk[i], v = rk[i + 1];
		E[++m] = (Edge){u, v, pts[rk[i + 1]].se - pts[rk[i]].se};
	}
	sort(E + 1, E + m + 1, cmpw);
	REP(i, 1, n) fa[i] = i;
	LL ans = 0;
	REP(i, 1, m){
		if (Find(E[i].u) != Find(E[i].v)){
			fa[Find(E[i].u)] = Find(E[i].v);
			ans += E[i].w;
		}
	}
	cout << ans << endl;
	return 0;
}