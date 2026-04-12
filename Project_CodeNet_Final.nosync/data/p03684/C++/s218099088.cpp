#include<bits/stdc++.h>
using namespace std;
const int N=200010;
pair<int,int> a[N],b[N];
int n,i,f[N],u[N],v[N],w[N],x,y,z,j;
long long ans;
struct edge{
	int u,v,w;
	bool operator<(const edge&x)const{
		return w<x.w;
	}
}e[N*4];
int gfa(int x){
	return f[x]==x?x:f[x]=gfa(f[x]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		a[i]=make_pair(x,i);
		b[i]=make_pair(y,i);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	f[1]=1;
	for(i=2;i<=n;++i){
		f[i]=i;
		e[++j]=(edge){a[i-1].second,a[i].second,a[i].first-a[i-1].first};
		e[++j]=(edge){b[i-1].second,b[i].second,b[i].first-b[i-1].first};
	}
	sort(e+1,e+j+1);
	for(i=1;i<=j && n>1;++i){
		x=gfa(e[i].u);
		y=gfa(e[i].v);
		if(x!=y){
			ans+=e[i].w;
			--n;
			f[x]=y;
		}
	}
	cout<<ans;
	return 0;
}