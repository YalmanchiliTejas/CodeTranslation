#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10010,p=998244353;
int inc(int x,int y){x+=y;return x>=p?x-p:x;}
int mul(int x,int y){return (ll)x*y%p;}
int power(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=mul(x,x))
		if (y&1) ans=mul(ans,x);
	return ans;
}
int dp[N][N],fac[N],ifac[N],n,m,len;
char s[N],t[N];
int C(int n,int m){
	return mul(fac[n],mul(ifac[m],ifac[n-m]));
}
int main()
{
	scanf("%s%s",s,t);
	len=strlen(s);
	for (int i=0;i<len;i++)
	if (s[i]=='1') t[i]=='1'?n++:m++;
	dp[0][0]=1;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=m;j++){
		if (j) dp[i][j]=inc(dp[i][j],mul(dp[i][j-1],j*j));
		if (i&&j) dp[i][j]=inc(dp[i][j],mul(dp[i-1][j],i*j));
	}
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	ifac[N-1]=power(fac[N-1],p-2);
	for (int i=N-1;i;i--) ifac[i-1]=mul(ifac[i],i);
	int ans=0;
	for (int i=0;i<=n;i++) ans=inc(ans,mul(mul(fac[i],fac[i]),mul(dp[n-i][m],mul(C(n+m,i),C(n,i)))));	
	printf("%d\n",ans);
	return 0;
}