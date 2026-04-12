#include <cstdio>
#include <vector>
#include <cstring>
#define mod 1000000007
using namespace std;
typedef long long ll;
int n,m;
int a[100001],b[100001];
vector<int> G[100001];
int group[100001];
int gcnt[100001];

void dfs(int v,int cnt){
	group[v]=cnt;
	gcnt[cnt]++;
	for(int i=0;i<G[v].size();i++){
		if(group[G[v][i]]==-1)dfs(G[v][i],cnt);
	}
}

int main(void){
	while(1){
		scanf("%d %d",&n,&m);
		if(n+m==0)break;
		for(int i=0;i<n;i++){
			G[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d %d",&a[i],&b[i]);
			a[i]--;
			b[i]--;
			G[a[i]].push_back(b[i]);
			G[b[i]].push_back(a[i]);
		}
		memset(gcnt,0,sizeof(gcnt));
		memset(group,-1,sizeof(group));
		int cnt=0;
		for(int i=0;i<n;i++){
			if(group[i]==-1){
				dfs(i,cnt++);
			}
		}
		ll res=1;
		bool flag=false;
		for(int i=0;i<cnt;i++){
			if(gcnt[i]>1){
				flag=true;
			}
			res=(ll)res*2%mod;
		}
		if(flag)res=(res+1)%mod;
		printf("%lld\n",res);
	}
	return 0;
}