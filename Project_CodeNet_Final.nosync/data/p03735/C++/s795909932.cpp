#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int MaxN = 400000;
int n, a[MaxN + 5], nxt[MaxN + 5];
int x[MaxN + 5], y[MaxN + 5], re[MaxN + 5];
bool flag[MaxN +5];
map <int, int> H;
struct ARR {
	int w, l, r, ty;
}b[MaxN + 5];
vector <int> v[MaxN + 5];

bool cmp(ARR A, ARR B) {
	return A.w <  B.w;
}

void Init()
{
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		a[++tot] = x[i]; a[++tot] = y[i];
	}
	sort(a + 1, a + 2 * n + 1);
	a[0] = -1; int cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (a[i] != a[i - 1]) cnt++;
		H[a[i]] = cnt;
		re[cnt] = a[i];
	}
	tot = 0;
	for (int i = 1; i <= n; i++) {
		x[i] = H[x[i]]; y[i] = H[y[i]];	
		if (x[i] > y[i]) swap(x[i], y[i]);
		b[++tot].w = x[i]; b[tot].ty = 0; b[tot].r = y[i];
		b[++tot].w = y[i]; b[tot].ty = 1; b[tot].l = x[i];
	}	
	sort(b + 1, b + tot + 1, cmp);
	/*for (int i = 1; i <= tot; i++) 
		printf("%d %d %d\n", re[b[i].w], b[i].ty, b[i].r);*/
}

void Solve()
{
	n = 2 * n;
	for (int i = 1; i <= n; i++) 
		if (b[i].ty == 1) v[b[i].w].push_back(i);
	for (int i = 1; i <= n; i++) {
		if (b[i].ty == 0) {
			nxt[i] = v[b[i].r][v[b[i].r].size() - 1];
			v[b[i].r].pop_back();
		}
	}
	//for (int i = 1; i <= n; i++) printf("%d ", nxt[i]); printf("\n");
	int cnt =  0, Rmin = 1 << 30, Rmax = 0, Bmin = 1 << 30, Bmax = 0;
	memset(flag, 0, sizeof(flag));
	for (int i = 1; i <= n; i++) {
		if (flag[i]) Rmin = min(Rmin, re[b[i].w]), Rmax = max(Rmax, re[b[i].w]);
		else {
			Bmin = min(Bmin, re[b[i].w]), Bmax = max(Bmax, re[b[i].w]);
			flag[nxt[i]] = true;
		}
		//printf("%d %d %d %d\n", Rmin, Rmax, Bmin, Bmax);
	}
	LL ans = ((LL)Rmax - Rmin) * (Bmax - Bmin);
	memset(flag, 0, sizeof(flag));
	int pos = n;
	for (int i = n; i >= 1; i--)
		if (nxt[i] != 0) {pos = i; break;}
	LL temp = re[b[n].w] - re[b[1].w];
	int MaX = 0;
	for (int i = 1; i <= n; i++) {
		if (flag[i - 1]) break;	
		else {
			flag[nxt[i]] = true;
			ans = min(ans, (re[b[max(MaX, pos)].w] - re[b[i].w]) * (LL)temp);
			MaX = max(MaX, nxt[i]);
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	while (~scanf("%d", &n)) {
		Init();
		Solve();
	}
	return 0;
}