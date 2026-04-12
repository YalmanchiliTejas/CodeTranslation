#include<bits/stdc++.h>
#define rg register
#define il inline
using namespace std;
typedef long long ll;
const int O=2e5+10;
const ll inf=2e9;
struct Data{
	int x,y;
	il bool operator<(Data A)const{
		return x<A.x;
	}
}a[O];
il void Max(int&x,int y){if(x<y)x=y;}
il void Min(int&x,int y){if(x>y)x=y;}
il int gi(){
    int o=0,fl=1;char ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')fl=-1,ch=getchar();
    while(isdigit(ch))o=o*10+ch-'0',ch=getchar();
    return fl*o;
}
int n,bmax,bmin,rmax,rmin,maxn[O],minl[O],ans2=inf;
ll ans1;
int main(){
	n=gi();
	bmax=rmax=-1;bmin=rmin=inf;
	for(int i=1;i<=n;++i){
		int x=gi(),y=gi();
		if(x>y)swap(x,y);
		a[i]=(Data){x,y};
		Max(bmax,y);Min(bmin,y);
		Max(rmax,x);Min(rmin,x);
	}
	ans1=1ll*(bmax-bmin)*(rmax-rmin);
	sort(a+1,a+n+1);bmin=rmin;
	maxn[1]=minl[1]=a[1].y;
	for(int i=2;i<=n;++i){
		maxn[i]=max(maxn[i-1],a[i].y);
		minl[i]=min(minl[i-1],a[i].y);
		if(i^n)Min(ans2,max(maxn[i],a[n].x)-min(minl[i],a[i+1].x));
	}
	printf("%lld\n",min(ans1,1ll*(bmax-bmin)*ans2));
//	printf("%lld %lld",ans1,1ll*(bmax-bmin)*ans2);
	return 0;
}
