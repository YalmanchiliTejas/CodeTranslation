#include <cstdio>
#define rep(i,j,k) for (i=j;i<=k;i++)
using namespace std;
const int N=1e5+5;
int n,u,v,i,j,x,End,l,r,q[N];
int En,fst[N],flg[N],dgr[N],nxt[N*2],to[N*2];
void add(int u,int v) {
	En++; nxt[En]=fst[u]; fst[u]=En; to[En]=v;
}
int fs(int x) {
	int j;
	for (j=fst[x];j;j=nxt[j])
		if (!flg[to[j]]) return to[j];
}
int main()
{
//	freopen("agress.in","r",stdin);
//	freopen("agress.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n-1)
	{
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
		dgr[u]++; dgr[v]++;
	}
	rep(i,1,n)
		if (dgr[i]==1)
			q[++r]=i;
	for (l=1;l<=r;l++)
	{
		if (flg[q[l]]) continue;
		x=fs(q[l]);
		flg[x]=1;
		End=0;
		for (j=fst[x];j;j=nxt[j])
			if (!flg[to[j]] && dgr[to[j]]==1) End++,flg[to[j]]=1;
		if (End>1) {
			printf("First\n");
			return 0;
		}
		for (j=fst[x];j;j=nxt[j])
		if (!flg[to[j]])
		{
			dgr[to[j]]--;
			if (!dgr[to[j]]) {
				printf("First\n");
				return 0;
			}
			if (dgr[to[j]]==1) q[++r]=to[j];
		}
	}
	printf("Second\n");
	return 0;
}