#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e7,p=998244353;
int n,v[N],o[N],c[N],z[N],bi[N];
#define C(x,y) (o[x]*c[y]%p*c[x-y]%p)
main()
{v[1]=o[1]=c[1]=1;z[0]=bi[0]=c[0]=1;
for(int i=2;i<=1e7;i++)v[i]=p-v[p%i]*(p/i)%p,o[i]=o[i-1]*i%p,c[i]=c[i-1]*v[i]%p;
for(int i=1;i<=1e7;i++)bi[i]=bi[i-1]*3%p,z[i]=z[i-1]*2%p;
	cin>>n;int ans=bi[n];
	for(int i=n/2+1;i<=n;i++)ans=(ans-C(n,i)*z[n-i+1]%p)%p;cout<<(ans+p)%p;
}
