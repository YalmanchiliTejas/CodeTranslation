#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=1e5+50;
const int mod=1e9+7;
using namespace std;
int n,m,i,v,u,x,y,t,p,j;
ll a[205][205],f[405][205][205];
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j];
	for(i=1;i<=n+m-1;i++)
	{
		for(x=1;x<=n;x++)
		{
			for(y=1;y<=n;y++)
			{
				v=i-x+1,u=i-y+1;
				if(v<=0 || u<=0)continue;
				//cout<<x<<" "<<v<<" "<<y<<" "<<u<<endl;
				for(t=-1;t<1;t++)
				{
					for(p=-1;p<1;p++)
					{
						f[i][x][y]=max(f[i][x][y],f[i-1][x+t][y+p]);
					}
				}
				f[i][x][y]+=a[x][v]+a[y][u];
				if(x==y && v==u)f[i][x][y]-=a[x][v];
			}
		}
	}
	cout<<f[n+m-1][n][n]<<endl;
    return 0;
}