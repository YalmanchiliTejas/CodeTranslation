/*input
1000000


*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

#define rep(i,j,n) for(i=j;i<n;i++)
#define repi(i,j,n) for(i=j;i>n;i--)
#define inf 100001
#define M 998244353
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define pll pair<long long,long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define vpll vector<pair<long long,long long> >
#define pb push_back
#define pf pop_front
#define mp make_pair
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds; 

template<typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ll power(ll a,ll m,ll mod){
	ll ans=1;
	while(m){
		if(m%2){
			ans*=a;
			ans%=(mod);
		}
		a=(a*a)%(mod);
		m>>=1;
	}
	return ans;
}


void init(long long* a,long long n,long long val){
	for(long long i=0;i<n;i++)
		a[i]=val;
}

ll fact[10000001],inv[10000001];

ll func(ll n,ll r){
	return (((fact[n]*inv[r])%M)*inv[n-r])%M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	ll t=1,i,j;
	ll n;
	cin>>n;
	ll ans=power(3,n,M);
	ll k=n/2+1;
	t=0;
	fact[0]=1,inv[0]=1;
	rep(i,1,10000001){
		fact[i]=i*fact[i-1];
		fact[i]%=M;
		inv[i]=power(fact[i],M-2,M);
	}
	rep(i,k,n+1){
		t+=(func(n,i)*(power(2,n-i,M)))%M;
		t%=M;
	}
	t*=2;
	t%=M;
	ans-=t;
	ans+=M;
	ans%=M;
	cout<<ans<<endl;
	return 0;
}


