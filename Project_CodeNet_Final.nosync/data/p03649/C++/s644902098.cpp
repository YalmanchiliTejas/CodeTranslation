#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll a[110],ans;
bool work(){
	int p=1;
	for (int i=1;i<=n;i++) if (a[i]>a[p]) p=i;
	if (a[p]<n) return 0;
	ll cnt=a[p]/n;ans+=cnt;
	a[p]%=n;a[p]-=cnt;
	for (int i=1;i<=n;i++) a[i]+=cnt;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while (work());
	printf("%lld\n",ans);
	return 0;
}