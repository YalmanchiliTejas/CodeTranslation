#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb(a) push_back(a)
using namespace std;

typedef long long ll;

const int N=1e4+5,Mo=1e9+7;

int pwr(int x,int y) {
	int z=1;
	for(;y;y>>=1,x=(ll)x*x%Mo)
		if (y&1) z=(ll)z*x%Mo;
	return z;
}

int n,h[N],row[N],column[N],tot;
vector<int> son[N];

int build(int l,int r,int d) {
	int mn=1e9,cnt=0,v=++tot;
	fo(i,l,r) mn=min(mn,h[i]);
	column[v]=r-l+1;row[v]=mn-d;
	fo(i,l,r) cnt+=h[i]==mn;
	if (cnt==r-l+1) return v;
	int la=l-1;
	fo(i,l,r) 
		if (h[i]==mn) {
			if (la!=i-1) son[v].pb(build(la+1,i-1,mn));
			la=i;
		}
	if (la!=r) son[v].pb(build(la+1,r,mn));
	return v;
}

ll f[N],g[N];

void dfs(int x) {
	f[x]=1;g[x]=0;int c=column[x]-1;
	for(int y:son[x]) {
		dfs(y);
		g[x]=(g[x]*(f[y]+g[y])+f[x]*g[y])%Mo;
		f[x]=f[x]*f[y]%Mo;
		c-=column[y]-1;
	}
	g[x]=(g[x]*pwr(2,c)+f[x]*(pwr(2,c)-1))%Mo;
	f[x]=f[x]*pwr(2,row[x]-(x==1))%Mo;
}

int main() {
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&h[i]);
	int ans=1;
	fo(i,2,n-1) 
		if (h[i]>h[i-1]&&h[i]>h[i+1]) {
			ans=(ll)ans*pwr(2,h[i]-max(h[i-1],h[i+1]))%Mo;
			h[i]=max(h[i-1],h[i+1]);
		}
	build(1,n,0);dfs(1);
	ans=(ll)ans*(f[1]+g[1])%Mo;
	printf("%d\n",ans*2%Mo);
	return 0;
}