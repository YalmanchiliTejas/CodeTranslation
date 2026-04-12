#include<bits/stdc++.h>
#define pb push_back
#define pf push_front

using namespace std;	
typedef long long int lli;
lli n,k,m,t,a,b,l,r,temp1,temp2,s,x,y,temp,q,d,mod=1e9+7,w,p,c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	
  	cin>>n;
  	vector<lli>v(n);
  	lli sum=0;
  	lli ans=0;
  	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		sum-=v[i];
		
		ans=(ans%mod+((v[i]%mod)*(sum%mod))%mod)%mod;
	}
	cout<<ans<<endl;
}
