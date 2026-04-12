#include<bits/stdc++.h>
#define rint register int
#define rep(i,u,z) for(rint i=u;i<=z;++i)
#define reb(i,u,z) for(rint i=u;i>=z;--i)
#define inf 0x7fffffff

using namespace std;
typedef long long ll;

const int N=60;
int n;
ll f[N],x,f2[N];

inline ll dpdfs(int lv,ll len){
	if(len<=lv)return 0;
	if(lv==1){
		if(len==5)return 3;
		return (ll)(len-1);
	}
	if(len>=f[lv]-(ll)lv&&len<=f[lv])return f2[lv];
	if(len>f[lv-1]+1)return f2[lv-1]+1ll+dpdfs(lv-1,len-f[lv-1]-2);
	return dpdfs(lv-1,len-1);
}
int main(){
	scanf("%d%lld",&n,&x);
	f[1]=5,f2[1]=3;
	rep(i,2,n){
		f[i]=2ll*f[i-1]+3ll;
		f2[i]=(f2[i-1]<<1ll)+1ll;
	}
	printf("%lld",dpdfs(n,x));
	return 0;
}