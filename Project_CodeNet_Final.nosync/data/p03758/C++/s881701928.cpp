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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
map<string,int> tmp;
//int cc=0;
//#define edg(a,b) ((abs((a)-(b))==1))
int ask(string s)
{
	int r=0;
	for(int i=0;i<s.size();i++) r+=(s[i]=='1');
	if(r<=1) return 0;
	if(tmp.count(s)) return tmp[s];
	/*
	++cc; vi rp;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1') rp.pb(i);
	if(rp.size()==2)
	return tmp[s]=edg(rp[0],rp[1]);
	if(rp.size()!=3) throw "RE";
	bool a=edg(rp[0],rp[1]),b=edg(rp[0],rp[2]),
	c=edg(rp[1],rp[2]);
	return tmp[s]=a+b+c;*/
	cout<<"? "<<s<<endl;
	int x; cin>>x; return tmp[s]=x;
}
int n,ff[SZ]; vector<int> vs[SZ],rs;
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void uni(int a,int b)
{int ga=gf(a),gb=gf(b);if(ga^gb)ff[ga]=gb;}
int cnt()
{
	int ans=0; rs.clear();
	for(int i=1;i<=n;i++) vs[i].clear();
	for(int i=1;i<=n;i++)
	{
		vs[gf(i)].pb(i);
		if(gf(i)==i);else continue;
		++ans; rs.pb(i);
	}
	random_shuffle(rs.begin(),rs.end());
	for(int i=1;i<=n;i++)
		random_shuffle(vs[i].begin(),vs[i].end());
	return ans;
}
const int B=11;
vector<pii> es;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) vs[i].pb(i);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j+=B)
		{
			string s; s.resize(n);
			for(int i=0;i<n;i++) s[i]='0';
			for(int k=0;k<B&&j+k<i;++k) s[j+k-1]='1';
			int a=ask(s); s[i-1]='1';
			int b=ask(s);
			if(a==b) continue;
			for(int k=0;k<B&&j+k<i;++k)
			{
				for(int i=0;i<n;i++) s[i]='0';
				s[j+k-1]=s[i-1]='1';
				if(ask(s)==1)
					es.pb(pii(j+k,i));
			}
		}
	}
	cout<<"!";
	for(auto r:es) printf(" (%d,%d)",r.fi-1,r.se-1);
	puts("");
	//cerr<<cc<<"\n";
}
