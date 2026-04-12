#include <bits/stdc++.h>
const long long inv2=500000004;
const int N=105,mu=1000000007;
int h[N],b[N],dp[N],dp2[N],f[N],n;
bool cmp(int x,int y){
	return h[x]==h[y]?x<y:h[x]>h[y];
}
int find(int x){
	if (f[x]==x) return f[x];
	f[x]=find(f[x]);
	return f[x];
}
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=1ll*x*x%mu)
		if (y&1) ans=ans*1ll*x%mu;
	return ans;
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx==fy) return;
	int t2=ksm(2,h[fy]-h[fx])*1ll*dp2[fy]%mu;
	dp[fx]=(1ll*dp[fx]*(t2+dp[fy])%mu+1ll*dp2[fx]*dp[fy]%mu)%mu; 
	dp2[fx]=inv2*t2%mu*dp2[fx]%mu;
	dp[fx]=(dp[fx]+dp2[fx])%mu;
	f[fy]=fx;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&h[i]);
	for (int i=1;i<=n;i++) b[i]=i;
	std::sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++) dp2[i]=2,dp[i]=0,f[i]=i;
	for (int j=1;j<=n;j++){
		int i=b[j];
		if (h[i-1]>=h[i]) merge(i,i-1);
		if (h[i+1]>=h[i]) merge(i,i+1); 
	}
	int ff=find(1);
	printf("%d",(dp[ff]+1ll*dp2[ff]*ksm(2,h[ff]-1))%mu);
}