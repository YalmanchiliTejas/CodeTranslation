#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
long long a[100];
long long ans;
long long n;
void findls(long long &ls){
	while(ls>1&&a[n]-a[ls-1]<=n+1) ls--;
}
void qdown(long long ls)
{
	long long x=n-ls+1;
	long long k=(a[n]-a[ls-1])/(long long)((long long)n-(x-1)+x);
	for(long long i=ls;i<=n;i++)
		a[i]=a[i]-k*((long long)n-(x-1));
	for(long long i=1;i<ls;i++)
		a[i]=a[i]+k*(long long)x;
	ans=ans+k*x;
}
void work()
{
	a[n]=a[n]-n;
	for(long long i=1;i<n;i++)
		a[i]++;
	sort(a+1,a+n+1);
	ans++;
}
void play(long long ls){
	while(a[n]-a[ls-1]>n+1)
		work();
}
void solve(){
	long long k=a[n]-(n+n+n+n);
	if(k<0) return;
	ans=ans+k*n;
	for(long long i=1;i<=n;i++)
		a[i]-=k;
}
int main()
{
//	freopen("C.in","r",stdin);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long ls=n;
	while(ls>1)
	{
		findls(ls);
		if(ls==1)
		{
			solve();
			break;
		}
		qdown(ls);
		play(ls);
	}
	while(a[n]>=n)
		work();
	printf("%lld\n",ans);
	return 0;
}