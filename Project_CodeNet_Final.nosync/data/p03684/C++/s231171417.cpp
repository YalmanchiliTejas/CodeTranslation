//Code by 27.
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>  
#include<memory.h> 
#include<sstream>
#include<time.h>
#include <iomanip>
using namespace std;
const unsigned long long BIGEST=1000000000000000000+1000000000000000000;
const long long BIGER=1000000000000000000;
const int BIG=1000000000;
const int MOD=19260817;
/*
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^ =ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\`  ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo,   =/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo`    \ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooo[o\oo\oo`  ,  ,o\o/\\ooo`ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo//\           \.          =\ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo\`   ,\`,ooo/]`*    ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo/oo`   .\ooo\[   ,/\ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\^  =\\o/  ,ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo  =/`  =^  =oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^            oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/    .oo/`    =ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo^o=`  ,\oooo/o^   ]^ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo.]o/\oooooooo,.//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^ [oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo  ,/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/`  ,\/oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\//oooooooooooooo,   =^/oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooo/`,`o\/ooooooooooooo`   \/ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo/\\        ,,\/\oooooooo\^   ,\oooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooo/^             `oooooooooo^    \ooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooo\\/             /\\ooooooooooo^    ,o\=ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooo`            /oooooooooooooooo^    ,,^ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooo/ooo/            =o\ooooooooooooooooo`     ^ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo/               ,\oooooooooooooooo^\     ,ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo`                ,\[]/oooooooooooooo      ,/ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooo/\        ]`       ,`\oooooooooooooo^      oooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooo\`     \o\o        \ooooooooooooooo      =\oooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooo/o=` /o/oooo^        \/\ooooooooooo      ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/o         ooooooooo\o/       ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo/\        .o\ooooooo/       ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo`        \/ooo\o/        ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\/         \ooo^^       ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo^        ./\/        oooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\/`        .        ,oo^ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooo.  ,ooooooooooooooo                ooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooo^        `/oooooooooooo/^             oooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooooo/\oo``           \/[ooo[ooooo^            ooooooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooo\,        =.        .[[[                 ,\ooooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo/o/o.       oooo\o`                             \o/\ooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo/o.        ]oooooooo\                            ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooo`        =ooooooooooooo`            ,oo/\         \ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooo        =oooooooooooooooooo/oooooooooooo\/.       `ooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooo^^      ,ooooooooooooooooooooooooooooooooooo\    ,ooooooooooooooooooooooooooooooooooooooooooooooooooo
oooooooooooooooooooooooooooooooooooooooooo\  `,/ooooooooooooooooooooooooooooooooooooo/^ o]o/ooooooooooooooooooooooooooooooooooooooooooooooooo
ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
*/
struct dsu
{
	int pa[200001];
	int rank[200001];
	int init()
	{
		for(int i=1;i<=200000;i++)rank[i]=1;
		for(int i=1;i<=200000;i++)pa[i]=i;
	}
	int find(int x)
	{
		if(pa[x]==x)return x;
		pa[x]=find(pa[x]);
		return pa[x];
	}
	int united(int x,int y)
	{
		int a=find(x);
		int b=find(y);
		if(rank[a]>rank[b])
		{
			pa[b]=a;
		}
		else if(rank[a]<rank[b])
		{
			pa[a]=b;
		}
		else if(rank[a]==rank[b])
		{
			pa[b]=a;
			rank[a]++;
		}
	}
};
dsu cccp;
pair<int,pair<int,int> > p[200001];
int f[200001];
pair<int,int>in1[200001];
pair<int,int>in2[200001];
int n,m;
int main()
{
	int x;int y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		in1[i].first=x;
		in1[i].second=i;
		in2[i].first=y;
		in2[i].second=i;
	}
	sort(in1+1,in1+1+n);
	sort(in2+1,in2+1+n);
	m=(n-1)*2;
	for(int i=1;i<n;i++)
	{
		p[i]=make_pair(abs(in1[i].first-in1[i+1].first),make_pair(in1[i].second,in1[i+1].second));
	}
	for(int i=1;i<n;i++)
	{
		p[i+n-1]=make_pair(abs(in2[i].first-in2[i+1].first),make_pair(in2[i].second,in2[i+1].second));
	}
	cccp.init();
	/*
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&p[i].second.first,&p[i].second.second,&p[i].first);
	}
	*/
	sort(p+1,p+1+m);
	int s=0;
	int g=0;
	for(int i=1;i<=m;i++)
	{
		if(cccp.find(p[i].second.first)==cccp.find(p[i].second.second))continue;
		else
		{
			if(f[p[i].second.first]==0)g++;
			f[p[i].second.first]=1;
			if(f[p[i].second.second]==0)g++;
			f[p[i].second.second]=1;
			cccp.united(p[i].second.second,p[i].second.first);
			s+=p[i].first;
		}
	}
	/*
	for(int i=1;i<=m;i++)
	{
		if(f[i])
		{
			cout<<p[i].second.first<<" "<<p[i].second.second<<" "<<p[i].first<<endl;
		}
	}
	*/
	if(g<n)cout<<"!";
	else cout<<s;
	return 0;
}