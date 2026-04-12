#include<cstdio>
#include<cstdlib>
using namespace std;
int d[100100];
int beg[100100],nex[200100],tto[200100],e;
void putin(int s,int t){
	tto[++e]=t;
	nex[e]=beg[s];
	beg[s]=e;
}
int f[100100];
void dfs(int u,int fa){
	for(int i=beg[u];i;i=nex[i]){
		if(tto[i]==fa) continue;
		dfs(tto[i],u);
	}
	int cnt=0;
	for(int i=beg[u];i;i=nex[i]){
		if(tto[i]==fa) continue;
		if(f[tto[i]]==0) cnt++;
	}
	if(cnt>=2)
	{
		printf("First\n");
		exit(0);
	}
	else
		f[u]=cnt;
}
int main(){
//	freopen("D.in","r",stdin);
	int n;
	scanf("%d",&n);
	if(n==2){
		printf("Second\n");
		return 0;
	}
	int s,t;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&s,&t);
		putin(s,t);
		putin(t,s);
		d[s]++,d[t]++;
	}
	int rt;
	for(int i=1;i<=n;i++){
		if(d[i]>1){
			rt=i;
			break;
		}
	}
	dfs(rt,-1);
	if(!f[rt]){
		printf("First\n");
		return 0;
	}
	printf("Second\n");
	return 0;
}
