//i ll be the king
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define rep(n) for(ll i2=0;i2<n;i2++)
#define vmp(v,a,b) v.push_back(make_pair(a,b))
#define si(a) scanf("%lld",&a)
#define pi(a) printf("%lld",a)
#define aset(a,n,k) for(ll i3=0;i3<n;i3++)a[i3]=k; 	
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define f first
#define s second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_orde(ind)
using namespace std;
ll manhattan(ll n)
{
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ans+=(i*(i-1))/2;
		ans%=mod;
		
	}
 	return ans;
}
ll modexp(ll a,ll b)
{
	if(a==0)return 0;
	if(b==0)return 1;
	if(a==1)return 1;
	if(b%2==0)
	{
		ll val=modexp(a,b/2);
		return(val*val)%mod;
	}
	return (a*modexp(a,b-1))%mod;
}
int main()
{
	sync;
	ll n,m,k;
	cin>>n>>m>>k;
	ll dis=(manhattan(n)*(m*m)%mod+manhattan(m)*(n*n)%mod)%mod;
	ll invf[n*m],fact[n*m];
	invf[0]=invf[1]=fact[0]=fact[1]=1;
	for(ll i=2;i<=n*m;i++)
	invf[i]=(invf[i-1]*modexp(i,mod-2))%mod,
	fact[i]=(fact[i-1]*i)%mod;
	ll ncr=(invf[k-2]*invf[n*m-k])%mod;
	ncr=(ncr*fact[n*m-2])%mod;
	//cout<<dis<<" "<<ncr<<"  "<<manhattan(n)<<" "<<fact[n*m-2]<<" "<<invf[k-2]<<" "<<invf[n*m-k]<<endl;
	cout<<(ncr*dis)%mod;
}
	
