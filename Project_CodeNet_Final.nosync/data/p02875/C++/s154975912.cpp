#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
const int maxn=1e7+5;
int n;
int f[maxn];
int invf[maxn];
int power[maxn];
inline int ksm(int x,int y){
	if(!y) return 1;
	if(y==1) return x;
	int tmp=ksm(x,y/2);
	tmp=(1ll*tmp*tmp)%MOD;
	if(y&1) return (1ll*tmp*x)%MOD;
	else return tmp;
}
inline int C(int x,int y){
	if(x<y) return 0;
	return 1ll*f[x]*invf[y]%MOD*invf[x-y]%MOD;
}
int main(){
	scanf("%d",&n);
	f[0]=invf[0]=1;
	for(int i=1;i<maxn;i++) f[i]=(1ll*f[i-1]*i)%MOD;
	invf[maxn-1]=ksm(f[maxn-1],MOD-2);
	for(int i=maxn-2;i>=1;i--) invf[i]=(1ll*invf[i+1]*(i+1))%MOD;
	power[0]=1;
	for(int i=1;i<maxn;i++) power[i]=(1ll*power[i-1]*2)%MOD;
	int ans=ksm(3,n);
	int res=0;
	for(int i=n/2+1;i<=n;i++) res=(res+2ll*power[n-i]%MOD*C(n,i))%MOD;
	ans=((ans-res)%MOD+MOD)%MOD;
	printf("%d\n",ans);
	return 0;
}