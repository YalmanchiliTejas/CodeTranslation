#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define repp(i, m, n) for(int i = m; i < n; i++)
const int    INF = 100000000;
const double EPS = 1e-10;
const int    MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pai;
typedef pair<ll,ll> pal;
int h, w;
int muri=0;
char a[10][10];
int x[11][11]={};
int sta[10];
int goa[10];
int main()
{
	cin >> h >> w;
	repp(i, 1, h+1)
	{
		repp(j, 1, w+1)
		{
			cin >> a[i][j];
			if(a[i][j]=='#')
			{
				x[i][j]=1;
			}
			else
			{
				x[i][j]=0;
			}
		}
	}
	repp(i, 1, h+1)
	{
		int c=0;
		repp(j, 1, w+2)
		{
			if((x[i][j]==1)&&(c==0))
			{
				sta[i]=j;
				c++;
			}
			if((x[i][j]==0)&&(x[i][j-1]==1)&&(c==1))
			{
				goa[i]=j-1;
				c++;
			}
			if((x[i][j]==1)&&(c==2))
			{
				muri=1;
			}
		}
		if(c==0)
		{
			muri=1;
		}
	}
	if(sta[1]!=1)
	{
		muri=1;
	}
	repp(i, 2, h+1)
	{
		if(sta[i]!=goa[i-1])
		{
			muri=1;
		}
	}
	if(goa[h]!=w)
	{
		muri=1;
	}
	if(muri==1)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << "Possible" << endl;
	}
	return 0;
}