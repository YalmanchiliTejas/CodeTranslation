#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100005];
ll b[100005];
ll num=100000000;
void work_1(){
	ll ans1=0,ans2=0;
	for (int i=1;i<=(n+1)>>1;i++)
		ans1-=a[i]*2;
	ans1+=a[(n+1)>>1]+a[n>>1];
	for (int i=n;i>=(n-(n>>1)+1);i--)
		ans1+=a[i]*2;
	for (int i=1;i<=(n-1)>>1;i++)
		ans2-=a[i]*2;
	for (int i=n;i>=(n-(n>>1));i--)
		ans2+=a[i]*2;
	ans2-=a[n-(n>>1)]+a[n-(n>>1)+1];
	printf("%lld\n",max(ans1,ans2));
}
void work_2(){
	ll ans=0;
	for (int i=1;i<=n>>1;i++)
		ans-=a[i]*2;
	for (int i=n;i>=(n-(n>>1)+1);i--)
		ans+=a[i]*2;
	ans+=a[n>>1];
	ans-=a[(n>>1)+1];
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if (n&1) work_1();else work_2();
}