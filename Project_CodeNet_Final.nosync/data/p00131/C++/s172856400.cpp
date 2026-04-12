#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

bool inside(int x,int y)
{
	return(0<=x&&x<10 && 0<=y&&y<10);
}

int main()
{
	int i,j,k;
	int dx[5]={1,-1,0,0,0};
	int dy[5]={0,0,0,-1,1};

	int C;
	cin >>C;
	for(int cases=0;cases<C;++cases)
	{
		int f[10][10]={0};
		rep(i,10)rep(j,10) scanf(" %d",&f[i][j]);

		int ans[10][10]={0};

		//1???????????????????????????????±????
		int mask;
		for(mask=0; mask<(1<<10); ++mask)
		{
			//???????????§?°??????????????¨????
			int ta[10][10]={0};
			//?????£???????????¶???
			int t[10][10]={0};
			rep(i,10)rep(j,10) t[i][j]=f[i][j];
			//1??????????????¢
			rep(i,10)
			{
				if(mask>>i&1)
				{//?????¢?????????
					ta[0][i]=1;
					rep(j,5)
					{
						int nx=i+dx[j];
						int ny=0+dy[j];
						if(inside(nx,ny)) t[ny][nx]=!t[ny][nx];
					}
				}
			}

			for(i=0;i<10-1;++i)
			{//i???????????¨???
				rep(j,10)
				{
					if(t[i][j]==1)
					{
						ta[i+1][j]=1;
						rep(k,5)
						{
							int nx=j+dx[k];
							int ny=i+1+dy[k];
							if(inside(nx,ny)) t[ny][nx]=!t[ny][nx];
						}
					}
				}
			}

			bool valid=true;
			rep(i,10)rep(j,10) valid&=(t[i][j]==0);

			if(valid)
			{
				rep(i,10)rep(j,10) ans[i][j]=ta[i][j];
				break;
			}
		}

		//output
		rep(i,10)
		{
			rep(j,10)
			{
				if(j) printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
}