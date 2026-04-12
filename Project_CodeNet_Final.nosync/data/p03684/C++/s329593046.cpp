#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define F first
#define S second
#define random(x) (rand()%x)
const int maxn=100005,INF=0x3f3f3f3f,mod=1000000007;
struct eg{
	int x,y,w;
}nd[maxn];
vector<eg> e;
int fa[maxn];
inline bool cmp1(eg a,eg b){
	return a.x<b.x;
}
inline bool cmp2(eg a,eg b){
	return a.y<b.y;
}
inline bool cmp3(eg a,eg b){
	return a.w<b.w;
}
inline int fnd(int v){
	return v==fa[v]?v:fa[v]=fnd(fa[v]);
}
inline void jn(int a,int b){
	fa[fnd(a)]=fnd(b);
}
int main(){
	int n,cnt=1;
	ll ans=0;
	eg tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&nd[i].x,&nd[i].y);
		nd[i].w=i;
		fa[i]=i;
	}
	sort(nd+1,nd+n+1,cmp1);
	for(int i=2;i<=n;i++){
		tmp.x=nd[i-1].w;
		tmp.y=nd[i].w;
		tmp.w=nd[i].x-nd[i-1].x;
		e.push_back(tmp);
	}
	sort(nd+1,nd+n+1,cmp2);
	for(int i=2;i<=n;i++){
		tmp.x=nd[i-1].w;
		tmp.y=nd[i].w;
		tmp.w=nd[i].y-nd[i-1].y;
		e.push_back(tmp);
	}
	sort(e.begin(),e.end(),cmp3);
	for(int i=0;i<e.size();i++){
		//printf("%d %d %d %d\n",e[i].x,e[i].y,e[i].w,i);
		if(fnd(e[i].x)==fnd(e[i].y)) continue;
		jn(e[i].x,e[i].y);
		cnt++;
		ans+=e[i].w;
		if(cnt==n) break;
	}
	printf("%lld\n",ans);
	return 0;
}
