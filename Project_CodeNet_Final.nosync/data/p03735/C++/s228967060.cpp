#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;

inline int read(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}

const int N=250005;
const int INF=1e9+7;
struct node{int x,y;}a[N];
int n,Lmin=INF,Rmin=INF,Lmax=-1,Rmax=-1;
int minn[N],maxn[N],ans;

bool cmp(node a,node b){return a.x<b.x;}

signed main(){
	n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;i++) if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	for(int i=1;i<=n;i++){
		Lmin=min(Lmin,a[i].x),Rmax=max(Rmax,a[i].y);
		Lmax=max(Lmax,a[i].x),Rmin=min(Rmin,a[i].y);
	}
	ans=(Lmax-Lmin)*(Rmax-Rmin);
	Rmin=Lmin;sort(a+1,a+n+1,cmp);
	minn[1]=maxn[1]=a[1].y;int ret=INF;
	for(int i=2;i<=n;i++){
		maxn[i]=max(maxn[i-1],a[i].y);
		minn[i]=min(minn[i-1],a[i].y);
		if(i!=n) ret=min(ret,max(maxn[i],a[n].x)-min(minn[i],a[i+1].x));
	}
	ret*=(Rmax-Rmin);
	printf("%lld\n",min(ans,ret));
	return 0;
}
