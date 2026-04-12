#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
//const int inf = 0x3f3f3f3f;
const ll inf = 1ll << 62;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define pi 3.14159265358979323846
#define pc putchar
#define gc getchar
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
//char __wzp[1<<15|1],*__S=__wzp+32768;
//#define gc() (__S>=__wzp+32768?(__wzp[fread(__wzp,sizeof(char),1<<15,stdin)]=EOF),*((__S=__wzp)++):*(__S++))
#define rd read
#define mem(x,v) memset(x,v,sizeof(x))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))
inline ll read(){
	register ll x=0,f=1;register char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
	return x*f;
}
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
#define MAXN 100000+233
bool partz,e[MAXN + 1], viz[MAXN + 1];
vector<int> g[MAXN+1];
void dfs(int x) {
	viz[x] = 1;
	int cnt = 0;
	for (auto &y : g[x]) {
		if (viz[y] == 0) {
			dfs(y);
			cnt += 1 - e[y];
		}
	}
	if (cnt == 1) e[x] = 1;
	else if (cnt > 1) partz = 1;
}
signed main() {
	int n;
	scanf("%lld", &n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	partz |= 1-e[1];
	if(partz) printf("First\n");
	     else printf("Second\n");
	return 0;
}
