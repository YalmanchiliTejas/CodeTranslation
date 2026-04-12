#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<list>
#include<deque>
#include<bitset>
#include<fstream>
#define ld double
#define ull unsigned long long 
#define ll long long 
#define pii pair<int,int >
#define iiii pair<int,pii >
#define mp make_pair 
#define INF 1000000000
#define MOD 1000000007 
#define rep(i,x) for(int (i)=0;(i)<(x);(i)++)
inline int getint()
{
	int x=0,p=1;char c;
	c=getchar();
	while (c<=32)c=getchar();
	if(c==45)p=-p,c=getchar();
	while (c>32)x=x*10+c-48,c=getchar();
	return x*p;
}
using namespace std;
//
const int maxn=1e5+5;
int n,par[maxn];
ll res;
vector<pii >Sx,Sy;
set<iiii >E;
//
void finit()
{
	rep(i,n)par[i]=i;
}
int fF(int x)
{
	if(par[x]==x)return x;
	return par[x]=fF(par[x]);
}
bool fU(int x,int y)
{
	x=fF(x);y=fF(y);
	if(x==y)return false;
	par[x]=y;
	return true;
}
int main()
{
	n=getint();
	rep(i,n)
	{
		int x=getint(),y=getint();
		Sx.push_back(mp(x,i));
		Sy.push_back(mp(y,i));
	}
	sort(Sx.begin(),Sx.end());
	sort(Sy.begin(),Sy.end());
	rep(i,n-1)
	{
		E.insert(mp(abs(Sy[i+1].first-Sy[i].first),mp(Sy[i].second,Sy[i+1].second)));
		E.insert(mp(abs(Sx[i+1].first-Sx[i].first),mp(Sx[i].second,Sx[i+1].second)));
	}
	finit();
	set<iiii >::iterator it;
	for(it=E.begin();it!=E.end();it++)
	{
		ll len=1ll*it->first;
		int x=it->second.first,y=it->second.second;
		if(fU(x,y))res+=len;
	}
	printf("%lld\n",res);
	return 0;	
} 