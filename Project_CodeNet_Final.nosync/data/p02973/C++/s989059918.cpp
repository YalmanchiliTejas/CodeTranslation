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

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[210000];
int col[210000];
int main()
{
	//WRT(INF);
	cin>>n;
	RPT(i,0,n)
	{
		scanf("%d",&a[i]);
		a[i]=1061108567-a[i];
	}
	int cnt=1;
	MST(col,INF);
	col[0]=a[0];
	RPT(i,1,n)
	{
		int pos=(upper_bound(col,col+cnt,a[i])-col);
		if (pos==cnt)
			cnt++;
		col[pos]=a[i];
		//cout<<a[i]<<' '<<cnt<<endl;
	}
	cout<<cnt;
	return ~~(0^_^0);
}

