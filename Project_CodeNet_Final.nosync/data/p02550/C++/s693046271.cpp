#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef map<ll,ll>::iterator itll;
typedef long double ld;
typedef map<ll,ll> mapll;

#define con continue
#define pb push_back
#define fi first
#define se second
#define fr front()
#define INF 1000000000000000000
#define all(vl) vl.begin(),vl.end()
#define m_p make_pair 
#define sz(a) sizeof(a)
#define forn(mp,it) for(it = mp.begin();it!=mp.end();it++)
#define FOR(i,a,n) for(ll i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

const double one = 1.0;
const double PI = 3.141592653589;
const ll m = 998244353;

int main() 
{
	ll n,k,m;
	cin>>n>>k>>m;
	vector<ll> vl;
	map<ll,ll> pos;
	vl.pb(k);
	pos[k] = 1;
	ll fip,lsp;
	ll an = k;
	if(n<=m){
		ll ans = 0;
		FOR(i,0,n)
		{
			ans+=k;
			k*=k;
			k%=m;
		}
		cout<<ans<<Endl;
		return 0;
	}
	FOR(i,1,m+1)
	{
		k*=k;
		k%=m;
		if(pos[k]!=0)
		{
			fip = pos[k]-1;
			lsp = i-1;
			break;
		}
		vl.pb(k);
		pos[k] = i+1;
	}
	ll ans = 0;
	FOR(i,0,fip)
	{
		ans+=vl[i];
	}
	ll ans1 = 0;
	ll zhouqi = 0;
	FOR(i,fip,lsp+1)
	{
		zhouqi+=vl[i];
	}
	ll z = (n-(fip))/(lsp-fip+1);
	ll y = (n-(fip))%(lsp-fip+1);
	ans1= zhouqi*z;
	FOR(i,fip,fip+y)
	{
		ans1+=vl[i];
	}
//	cout<<"ans1="<<ans1<<Endl;
//	cout<<"ans="<<ans<<endl;
//	cout<<"周期="<<zhouqi<<endl;
//	cout<<"周期个数="<<z<<Endl;
//	cout<<"后缀个数="<<y<<Endl; 
//	cout<<"周期长度="<<lsp-fip+1<<endl;
	cout<<(ans1+ans)<<Endl;
	return 0;
}