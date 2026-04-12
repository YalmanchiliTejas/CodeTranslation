#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long 
#define N 200005
const int mod=1e9+7,inv=mod+1>>1;
int a[N],sum,n;
inline void reduce(int&x){x+=x>>31&mod;}
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n;
	rep(i,1,n) std::cin>>a[i],reduce(sum+=a[i]-mod);
	int ret=0;
	rep(i,1,n) reduce(ret+=1ll*a[i]*sum%mod-mod);
	rep(i,1,n) reduce(ret-=1ll*a[i]*a[i]%mod);
	std::cout<<1ll*ret*inv%mod<<'\n';
	return 0;
}