#include <bits/stdc++.h>
const int mu=1000000007,N=1005;
int p[N],inv[N],n,a,b,c,d,dp[N];
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*1ll*x%mu)
		if (y&1) ans=ans*1ll*x%mu;
	return ans;
}
int C(int x,int y){
	return 1ll*p[x]*inv[y]%mu*inv[x-y]%mu;
}
int main(){
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	p[0]=1;
	for (int i=1;i<=n;i++) p[i]=p[i-1]*1ll*i%mu;
	inv[n]=ksm(p[n],mu-2);
	for (int i=n;i>=1;i--) inv[i-1]=inv[i]*1ll*i%mu;
	int now=0;
	dp[0]=1;
	for (int i=a;i<=b;i++){
		for (int j=n-i,rest=i;j>=0;j--,rest++)
			for(int k=c,t=ksm(inv[i],c);k<=d && j+k*i<=n;k++,t=t*1ll*inv[i]%mu)
				dp[j+k*i]=(dp[j+k*i]+dp[j]*1ll*t%mu*p[rest]%mu*inv[rest-k*i]%mu*inv[k]%mu)%mu;
	}
	printf("%d\n",dp[n]);
}