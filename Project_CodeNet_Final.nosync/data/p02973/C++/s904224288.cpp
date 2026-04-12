#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 1e5 + 5;
const ll LINF = 1e18 + 5;
int n, a[N], f[N], g[N<<2], tmp[N], tag[N<<2];
void pushup(int p)
{
	g[p] = max(g[p<<1], g[p<<1|1]);
}
void pushdown(int p)
{
	int &x = tag[p];
	g[p<<1] = max(g[p<<1], x);
	g[p<<1|1] = max(g[p<<1|1], x);
	tag[p<<1] = max(tag[p<<1], x);
	tag[p<<1|1] = max(tag[p<<1|1], x);
	x = 0;
}
void upd(int p, int l, int r, int x, int y, int v)
{
	if(l>=x && r<=y)
	{
		g[p] = max(g[p], v);
		tag[p] = max(tag[p], v);
		return;
	}
	if(tag[p]) pushdown(p);
	int mid = (l+r)>>1;
	if(x<=mid) upd(p<<1, l, mid, x, y, v);
	if(y>mid) upd(p<<1|1, mid+1, r, x, y, v);
	pushup(p);
}
int ask(int p, int l, int r, int x)
{
	if(l==r) return g[p];
	if(tag[p]) pushdown(p);
	int mid = (l+r)>>1;
	if(x<=mid) return ask(p<<1, l, mid, x);
	else return ask(p<<1|1, mid+1, r, x);
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	for(int i=1; i<=n; i++) 
 	{
 		cin >> a[i]; 
 		tmp[i] = a[i];
 	}
 	sort(tmp+1, tmp+n+1);
 	int m = unique(tmp+1, tmp+n+1) - tmp - 1;
 	for(int i=1; i<=n; i++)
 		a[i] = lower_bound(tmp+1, tmp+m+1, a[i]) - tmp;
 	for(int i=1; i<=n; i++)
 	{
 		f[i] = ask(1, 1, n, a[i]) + 1;
 		upd(1, 1, n, 1, a[i], f[i]);
 	}
 	int ans = *max_element(f+1, f+n+1);
 	cout << ans;
	return 0;
}
