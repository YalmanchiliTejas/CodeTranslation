// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
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

const int poly_bits=18;
const int poly_max=262144;//poly_max=2^poly_bits
const int mod=998244353;//a prime in the form of k*poly_max+1
const int root=3;//a primitive root of mod

int power(int x,int y){int ret=1;do{if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;}while(y>>=1);return ret;}

void ntt(int a[],int n,int f)
{
	for(int i=0,j=0;i<n;i++)
	{
		if(i<j)swap(a[i],a[j]);
		for(int t=n>>1;(j^=t)<t;t>>=1);
	}
	for(int l=1;l<n;l<<=1)
	{
		int l2=l<<1;
		int wn=power(root,(mod-1)/l2),w;
		if(f==-1)wn=power(wn,mod-2);
		for(int i=0;i<n;i+=l2)
		{
			w=1;
			for(int j=0;j<l;j++)
			{
				int tmp=1ll*a[i+l+j]*w%mod;
				a[i+l+j]=(a[i+j]-tmp+mod)%mod;
				a[i+j]=(a[i+j]+tmp)%mod;
				w=1ll*w*wn%mod;
			}
		}
	}
	if(f==-1)
	{
		int rev=power(n,mod-2);
		for(int i=0;i<n;i++)a[i]=1ll*a[i]*rev%mod;
	}
}

void poly_mult(int a[],int b[],int c[],int n,int m)
{
	static int ta[1<<20],tb[1<<20];
	int l=1;while(l<n+m)l<<=1;
	for(int i=0;i<l;i++)ta[i]=(i<n?a[i]:0),tb[i]=(i<m?b[i]:0);
	ntt(ta,l,1);ntt(tb,l,1);
	for(int i=0;i<l;i++)ta[i]=1ll*ta[i]*tb[i]%mod;
	ntt(ta,l,-1);
	for(int i=0;i<n+m;i++)c[i]=ta[i];
}

int n,m,f[20111],invf[20111],ret[20111],now[20111];
char s[10111],t[10111];
int main()
{
	f[0]=1;invf[0]=1;
	for(int i=1;i<20111;i++)
	{
		f[i]=1ll*i*f[i-1]%mod;
		invf[i]=power(f[i],mod-2);
	}
		
	scanf("%s%s",s+1,t+1);
	for(int i=1;s[i];i++)if(s[i]=='1')
	{
		if(t[i]=='1')m++;
		else n++;
	}
	
	for(int i=0;i<=m;i++)now[i]=invf[i+1];
	ret[0]=1;
	int tmp=n,ans=0;
	while(tmp)
	{
		if(tmp&1)poly_mult(ret,now,ret,m+1,m+1);
		poly_mult(now,now,now,m+1,m+1);
		tmp>>=1;
	}
	for(int i=0;i<=m;i++)ans=(ans+ret[i])%mod;
	ans=1ll*ans*f[n]%mod*f[m]%mod*f[n+m]%mod;
	
	printf("%d\n",ans);
	return 0;
}