#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+20;
const ll inf=1e16+1000;
ll a[N];
int n;
int main()
{
	while(cin>>n)
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],sum+=a[i];
		ll l=sum-n*(n-1),r=sum;
		for(ll k=l;k<=r;k++)
		{
			if(k<0)	continue;
			ll res=0;
			bool ok=true;
			for(int i=1;i<=n;i++)
			{
				ll x=(a[i]+k+1)/(n+1),y=(a[i]+k)/(n+1);
			//	if(x<=y)
					res+=x;
			//	else
			//		ok=false;
			}
			if(ok&&res==k)
			{
				cout<<res<<endl;
				break;
			}
		}
	}
	return 0;
}
//25720164523
//154320986863
//500000000000000000