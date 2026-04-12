// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;

int power(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int f[1111],invf[1111],dp[1111][1111];
int n,a,b,c,d;
int main()
{
	f[0]=invf[0]=1;for(int i=1;i<1111;i++){f[i]=1ll*i*f[i-1]%mod;invf[i]=power(f[i],mod-2);}
	
	get3(n,a,b);get2(c,d);
	dp[a][0]=1;
	for(int i=a;i<=b;i++)
	{
		int prod=1;
		for(int j=1;j<=c;j++)prod=1ll*prod*invf[i]%mod;
		for(int j=0;j<=n;j++)dp[i+1][j]=dp[i][j];
		for(int k=i*c;k<=i*d;k+=i)
		{
//			printf("hehe %lld\n",power(prod,mod-2));
			for(int j=0;j<=n-k;j++)
				dp[i+1][j+k]=(dp[i+1][j+k]+1ll*dp[i][j]*prod%mod*invf[k/i])%mod;
			prod=1ll*prod*invf[i]%mod;
		}
	}
	printendl(1ll*dp[b+1][n]*f[n]%mod);
	return 0;
}