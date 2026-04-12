
#include<bits/stdc++.h>
#define LL long long
#define MOD (LL)1000000007
#define pi acos(-1.0)
#define ULL unsigned long long
#define mem_1(str) memset(str,-1,sizeof(str))
#define mem0(str) memset(str,0,sizeof(str))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define INF 999999999
using namespace std;
struct ee{            //存放每边的起点终点和权值 
	LL x,y;
	int id;
}num[200000];  
LL p[200000];
struct edge{            //存放每边的起点终点和权值 
	LL u,v;
	LL w;
}myedge[500000];  
bool cmp(const edge& p1,const edge& p2)    
{
	 if(p1.w<p2.w)return true;
     else return false;
}
bool cmpp(const ee& p1,const ee& p2)    
{
	 if(p1.x<p2.x)return true;
     else return false;
}
bool cmppp(const ee& p1,const ee& p2)    
{
	 if(p1.y<p2.y)return true;
     else return false;
}
LL findset(LL x)             //寻找根节点并压缩路径 
{
	if(p[x]==x)return x;
	else p[x]=findset(p[x]);
	return p[x];
}
LL kruskal(int n,int m)      //kruskal算法 
{
	LL x,y;
	LL ans=0;
	for(int i=1;i<=n;i++)
	    p[i]=i;
	sort(myedge+1,myedge+m+1,cmp);
	for(int i=1;i<=m;i++) 
	{	
		x=findset(myedge[i].u);
		y=findset(myedge[i].v);
		if(x!=y)
		{
			ans+=myedge[i].w; 
			p[y]=x;                                  
		}
	}
	return ans;
}
int main()
{
	int n;
	LL ans; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&num[i].x ,&num[i].y );
		num[i].id =i;
	}
	sort(num+1,num+n+1,cmpp);
	int s=0;
	for(int i=1;i<n;i++)
	{
		myedge[++s].u =num[i].id ;
		myedge[s].v =num[i+1].id ;
		myedge[s].w =num[i+1].x -num[i].x ;
	}
	sort(num+1,num+n+1,cmppp);
	for(int i=1;i<n;i++)
	{
		myedge[++s].u =num[i].id ;
		myedge[s].v =num[i+1].id ;
		myedge[s].w =num[i+1].y -num[i].y ;
	}
	ans=kruskal(n,s);
	printf("%lld",ans);
}