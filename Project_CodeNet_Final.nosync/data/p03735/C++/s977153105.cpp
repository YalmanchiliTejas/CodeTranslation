#include<iostream>
#include<cstdio>
#include<ctype.h>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
struct OOO{
	ll x,y;
	bool operator <(OOO b)const{return x<b.x;}
}a[200007];
ll mxn[200007],mn[200007];
int main(){
	ll n=read(),mx=-1,mxx=-1,mi=2e9,mii=2e9;
	for(int i=1;i<=n;++i){
		a[i].x=read(),a[i].y=read();
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
		mx=max(mx,a[i].y),mi=min(mi,a[i].y);
		mxx=max(mxx,a[i].x),mii=min(mii,a[i].x);
	}
	ll ans1=1ll*(mx-mi)*(mxx-mii),ans2=1e18;
	mi=mii;sort(a+1,a+n+1);
	mxn[1]=mn[1]=a[1].y;
	for(int i=2;i<=n;++i){
		mxn[i]=max(mxn[i-1],a[i].y),mn[i]=min(mn[i-1],a[i].y);
		ans2=min(ans2,1ll*max(mxn[i],a[n].x)-min(mn[i],a[i+1].x));
	}
	printf("%lld\n",min(ans1,ans2*(mx-mi)));
	return 0;
}