#include<bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
inline ll min(ll x,ll y) {return x<y?x:y;}
inline ll max(ll x,ll y) {return x>y?x:y;}
const int Maxn=1e5+5;
int n,a[Maxn];
ll ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n/2+1;i<=n;i++)
		ans+=2*a[i];
	for(int i=1;i<=n/2;i++)
		ans-=2*a[i];
	if(n&1)
	{
		ans-=2*a[n/2+1];
		ans+=max(a[n/2]-a[n/2+1],a[n/2+1]-a[n/2+2]);
	}	
	else	
		ans+=a[n/2]-a[n/2+1];
	cout<<ans<<endl;
 	return 0;
}
