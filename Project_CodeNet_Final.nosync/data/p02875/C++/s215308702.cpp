#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10000005,M=998244353;
int inv[N],fac[N],ans,n,fac2[N];
inline int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;	
}
int C(int x,int y){
	if (x<y)return 0;
	return fac[x]*inv[y]%M*inv[x-y]%M;
} 
signed main(){
	scanf("%lld",&n);
	fac[0]=inv[0]=fac2[0]=1;
	for (int i=1;i<N;i++)fac[i]=fac[i-1]*i%M,fac2[i]=fac2[i-1]*2%M;
	inv[N-1]=ksm(fac[N-1],M-2);
	for (int i=N-2;i;i--)inv[i]=inv[i+1]*(i+1)%M; 
	int ans=ksm(3,n);
	for (int i=n/2+1;i<=n;i++)(ans+=M-2*C(n,i)*fac2[n-i]%M)%=M;
	printf("%lld\n",ans);
}