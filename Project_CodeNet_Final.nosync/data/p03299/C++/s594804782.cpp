#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=101;
const LL p=1e9+7;
const LL inf=0x3f3f3f3f;
LL n,h[N];
inline LL pw(LL x,LL y){
	LL ans=1;
	while(y){
		if(y&1)ans=ans*x%p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
#define pii pair<LL,LL>
#define mp(x,y) make_pair((x),(y))
#define fi first
#define se second
inline pii solve(LL l,LL r,LL H){
	LL mn=inf;
	for(LL i=l; i<=r; ++i)mn=min(mn,h[i]-H);
	bool flag=0; for(LL i=l; i<=r; ++i)if(h[i]>mn+H)flag=1;
	if(!flag)return mp(pw(2,mn-1),(pw(2,r-l+1)-2+p)%p);
	LL ans0=1,ans1=1,x=r-l+1,y=0;
	for(LL i=l,pre=0; i<=r; ++i){
		if(!pre&&h[i]>mn+H)pre=i;
		if(pre&&h[i]==mn+H){
			pii P=solve(pre,i-1,mn+H);
			ans0=2*ans0%p*P.fi%p; ans1=ans1*(P.se+4*P.fi%p)%p;
			++y; x-=i-pre; pre=0;
		}else if(pre&&i==r){
			pii P=solve(pre,r,mn+H);
			ans0=2*ans0%p*P.fi%p; ans1=ans1*(P.se+4*P.fi%p)%p;
			++y; x-=r-pre+1; pre=0;
		}
	}
	ans1=(ans1-ans0+p)%p;
	ans1=ans1*pw(2,x)%p;
	ans1=(ans1+(pw(2,x)%p-2+p)%p*ans0%p)%p;
	ans0=ans0*pw(2,mn-1)%p;
	return mp(ans0,ans1);
}
int main(){
	scanf("%lld",&n);
	for(LL i=1; i<=n; ++i)scanf("%lld",&h[i]);
	pii ans=solve(1,n,0);
	printf("%lld",(2*ans.fi+ans.se)%p);
	return 0;
}