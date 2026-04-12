#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
#define Pii pair<int, int>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
inline int read(){
	int sum = 0, t = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') t = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ sum = sum * 10 + ch - '0'; ch = getchar(); }
	return sum * t;
}

ll ans;
int n, pl[2][N], pr[2][N], sl[2][N], sr[2][N];
Pii p[N];

int main(){
	n = read();
	for(int i = 1; i <= n; i++){
		int x = read(), y = read();
		if(x > y) swap(x, y);
		p[i] = mk(x, y);
	}
	sort(p + 1, p + n + 1);
	pl[0][1] = pl[1][1] = p[1].fi;
	pr[0][1] = pr[1][1] = p[1].se;
	for(int i = 2; i <= n; i++)
		pl[0][i] = min(pl[0][i - 1], p[i].fi), pl[1][i] = max(pl[1][i - 1], p[i].fi),
		pr[0][i] = min(pr[0][i - 1], p[i].se), pr[1][i] = max(pr[1][i - 1], p[i].se);
	sl[0][n] = sl[1][n] = p[n].fi;
	sr[0][n] = sr[1][n] = p[n].se;
	for(int i = n - 1; i ; i--)
		sl[0][i] = min(sl[0][i + 1], p[i].fi), sl[1][i] = max(sl[1][i + 1], p[i].fi),
		sr[0][i] = min(sr[0][i + 1], p[i].se), sr[1][i] = max(sr[1][i + 1], p[i].se);
	ans = 1LL * (sl[1][1] - sl[0][1]) * (sr[1][1] - sr[0][1]);
	for(int i = 1; i < n; i++){
		int rmax = max(pl[1][i], sr[1][i + 1]);
		int rmin = min(pl[0][i], sr[0][i + 1]);
		int bmax = max(pr[1][i], sl[1][i + 1]);
		int bmin = min(pr[0][i], sl[0][i + 1]);
		ans = min(ans, 1LL * (rmax - rmin) * (bmax - bmin));
	}
	printf("%lld\n", ans);
}