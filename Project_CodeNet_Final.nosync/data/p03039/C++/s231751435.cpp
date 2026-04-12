#include <bits/stdc++.h>
using namespace std;
 
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define track(x) cout << #x << " : " << (x) << endl
#define all(v) v.begin(),v.end() 
#define allr(v) v.rbegin(),v.rend() 
//#define endl '\n'  
typedef  long long ll; 
typedef  unsigned long long ull; 
typedef vector< ll > edge; 
typedef pair< ll , ll > mypair;
typedef priority_queue <ll> max_heap;
typedef priority_queue <ll, vector<ll>, greater<ll> > min_heap;
const ll mod=1e9+7;
const ll inf=1e15;
const ll N=2e5+10;
 

ll mod_expo(ll a,ll b, ll c)
{
	ll ans=1;
	while(b)
	{
		if(b & (ll)1) ans=(ans*a)%c;
		a=(a*a)%c;
		b=b>>1;
	}
	return ans;
}
ll invese(ll n)
{
	return mod_expo(n,mod-2,mod);
} 
ll fact[N]; 
ll ncr(ll n, ll k)
{
	if(n<k) return 0;
	ll ans=1;
	ans=(ans*fact[n])%mod;
	ans=(ans*invese(fact[k]))%mod;
	ans=(ans*invese(fact[n-k]))%mod;
	return ans;
} 
 
int main()
{
	boost;
	fact[0]=1;
	for(ll i=1;i<N;i++) fact[i]=(fact[i-1]*i)%mod;
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ll n,m,k;
	cin>>n>>m>>k;
	ll ans=0,sum=0,ans1=0;
	for(ll i=1;i<=(n-1);i++)
	{
		sum+=i;
		sum%=mod;
		ans+=sum;
		ans%=mod;
	}
	ans*=m;
	ans%=mod;
	ans*=m;
	ans%=mod;	
	sum=0;	
	for(ll i=1;i<=(m-1);i++)
	{
		sum+=i;
		sum%=mod;
		ans1+=sum;
		ans1%=mod;
	}
	ans1*=n;
	ans1%=mod;
	ans1*=n;
	ans1%=mod;	
	ans+=ans1;
	ans%=mod;
	cout<<(ans*ncr(n*m-2,k-2))%mod;
  	return 0;
}
