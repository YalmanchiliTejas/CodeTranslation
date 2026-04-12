#include <bits/stdc++.h>
#define rg register
#define ll long long
using namespace std;
const int N=2e5+5,Inf=1e9+7;
inline ll read(){
	rg ll x=0; rg char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x; 
}
struct Bag{
	ll ballx,bally;
	inline bool operator < (const Bag &bg) const{ return ballx<bg.ballx; }
}bag[N];
ll x[N],y[N],mx[N],mn[N],n,cnt,ans=Inf,amax,amin=Inf,bmax,bmin=Inf;
int main(){
	n=read();
	for(rg int i=1;i<=n;++i){
		bag[i].ballx=read(); bag[i].bally=read(); 
		if(bag[i].ballx>bag[i].bally) swap(bag[i].ballx,bag[i].bally);
		amin=min(amin,bag[i].bally); amax=max(amax,bag[i].bally);
		bmin=min(bmin,bag[i].ballx); bmax=max(bmax,bag[i].ballx);
	}
	cnt=(amax-amin)*(bmax-bmin); sort(bag+1,bag+n+1); mn[1]=mx[1]=bag[1].bally;
	for(rg int i=2;i<n;++i){
		mn[i]=min(mn[i-1],bag[i].bally); mx[i]=max(mx[i-1],bag[i].bally);
		ans=min(ans,max(mx[i],bag[n].ballx)-min(mn[i],bag[i+1].ballx));
	}
	return printf("%lld\n",min(ans*(amax-bmin),cnt))&0;
}