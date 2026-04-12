#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0)
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
typedef long long ll;
#define pri(n) printf("%d\n",n)
#define lpri(n) printf("%lld\n",n);
#define rep(i,st,ed) for(int i=st;i<ed;i++)
#define var(n) int n; scn(n)
#define F first
#define S second 
#define pb push_back
const int N=3003;
// const ll M = 998244353;
const ll M=1e9+7;
const ll inf=1e18;

ll dp[N][N],pre[N];
int n;

ll range_sum(int i,int j)
{
	return i>0 ? pre[j]-pre[i-1] : pre[j];
}

ll rec(int i,int j,ll a[])
{
	if(i==j)
		return a[i];
	if(i>j)
		return 0;
	if(i+1==j)
		return max(a[i],a[j]);
	if(dp[i][j]!=0)
		return dp[i][j];
	ll minus1 = rec(i+1,j,a);
	ll minus2 = rec(i,j-1,a);

	ll val1 = a[i] + range_sum(i+1,j)-minus1;
	ll val2 = a[j] + range_sum(i,j-1)-minus2;

	ll val = max(val1,val2);
	dp[i][j]=val;

	return val;



}

int main()
{
	scn(n);
	ll a[n];
	ll total = 0;
	rep(i,0,n)
	{
		lscn(a[i]);
		pre[i]=a[i];
		if(i)
			pre[i]+=pre[i-1];
	}

	ll sum = rec(0,n-1,a);
	ll val = pre[n-1]-sum;
	sum-=val;
	printf("%lld \n",sum);
}