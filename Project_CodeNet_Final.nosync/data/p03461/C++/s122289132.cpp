#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl; 
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#define LINK(i,graph,pos) for (REG int i=graph.head[pos];i;i=graph.next[i])

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;



int n,m;
int d[12][12];
int dd[12][12];
int c[110][110]; 
set <int> st;

int main()
{
	cin>>n>>m;
	RPT(i,1,n+1)
		RPT(j,1,m+1)
			scanf("%d",&d[i][j]);
	MST(dd,INF);
	RPT(i,0,101)
		RPT(j,0,101)
			RPT(ii,1,n+1)
				RPT(jj,1,m+1)
					c[i][j]=max(c[i][j],d[ii][jj]-i*ii-j*jj);
	RPT(i,0,101)
		RPT(j,0,101)
			RPT(ii,1,n+1)
				RPT(jj,1,m+1)
					dd[ii][jj]=min(dd[ii][jj],jj*j+ii*i+c[i][j]);
	RPT(i,1,n+1)
		RPT(j,1,m+1)
		{
			if (dd[i][j]!=d[i][j])
			{
				cout<<"Impossible"<<endl;
				return 0;
			}
		}
	cout<<"Possible"<<endl;
	cout<<202<<' '<<200+101*101<<endl;
	RPT(i,1,101)
		cout<<i<<' '<<i+1<<' '<<'X'<<endl;
	RPT(i,102,202)
		cout<<i+1<<' '<<i<<' '<<'Y'<<endl;
	RPT(i,0,101)
		RPT(j,0,101)
			cout<<i+1<<' '<<j+1+101<<' '<<c[i][j]<<endl;
	cout<<1<<' '<<102<<endl;
	return ~~(0^_^0);
}
