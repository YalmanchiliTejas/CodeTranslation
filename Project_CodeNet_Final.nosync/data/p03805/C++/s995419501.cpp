#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
PII a[N],b[N];
int vis[N],s[N];
int find(int x){
	return s[x]==x?x:s[x]=find(s[x]);
}
int main(){
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) s[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].fi,&a[i].se);
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		if(__builtin_popcount(i)!=n-1) continue;
		cnt=0;
		for(int j=0;j<m;j++){
			if((i>>j)&1){
				b[++cnt]=a[j+1];
			}
		}
		mst(vis,0);
		for(int j=1;j<=cnt;j++){
			int u=b[j].fi,v=b[j].se;
			vis[u]++,vis[v]++;
			int fu=find(u),fv=find(v);
			if(fu!=fv) s[fu]=fv;
		}
		int ok=1,sum=0,t=0,v=-1;
		if(vis[1]!=1) ok=0;
		for(int j=2;j<=n;j++){
			if(vis[j]==1) sum++,v=j;
			else if(vis[j]==2) t++;
		}
		for(int i=2;i<=n;i++){
			if(find(i)!=find(1)){
				ok=0;
				break;
			}
		}
		if(ok&&sum==1&&t==n-2) ans++;
		for(int i=1;i<=n;i++) s[i]=i;
	}
	printf("%d\n",ans);
}