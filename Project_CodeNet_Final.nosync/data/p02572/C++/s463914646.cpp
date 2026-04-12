#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
#include <cmath>
#include <iomanip>
#include <math.h>
const int MOD = 1000000007;
 
 
ll POWER(ll x,ll y)
{
	ll ret=1;
	ll p=x;
	for (ll i=y;i>0;i/=2)
	{
		if (i%2) ret=(ret*p)%MOD;
		p=(p*p)%MOD;
	}
	return ret;
}
ll gcm(ll a, ll b)
{
	if (b>a) {ll c=a; a=b; b=c;}
	while (b>0)
	{
		ll r=a%b;
		a=b;
		b=r;
	}
	return a;
}
 
 
int main(int argc, char *argv[])
{
	int n;
	cin>>n;
	ll s=0,s2=0;
	for(int i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		s=(s+a)%MOD;
		s2=(s2+a*a)%MOD;
	}
	ll ret=((s*s)%MOD+(MOD-s2))%MOD;
	ret = (ret*500000004)%MOD;
	cout<<ret<<endl;
	return 0;
}
