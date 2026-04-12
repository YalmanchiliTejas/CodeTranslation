#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#define ll long long
#define lson (rt<< 1)
#define rson (rt<< 1 | 1)
#define gmid ((l+r)>> 1 )
using namespace std;

const int maxn=200050;
const int p=1e9+7;
ll f[maxn],a[maxn];

int main()
{
	int n;
	ll ans=0;
	cin>>n;
	f[0]=0;
	for(int i=1;i<=n;++i)
	  {
	  	  cin>>a[i];
	  	  f[i]=(f[i-1]+a[i])%p;
	  }
	for(int i=1;i<n;++i)
	  {
	  	  ll k;
	  	  k=(p+f[n]-f[i])%p;
	  	  ans=(ans+k*a[i])%p;
	  }	  
	cout<<ans<<endl;  
}
