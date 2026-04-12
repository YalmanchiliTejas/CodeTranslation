// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=200111;
const int mod=1e9+7;

int n,m,dp[maxn],pre[maxn];
char s[maxn];

int main()
{
	get2(n,m);
	scanf("%s",s+1);
	
	while(m>1&&s[m]==s[m-1])m--;
	if(m==1)
	{
		dp[0]=2;dp[1]=1;
		for(int i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]+dp[i-2];
			if(dp[i]>=mod)dp[i]-=mod;
		}
		printf("%d\n",dp[n]);
		return 0;
	}
	
	if(n%2==1)
	{
		puts("0");
		return 0;
	}
	
	if(s[m]==s[1])m--;
	int bound=inf;
	for(int i=1;i<=m;i++)if(s[i]==s[1]&&s[i]!=s[i-1])
	{
		int len=0;
		while(s[i+len]==s[i])len++;
		if(len%2==1)bound=min(bound,len);
		else if(i==1)bound=min(bound,len+1);
	}
	bound=min(bound,n-1);
	
	n/=2;bound=(bound+1)/2;
	dp[0]=1;pre[0]=1;
	int sum=0;
	for(int i=0;i<=n;i++)
	{
		if(i)
		{
			if(i<=bound)dp[i]=pre[i-1];
			else dp[i]=(pre[i-1]-pre[i-bound-1]+mod)%mod;
			pre[i]=(pre[i-1]+dp[i])%mod;
		}
		if(i>=n-bound)
		{
			int coef=((n-i)*2-1);
			if(i==n)coef=1;
			sum=(sum+(LL)dp[i]*coef)%mod;
		}
	}
	printendl(sum);
	
	return 0;
}