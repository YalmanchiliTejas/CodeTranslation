#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
using namespace std;
int n,mod,i,j,ans,c[3005][3005],s[3005][3005],pw[10000005];
long long pw2[10005];
int qp(int x,long long y)
{
	int z=1;
	while(y){
		if(y&1){
			z=1ll*z*x%mod;
		}
		x=1ll*x*x%mod;
		y/=2; 
	}
	return z;
}
int solve(int x)
{
	int i,ans=0;
	fz1(i,x){
		inc(ans,1ll*s[x][i]*pw[(n+1-x)*(i-1)]%mod)
	}
	return 1ll*ans*qp(2,pw2[n+1-x])%mod;
}
int main()
{
	scanf("%d%d",&n,&mod);
	pw[0]=pw2[0]=1;
	fz1(i,10000000){
		pw[i]=pw[i-1]+pw[i-1];
		if(pw[i]>=mod) pw[i]-=mod;
	}
	fz1(i,10000){
		long long t=0ll+pw2[i-1]+pw2[i-1];
		if(t>=mod-1) t-=mod-1;
		pw2[i]=t;
	}
	c[0][0]=s[0][0]=1;
	fz1(i,n+2){
		c[i][0]=1;
		fz1(j,i){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			s[i][j]=(1ll*s[i-1][j]*j+s[i-1][j-1])%mod;
		}
	}
	fz0g(i,n){
		int t=1ll*solve(i+1)*c[n][i]%mod;
		if(i&1) dec(ans,t) else inc(ans,t) 
	}
	cout<<ans<<endl;
	return 0;
}