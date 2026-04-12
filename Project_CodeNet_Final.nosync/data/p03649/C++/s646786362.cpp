#include <cstdio>
typedef long long ll;

ll ans[55];
int n;
/*bool check(ll lim)
{
	ll btm=n-1-lim;
	ll res=0;
	for(int i=1;i<=n;i++)
		if(ans[i]>btm)
			res+=(ans[i]-btm-1)/(n+1)+1;
	printf("res %lld lim %lld\n",res,lim);
	return res>=lim;
}
*/

int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&ans[i]);
	ll res=0;
	while(1)
	{
		int flag=0;
		for(int i=1;i<=n;i++)
			if(ans[i]>=n)
			{
				flag=1;
				ll mns=ans[i]/n;
				res+=mns;
				ans[i]%=n;
				for(int j=1;j<=n;j++)
					if(i!=j)
						ans[j]+=mns;
//				break;
			}
		if(!flag) break;
	}
	printf("%lld\n",res);
/*	ll l=0,mid;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%lld\n",l);
	*/
}
