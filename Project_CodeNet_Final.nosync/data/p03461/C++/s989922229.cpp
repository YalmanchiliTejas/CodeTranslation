#include<iostream>
#include<cstdio>
#include<cstring>

inline void check_max(int a,int &b){if(a>b)b=a;}
inline void check_min(int a,int &b){if(a<b)b=a;}

namespace YouQu____o_o________nyg_tai_qiang_le
{
	typedef std::pair<int,int> pii;
	const int N=12,M=202;

	struct outputer
	{
		int n,m,S,T;
		int w[M*M];
		pii E[M*M];
		void reset(int n_){n=n_,m=0;}
		void insert(int u,int v,int k){E[++m]=pii(u,v);w[m]=k;}
		void output()
		{
			printf("%d %d\n",n+1,m);
			for(int i=1;i<=m;i++)
			{
				printf("%d %d ",E[i].first+1,E[i].second+1);
				if(w[i]==-1)printf("X\n");
				else if(w[i]==-2)printf("Y\n");
				else printf("%d\n",w[i]);
			}
			printf("%d %d\n",S+1,T+1);
		}
	}d;

#define idx(p) (p)
#define idy(p) (201-(p))

	int dis[N][N],G[M][M];
	int A,B,lim;

	int calc(int x,int y)
	{
		int ret=23333;
		for(int i=0;i<=lim;i++)
			for(int j=0;j<=lim;j++)
				check_min(x*i+y*j+G[i][j],ret);
		return ret;
	}

	void solve()
	{
		lim=100;

		scanf("%d%d",&A,&B);
		for(int i=1;i<=A;i++)
			for(int j=1;j<=B;j++)
				scanf("%d",&dis[i][j]);

		for(int i=0;i<=lim;i++)
			for(int j=0;j<=lim;j++)
			{
				G[i][j]=0;
				for(int x=1;x<=A;x++)
					for(int y=1;y<=B;y++)
						check_max(dis[x][y]-x*i-y*j,G[i][j]);
			}

		for(int i=1;i<=A;i++)
			for(int j=1;j<=B;j++)
				if(calc(i,j)!=dis[i][j]){printf("Impossible\n");return;}

		printf("Possible\n");

		d.reset(idy(0));d.S=idx(0),d.T=idy(0);

		for(int i=0;i<lim;i++)d.insert(idx(i),idx(i+1),-1);
		for(int i=lim;i;i--)d.insert(idy(i),idy(i-1),-2);

		for(int i=0;i<=lim;i++)
			for(int j=0;j<=lim;j++)
				d.insert(idx(i),idy(j),G[i][j]);

		d.output();
	}
}

int main()
{
//	freopen("out","w",stdout);
	YouQu____o_o________nyg_tai_qiang_le::solve();
	return 0;
}
