#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
const int maxn=1e5+10;
ll ans=0;
int a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ll now=0;
		for(int k=1;k<=(n-1)/i;k++){
			int x=n-1-k*i;
			if(x<=i||x%i==0&&x/i<=k)break;
			now+=a[x]+a[k*i];
			ans=max(ans,now);
		}
	}
	printf("%lld\n",ans);
}