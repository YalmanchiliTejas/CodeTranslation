#include<bits/stdc++.h>
using namespace std;

struct edge
{int u,v,next;
};
struct edge e[200010];

int n,num,ans;
int head[200010],f[2][200010],g[200010];

void add(int u,int v)
{e[num].u=u;
 e[num].v=v;
 e[num].next=head[u];
 head[u]=num;
 num++;
 e[num].u=v;
 e[num].v=u;
 e[num].next=head[v];
 head[v]=num;
 num++;
}

void dfs(int i,int fa)
{int j;
 
 j=head[i];
 while(j!=-1)
 {	if(e[j].v!=fa)
 	{	dfs(e[j].v,i);
 		f[g[e[j].v]^1][i]++;
 	}
 	j=e[j].next;
 }
 g[i]=(f[0][i]==0);
}

void dfs1(int i,int fa,int flag)
{int j,x=0;
 int c[2];
 
 if(f[0][i]>=2) ans=1;
 
 //cout<<i<<" "<<fa<<" "<<f[0][i]<<" "<<f[1][i]<<" "<<flag<<endl;
 
 if(i!=1)
 {	c[0]=f[0][fa];
 	c[1]=f[1][fa];
 	c[g[i]^1]--;
 	c[flag]++;
 	x=(c[0]==0);
 	x^=1;
 	if(f[0][i]+(x==0)>=2) ans=1;
 	
 	//cout<<"## "<<i<<" "<<f[0][i]<<" "<<x<<endl;
 }
 else
 	x=1;
 j=head[i];
 while(j!=-1)
 {	if(e[j].v!=fa)
 		dfs1(e[j].v,i,x);
 	j=e[j].next;
 }
}	

int main()
{int i,j,x,y;
 
 while(scanf("%d",&n)!=EOF)
 {	num=0;
 	for(i=1;i<=n;i++)
	{	head[i]=-1;
		f[0][i]=f[1][i]=g[i]=0;
	}
 	for(i=1;i<n;i++)
 	{	scanf("%d%d",&x,&y);
 		add(x,y);
 	}
 	ans=(n==1);
 	dfs(1,0);
 	dfs1(1,0,0);
 	printf("%s",ans?"First":"Second");
 }
 return 0;
}