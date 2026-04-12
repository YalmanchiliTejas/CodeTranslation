#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<ctime>
#include<deque>
#include<stack>
#include<functional>
#include<sstream>
//#include<cctype>
//#pragma GCC optimize(2)
using namespace std;
#define maxn 2000005
#define inf 0x7fffffff
//#define INF 1e18
#define rdint(x) scanf("%d",&x)
#define rdllt(x) scanf("%lld",&x)
#define rdult(x) scanf("%lu",&x)
#define rdlf(x) scanf("%lf",&x)
#define rdstr(x) scanf("%s",x)
typedef long long  ll;
typedef unsigned long long ull;
typedef unsigned int U;
#define ms(x) memset((x),0,sizeof(x))
const long long int mod = 1e9 + 7;
#define Mod 1000000000
#define sq(x) (x)*(x)
#define eps 1e-4
typedef pair<int, int> pii;
#define pi acos(-1.0)
//const int N = 1005;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef pair<int, int> pii;
inline ll rd() {
	ll x = 0;
	char c = getchar();
	bool f = false;
	while (!isdigit(c)) {
		if (c == '-') f = true;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int sqr(int x) { return x * x; }


/*ll ans;
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1; y = 0; return a;
	}
	ans = exgcd(b, a%b, x, y);
	ll t = x; x = y; y = t - a / b * y;
	return ans;
}
*/


int n;
int tot;
struct node {
	int x, y;
	int d;
	node(){}
	node(int x,int y,int d):x(x),y(y),d(d){}

}nd[maxn],nd2[maxn];

bool cmp(node a, node b) {
	return a.x < b.x;
}
bool cmp2(node a, node b) {
	return a.y < b.y;
}

bool cmp3(node a, node b) {
	return a.d < b.d;
}

int fa[maxn];
void init() {
	for (int i = 0; i <= n; i++)fa[i] = i;
}
int findfa(int x) {
	if (x == fa[x])return x;
	return fa[x] = findfa(fa[x]);
}

void merge(int u, int v) {
	int p = findfa(u);
	int q = findfa(v);
	if (p != q) {
		fa[p] = q;
	}
}

bool chk(int x, int y) {
	if (findfa(x) == findfa(y))return true;
	else return false;
}

int kruskal() {
	int sum = 0;
	init();
	for (int i = 0; i < tot; i++) {
		node tmp = nd2[i];
		if (tmp.d == 0)merge(tmp.x, tmp.y);
		if (!chk(tmp.x, tmp.y)) {
			merge(tmp.x, tmp.y); sum += tmp.d;
		}
	}
	return sum;
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		rdint(nd[i].x); rdint(nd[i].y);
		nd[i].d = i;
	}
	tot = 0;
	sort(nd + 1, nd + 1 + n, cmp);
	for (int i = 2; i <= n; i++) {
		nd2[tot++] = node(nd[i].d, nd[i - 1].d, nd[i].x - nd[i - 1].x);
	}
	sort(nd+1, nd + n+1, cmp2);
	for (int i = 2; i <= n; i++) {
		nd2[tot++] = node(nd[i].d, nd[i - 1].d, nd[i].y - nd[i - 1].y);
	}
	sort(nd2, nd2 + tot, cmp3);
	int sum = kruskal();
	cout << sum << endl;
	return 0;
}