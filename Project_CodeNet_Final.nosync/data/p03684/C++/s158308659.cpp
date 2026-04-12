#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)

const int INF=1<<30;
using namespace std;

const int maxn=100000+10;

int p[maxn];
int findset(int x){return p[x]==x?x:p[x]=findset(p[x]);}
int merge(int a,int b)
{
	a=findset(a);b=findset(b);
	if(a==b) return 0;
	p[a]=b;return 1;
}

struct Edge{
	int u,v,w;
	Edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	inline bool operator < (const Edge &rhs)const{
		return w<rhs.w;
	}
};

int idx[maxn],idy[maxn],x[maxn],y[maxn];

bool cmpx(int a,int b){return x[a]<x[b];}
bool cmpy(int a,int b){return y[a]<y[b];}

vector<Edge>e;

int main()
{
	int n;cin>>n;
	rep(i,1,n) scanf("%d%d",x+i,y+i),idx[i]=idy[i]=i;
	sort(idx+1,idx+n+1,cmpx);
	sort(idy+1,idy+n+1,cmpy);

	rep(i,1,n-1)
	{
		e.push_back(Edge(idx[i],idx[i+1],x[idx[i+1]]-x[idx[i]]));
		e.push_back(Edge(idy[i],idy[i+1],y[idy[i+1]]-y[idy[i]]));
	}

	sort(e.begin(),e.end());

	rep(i,1,n) p[i]=i;

	int cnt=0;long long cost=0;
	for(int i=0;i<(int)e.size();++i)
	{
	//	printf("(%d,%d,%d)\n",e[i].u,e[i].v,e[i].w);
		if(merge(e[i].u,e[i].v))
		{
			cost+=e[i].w;
			if(--cnt==1) break;
		}
	}

	cout<<cost<<endl;
	return 0;
}
