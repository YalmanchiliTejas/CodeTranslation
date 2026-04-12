#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const int maxn=2E5+5;
ll n,x,m,ans;
ll a[maxn],sum[maxn];
inline ll f(ll x,ll m)
{
	return (x%m)*(x%m)%m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>x>>m;
	a[x]=1;
	sum[1]=x;
	ans=x;
	for(ll now=x,i=2;i<=n;++i)
	{
		now=f(now,m);
		if(a[now])
		{
			ll len=i-a[now];
			ll left=n-i+1;
			ans+=(sum[i-1]-sum[a[now]-1])*(left/len);
			ans+=(sum[a[now]-1+(left%len)]-sum[a[now]-1]);
			break;
		}
		ans+=now;
		a[now]=i;
		sum[i]=sum[i-1]+now;
	}
	cout<<ans<<endl;
	return 0;
}
