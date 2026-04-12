#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,h[SZ];
const int MOD=1e9+7;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
struct arr
{
ll g[2][2],e; bool m;
void mu(ll x)
{
	(g[0][0]*=x)%=MOD;
	(g[0][1]*=x)%=MOD;
	(g[1][0]*=x)%=MOD;
	(g[1][1]*=x)%=MOD;
}
void clr() {memset(&g,0,sizeof g);e=m=0;}
ll all() {return (g[0][0]+g[0][1]+g[1][0]+g[1][1]+e)%MOD;}
};
arr tf(arr a)
{
	if(a.m) return a;
	arr s=a;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			(s.g[j][i]+=a.g[i][j])%=MOD;
	return s;
}
arr operator * (arr a,arr b)
{
	if(a.m) return b;
	if(b.m) return a;
	arr t; t.clr();
	t.e=a.e*b.e%MOD;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			(t.e+=a.g[i][j]*b.e)%=MOD,
			(t.e+=a.e*b.g[i][j])%=MOD;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j) if(a.g[i][j])
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l)
				{
					if(j==k) (t.e+=a.g[i][j]*b.g[k][l])%=MOD;
					else (t.g[i][l]+=a.g[i][j]*b.g[k][l])%=MOD;
				}
	return t;
}
arr go(int x,int y,int b)
{
//	cerr<<"REAL"<<x<<"~"<<y<<"\n";
	if(x>y)
	{
		arr xx;
		xx.clr(); xx.m=1;
		return xx;
	}
	if(x==y)
	{
		arr xx; xx.clr();
		xx.g[0][0]=xx.g[1][1]=qp(2,h[x]-b-1);
//		cout<<x<<":"<<y<<" "<<xx.g[0][0]<<"!!\n";
		return xx;
	}
//	cout<<x<<"~"<<y<<"  "<<b<<"\n";
	int mi=1e9;
	for(int i=x;i<=y;++i)
		mi=min(mi,h[i]);
	arr ans; ans.clr(); ans.m=1; int cl=x;
	for(int i=x;i<=y;++i)
	{
		if(h[i]==mi)
		{
			arr s=go(cl,i-1,mi); s=tf(s);
			ans=ans*s; cl=i+1;
			s.clr(); s.g[0][0]=s.g[1][1]=1;
			ans=ans*s;
		}
	}
	ans=ans*tf(go(cl,y,mi));
//	cout<<x<<"~"<<y<<"  "<<b<<" "<<ans.all()<<" extra"<<mi-b-1<<"\n";
//	cout<<ans.g[0][0]<<","<<ans.g[0][1]<<","<<ans.g[1][0]<<","<<ans.g[1][1]<<" "<<ans.e<<"||\n";
	if(mi-b-1)
	{
		ans=tf(ans);
		ans.mu(qp(2,mi-b-2));
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>h[i];
	arr t=go(1,n,0);
	ll ans=t.all();
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}
