#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Q=1<<19;
char s[Q];
int n,m;
const int MOD=1e9+7;
inline int add(int a,int b)
{a+=b;return a>=MOD?a-MOD:a;}
inline int sub(int a,int b)
{a-=b;return a<0?a+MOD:a;}
inline int mul(int a,int b)
{return 1LL*a*b%MOD;}
int dp[Q];
void DP(int n,int lim)
{
	dp[0]=1;
	int sm=1;
	for(int i=1;i<=n;i++){
		if(i>lim)sm=sub(sm,dp[i-lim-1]);
		dp[i]=sm;
		sm=add(sm,dp[i]);
	}
}
void s1()
{
	dp[0]=1;
	int sm=0;
	for(int i=1;i<=n;i++){
		if(i>=2)sm=add(sm,dp[i-2]);
		dp[i]=sm;
	}
	int als=1;
	for(int i=2;i<=n;i++){
		als=add(als,mul(i,dp[n-i]));
	}
	printf("%d\n",als);
}
void s2(int fir)
{
	if(n&1){
		puts("0");
		return;
	}
	int mus=fir+(fir%2==0);
	for(int len=0,i=fir+2;i<=m;i++){
		if(s[i]==s[1])++len;
		else{
			if(len&1)mus=min(mus,len);
			len=0;
		}
	}
	n/=2,mus=(mus+1)/2;
	// printf("%d %d WCNM\n",n,mus);
	
	DP(n,mus);
	// for(int i=0;i<=n;i++)
		// printf("%d ????\n",dp[i]);
	int als=0;
	for(int i=1;i<=n&&i<=mus;i++){
		als=add(als,mul(2*i,dp[n-i]));
	}
	printf("%d",als);
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=2;i<=m;i++)
		if(s[i]!=s[1]){
			s2(i-1);
			return 0;
		}
	s1();
	return 0;
}