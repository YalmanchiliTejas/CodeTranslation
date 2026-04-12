#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define REPO(i,n) for(int (i)=1; (i)<=(int)(n); (i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

struct PT {
	int x, y, ix;
	PT() {}
	PT(int xx, int yy, int ii) : x(xx), y(yy), ix(ii) {}
};
struct ED {
	int a, b, c;
	ED() {}
	ED(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
};

const int MAX_N = 1e5 + 100;

int N; vector<PT> Ps;
int UNF[MAX_N];
int F(int v) {return UNF[v]==v?v:UNF[v]=F(UNF[v]);}
bool U(int a, int b) {a = F(a), b = F(b); UNF[a] = b; return a != b;}
int main() {
	cin >> N;
	REP(i, N) {
		int x, y; scanf("%d%d", &x, &y);
		Ps.push_back(PT(x, y, i));
	}
	sort(ALL(Ps), [&](PT a, PT b) {
		return a.x < b.x;
	});
	vector<ED> Es;
	REP(i, N-1) Es.push_back(ED(Ps[i].ix, Ps[i+1].ix, Ps[i+1].x - Ps[i].x));
	sort(ALL(Ps), [&](PT a, PT b) {
		return a.y < b.y;
	});
	REP(i, N-1) Es.push_back(ED(Ps[i].ix, Ps[i+1].ix, Ps[i+1].y - Ps[i].y));

	sort(ALL(Es), [&](ED a, ED b) {
		return a.c < b.c;
	});
	REP(i, N) UNF[i] = i;

	ll ans = 0;
	for(ED &e : Es) if(U(e.a, e.b)) ans += e.c;
	printf("%lld\n", ans);
	return 0;
}