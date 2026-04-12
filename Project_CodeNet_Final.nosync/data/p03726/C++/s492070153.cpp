#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int deg[110001],v[110001],i,j,k,n,m;
struct scmp{
	bool operator() (int x,int y){
		return deg[x]<deg[y]||deg[x]==deg[y]&&x<y;
	}
};
set<int> g[110001];
set<int,scmp> s;
set<int>::iterator it;
void work(int x){
	int j,k;
	k=*g[x].begin();s.erase(k);v[k]=1;
	for (it=g[k].begin();it!=g[k].end();it++){
		j=*it;
		if (v[j]) continue;
		s.erase(j);deg[j]--;s.insert(j);
		g[j].erase(k);
	}
}
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++) deg[i]=v[i]=0,g[i].clear();
	for (i=1;i<n;i++) scanf("%d%d",&j,&k),deg[j]++,deg[k]++,g[j].insert(k),g[k].insert(j);
	s.clear();
	for (i=1;i<=n;i++) s.insert(i);
	while (!s.empty()){
		k=*s.begin();s.erase(k);v[k]=1;
		if (!deg[k]){
			puts("First");return 0;
		}
		if (deg[k]>1) break;
		work(k);
	}
	puts("Second");
	return 0;
}