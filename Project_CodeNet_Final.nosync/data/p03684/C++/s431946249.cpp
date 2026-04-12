#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct data{
	int x,y;
}a[210001];
struct edge{
	int a,b,v;
}g[410001];
ll ans;
int tot,f[210001],i,j,k,n,m,p[210001];
int getfa(int x){
	return (f[x])?f[x]=getfa(f[x]):x;
}
bool merge(int x,int y){
	int i=getfa(x),j=getfa(y);
	if (i==j) return 0;
	f[j]=i;
	return 1;
}
bool cmpx(int x,int y){
	return a[x].x<a[y].x;
}
bool cmpy(int x,int y){
	return a[x].y<a[y].y;
}
bool cmpg(edge x,edge y){
	return x.v<y.v;
}
int main(){
	scanf("%d",&n);memset(f,0,sizeof(f));
	for (i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),p[i]=i;
	sort(p+1,p+1+n,cmpx);
	for (tot=0,i=1;i<n;i++) g[++tot].a=p[i],g[tot].b=p[i+1],g[tot].v=a[p[i+1]].x-a[p[i]].x;
	sort(p+1,p+1+n,cmpy);
	for (i=1;i<n;i++) g[++tot].a=p[i],g[tot].b=p[i+1],g[tot].v=a[p[i+1]].y-a[p[i]].y;
	sort(g+1,g+1+tot,cmpg);
	for (i=1,k=ans=0;k<n-1;i++){
		if (merge(g[i].a,g[i].b)) k++,ans+=g[i].v;
	}
	printf("%lld\n",ans);
	return 0;
}