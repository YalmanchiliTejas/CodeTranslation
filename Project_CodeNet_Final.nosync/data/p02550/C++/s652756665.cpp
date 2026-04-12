#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =3e5+13;

int a[maxn];
int vis[maxn];
ll b[maxn];
int main()
{
	ll n;
	int x,m;
	scanf("%lld%d%d",&n,&x,&m);
	a[1]=x;
	int cnt =1;
	vis[a[1]]=1;
	int last,fir;
	while(1)
	{
		a[cnt+1]=1ll*a[cnt]*a[cnt]%m;
	    cnt++;
	    if(!vis[a[cnt]]) vis[a[cnt]]=cnt;
	    else 
		{
		last = cnt - vis[a[cnt]];
		fir = vis[a[cnt]];
		break;}
	}
	for(int i=1;i<=cnt;i++)
	{
		b[i]=b[i-1]+1ll*a[i];
	}
	
	ll ans=b[fir-1]+(b[cnt-1]-b[fir-1])*((n-fir+1)/(last))+b[(n-fir+1)%last+fir-1]-b[fir-1];
	printf("%lld",ans);
 } 