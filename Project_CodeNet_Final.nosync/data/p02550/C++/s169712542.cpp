#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,m,a[N],s[N],v[N],k,ans,l,r,sz;
signed main()
{
	cin>>n>>a[1]>>m;
	s[1]=a[1];
	for(k=2;;k++)
	{
		a[k]=a[k-1]*a[k-1]%m;
		if(v[a[k]])
		{
			l=v[a[k]];
			r=k-1;
			sz=r-l+1;
			break;
		}
		s[k]=s[k-1]+a[k];
		v[a[k]]=k;
	}
	if(n<=l)
	{
		cout<<s[n]<<endl;
		return 0;
	}
	ans+=s[l-1];
	n-=l-1;
	ans+=n/sz*(s[r]-s[l-1]);
	ans+=s[l+n%sz-1]-s[l-1];
	cout<<ans<<endl;
	return 0;
}