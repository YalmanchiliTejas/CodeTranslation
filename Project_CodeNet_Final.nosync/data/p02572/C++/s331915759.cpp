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
#define FOR(i,a,n) for(int i=a;i<n;i++) 
#define FORE(i,a,n) FOR(i,a,n+1)
#define Endl endl
#define eNdl endl
#define enDl endl
#define endL endl

int main()
{
	ll n;
	cin>>n;
	vector<ll> vl(n);
	const ll mod = 1000000007;
	ll he = 0;
	FOR(i,0,n)
	{
		ll a;
		cin>>a;
		he+=a;
		vl[i] = a;
	} 
	ll ans = 0;
	FOR(i,0,n)
	{
		ll cnt = 0;
		ll ch = (he-vl[i])%mod;
		cnt = ((ch)*vl[i])%mod;
		ans+=cnt;
		ans%=mod;
	}
	if((ans%mod)%2 == 1)
	{
		cout<<(ans+mod)/2<<endl;
	}
	else
	{
		cout<<(ans%mod)/2<<endl;
	}
	return 0;
}
