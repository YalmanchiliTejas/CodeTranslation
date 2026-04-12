#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll kai[200001];
ll gyaku[200001];

//aのp乗を求める
ll jou(ll a,ll p)
{
	ll ret=1;
	ll b2[40];
	b2[0]=a;
	for(int i=1;i<40;i++)
	{
		b2[i]=b2[i-1]*b2[i-1];
		b2[i]%=MOD;
		if(b2[i]<0)
			b2[i]+=MOD;
	}

	for(ll bit=0;bit<40;bit++)
	{
		ll tmp=(p&(1LL<<bit));
		if(tmp>0)
		{
			ret*=b2[bit];
			ret%=MOD;
			if(ret<0)
				ret+=MOD;
		}
	}
	return ret;
}

int main()
{
	int n,m,k;
	ll ans=0;
	int cnt=0;
	cin>>n>>m>>k;
	//階乗
	kai[0]=1;
	for(ll i=1;i<200001;i++)
	{
		kai[i]=kai[i-1]*i;
		kai[i]%=MOD;
		if(kai[i]<0)
			kai[i]+=MOD;
	}
	//逆元
	for(int i=0;i<200001;i++)
		gyaku[i]=jou(kai[i],MOD-2);
	
	for(int i=1;i<n*m;i++)
	{
		ll tmp=abs(i%m-0%m)+abs(i/m-0/m);//コストを求める
		//cerr<<tmp<<" ";
		tmp*=kai[n*m-2];
		tmp%=MOD;
		tmp*=gyaku[k-2];
		tmp%=MOD;
		tmp*=gyaku[n*m-k];
		tmp%=MOD;
		//cerr<<tmp<<endl;
		//個数はこの四角形が入る個数分
		tmp*=(ll)(m-i%m);
		tmp%=MOD;
		tmp*=(ll)(n-i/m);
		tmp%=MOD;
		if(i%m>0 && i/m>0)
			tmp*=2;
		tmp%=MOD;
		if(tmp<0)
			tmp+=MOD;
		ans+=tmp;
		ans%=MOD;
	}
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}