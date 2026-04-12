#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
const int N=10000;
const db pi=acos(-1.0);
#define lowbit(x) (x)&(-x)
#define sqr(x) (x)*(x)
#define rep(i,a,b) for (register int i=a;i<=b;i++)
#define per(i,a,b) for (register int i=a;i>=b;i--)
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define maxd 1000000007
#define eps 1e-8
int n,d,a[100100],dp[10010][110][2];
char s[100100];

int read()
{
    int x=0,f=1;char ch=getchar();
    while ((ch<'0') || (ch>'9')) {if (ch=='-') f=-1;ch=getchar();}
    while ((ch>='0') && (ch<='9')) {x=x*10+(ch-'0');ch=getchar();}
    return x*f;
}

int dfs(int pos,int mod,int lim)
{
	if (pos>n) dp[pos][mod][lim]=(mod==0);
	if (dp[pos][mod][lim]>-1) return dp[pos][mod][lim];
	int sum=0,up=9;
	if (lim) up=a[pos];
	rep(i,0,up)
	{
		int tmp=dfs(pos+1,(mod+i)%d,lim&&(i==up));
		sum=(sum+tmp)%maxd;
	}
	dp[pos][mod][lim]=sum;
	return sum;
}

int main()
{
	scanf("%s",s+1);d=read();n=strlen(s+1);
	rep(i,1,n) a[i]=s[i]-'0';
	memset(dp,-1,sizeof(dp));
	printf("%d",(dfs(1,0,1)+maxd-1)%maxd);
	return 0;
}
