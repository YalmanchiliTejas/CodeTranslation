#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
pll a[200010];
ll s11[200010],s12[200010],s21[200010],s22[200010];
int n;
int main()
{
#ifdef DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].first,&a[i].second);
		if(a[i].first<a[i].second)
			swap(a[i].first,a[i].second);
	}
	sort(a+1,a+n+1);
	s11[0]=s21[n+1]=0x7fffffffffffffff;
	s12[0]=s22[n+1]=0;
	for(i=1;i<=n;i++)
	{
		s11[i]=min(s11[i-1],a[i].second);
		s12[i]=max(s12[i-1],a[i].second);
	}
	for(i=n;i>=1;i--)
	{
		s21[i]=min(s21[i+1],a[i].second);
		s22[i]=max(s22[i+1],a[i].second);
	}
	ll ans=(a[n].first-a[1].first)*(s12[n]-s11[n]);
	for(i=1;i<n;i++)
	{
		ll x1=max(a[i].first,s22[i+1]);
		ll x2=min(a[1].first,s21[i+1]);
		ll y1=max(a[n].first,s12[i]);
		ll y2=min(a[i+1].first,s11[i]);
		ans=min(ans,(x1-x2)*(y1-y2));
	}
	printf("%lld\n",ans);
	return 0;
}