#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<queue>
#include<set>
#define ji -
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fe(x) for(int i=be[x];i;i=e[i].ne)
using namespace std;
int n,na[110000],et,be[110000],t;
struct nod{
	int x,y;
};
nod a[110000];
struct edg{
	int y,z,ne;
};
edg e[510000];
inline bool cmpx(int c,int d){
	return a[c].x<a[d].x;
}
inline bool cmpy(int c,int d){
	return a[c].y<a[d].y;
}
inline void add_edge(int x,int y,int z){
	e[++et].y=y;
	e[et].z=z;
	e[et].ne=be[x];
	be[x]=et;
}
long long ans;
struct nod2{
	int x,v;
	bool operator <(const nod2 &a)const{
		return v>a.v;
	}
};
priority_queue<nod2> q; 
bool p[110000];
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	fo(i,1,n) na[i]=i;
	sort(na+1,na+n+1,cmpx);
	fo(i,2,n){
		add_edge(na[i-1],na[i],a[na[i]].x-a[na[i-1]].x);
		add_edge(na[i],na[i-1],a[na[i]].x-a[na[i-1]].x);
	}
	sort(na+1,na+n+1,cmpy);
	fo(i,2,n){
		add_edge(na[i-1],na[i],a[na[i]].y-a[na[i-1]].y);
		add_edge(na[i],na[i-1],a[na[i]].y-a[na[i-1]].y);
	}	
	p[1]=1;
	fe(1) if(!p[e[i].y]) q.push((nod2){e[i].y,e[i].z});
	t=1;
	while (t<n){
		nod2 te=q.top();q.pop();
		if (p[te.x]) continue;
		p[te.x]=1;ans+=te.v;
		fe(te.x) q.push((nod2){e[i].y,e[i].z});
		t++;
	}
	printf("%lld\n",ans);
	return 0;
}