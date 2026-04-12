#include<bits/stdc++.h>
#define ll long long
const int maxn=1e5+10;
using namespace std;

ll quickqow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans*=a;
		a*=a;b>>=1;
	}
	return ans;
}
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{ 
	int n,m;
	cin>>n>>m;
	if(m>=n) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}