#include<bits/stdc++.h>
typedef long long ll;
using namespace std;


int main()
{
	ll n,k;
	cin>>n>>k;
	ll ans=0;
	for(int i=k+1;i<=n;++i)ans+=n/i*(i-k)+(n%i!=0)*max(n-n/i*i-k+(k!=0),0ll);
	cout<<ans;
}