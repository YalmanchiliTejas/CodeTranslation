#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<string,int> P;
const ll MOD=1e9+7;
ll kuri2(ll x,ll a)
{
	ll ret=1;
	ll tmp=x;
	while(a>0)
	{
		if(a&1LL)
		{
			ret*=tmp;
			ret%=MOD;
		}
		tmp=tmp*tmp;
		tmp%=MOD;
		a>>=1LL;
	}
	if(ret<0)
		ret+=MOD;
	return ret;
}
ll kai[200001];
ll gyaku[200001];
int main()
{
	int n,m;
	ll k;
	cin>>n>>m>>k;
	ll ans=0;
	kai[0]=1;
	gyaku[0]=kuri2(kai[0],MOD-2);
	for(int i=1;i<200001;i++)
	{
		kai[i]=(kai[i-1]*i+MOD)%MOD;
		gyaku[i]=kuri2(kai[i],MOD-2);
	}
	//cerr<<(kai[10]*gyaku[10])%MOD<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i==0 && j==0)
				continue;
			ll d=i+j;
			ll cnt=(n-i)*(m-j);
			if(i>0 && j>0)
				cnt*=2;
			//cerr<<cnt<<" ";
			ll tmp=d;
			tmp*=kai[n*m-2];
			tmp%=MOD;
			tmp*=gyaku[k-2];
			tmp%=MOD;
			tmp*=gyaku[n*m-k];
			tmp%=MOD;
			tmp*=cnt;
			tmp%=MOD;
			ans+=tmp;
			ans%=MOD;
		}
		//cerr<<endl;
	}
	if(ans<0)
		ans+=MOD;
	cout<<ans<<endl;
	return 0;
}