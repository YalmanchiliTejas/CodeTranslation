#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
using namespace std;
ll M=1000000007;
int main()
{
    IOS;
    int t=1;
	//cin>>t;
	while(t--)
	{
		ll n,i,ans=0,sum=0;
		cin>>n;
		ll a[n],b[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		for(i=1;i<n;i++)
		{
			b[i]+=b[i-1];
		}
		for(i=0;i<n;i++)
		{
			sum=(a[i]%M)*((b[i]-a[i])%M);
			ans+=sum%M;
			if(ans>M) ans-=M;
		}
		cout<<ans%M<<endl;
	}
}
