#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N = 2e5+5;
const int M = 1e9+7;
#define pi acos(-1)
#define INF 1e10
#define INM INT_MIN
#define pb(a)  push_back(a)
#define mk(a,b) make_pair(a,b)
#define dbg(x) cout << "now this num is " << x << endl;
#define met0(axx) memset(axx,0,sizeof(axx));
#define metf(axx) memset(axx,-1,sizeof(axx));
#define sd(ax) scanf("%d",&ax)
#define sld(ax) scanf("%lld",&ax)
#define sldd(ax,bx) scanf("%lld %lld",&ax,&bx)
#define sdd(ax,bx) scanf("%d %d",&ax,&bx)
#define sddd(ax,bx,cx) scanf("%d %d %d",&ax,&bx,&cx)
#define sfd(ax) scanf("%lf",&ax)
#define sfdd(ax,bx) scanf("%lf %lf",&ax,&bx)
#define pr(a) printf("%d\n",a)
#define plr(a) printf("%lld\n",a)
LL dp[N][2],a[N];
int main()
{
	int n;sd(n);
	for(int i=1;i<=n;++i) sld(a[i]);
	dp[1][0] = dp[1][1] = 0;//注意对于1位置选i/2个元素其实是0个元素,所以1位置不用选择元素
	dp[2][0] = a[1],dp[2][1] = a[2];
	for(int i=3;i<=n;++i)
	{
		if(i&1)
		{
			dp[i][0] = max(dp[i-1][0],max(dp[i-1][1],dp[i-3][0]+a[i-2]));
			dp[i][1] = max(max(dp[i-2][0],dp[i-2][1]),max(dp[i-3][0],dp[i-3][1]))+a[i];
		}
		else 
		{
			dp[i][0] = dp[i-2][0]+a[i-1];
			dp[i][1] = max(dp[i-1][0],max(dp[i-2][0],dp[i-2][1]))+a[i];
		}
	}
	plr(max(dp[n][0],dp[n][1]));
	//system("pause");
	return 0;
}