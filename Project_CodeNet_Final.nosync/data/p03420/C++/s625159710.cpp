#include<bits/stdc++.h>
using namespace std;

typedef long long s64;

int main()
{
	//freopen("1.in","r",stdin);
	int n,k;
	cin>>n>>k;
	if(!k)
	{
		cout<<(s64)n*n;
		exit(0);
	}
	s64 ans=0;
	for(int b=1;b<=n;++b)
	for(int i=0;i<=n;i+=b)ans+=max(0,min(n+1,i+b)-(i+k));
	cout<<ans;
}