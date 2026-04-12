#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
//#include <boost/lexical_cast.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define PI acos(-1)
#define P pair<int,int>
typedef tree<int,null_type,less_equal <int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
const int N=2e5+5;
int mod=1e9+7;
int fact[N],invfact[N];

int power(int base,int exp)
{
	if(exp==0)
		return 1;
	if(exp&1)
		return ((base%mod)*power((base*base)%mod,exp/2))%mod;
	else
		return power((base*base)%mod,exp/2)%mod;
}

void precompute()
{
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
	}
	invfact[N-1]=power(fact[N-1],mod-2)%mod;
	for(int i=N-2;i>=0;--i)
	{
		invfact[i]=(invfact[i+1]*(i+1))%mod;
	}
}

int ncr(int a,int b)
{
	if(b>a)
		return 0;
	int temp=0;
	temp=fact[a]%mod;
	temp*=invfact[b];
	temp%=mod;
	temp*=invfact[a-b];
	temp%=mod;
	return temp%mod;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	precompute();
	int n,m,k;
	cin>>n>>m>>k;
	int ans=0;
	int add=ncr(n*m-2,k-2)%mod;
	for(int i=1;i<=n;i++)
	{
		int temp=(m*m)%mod;
		temp=(temp*add)%mod;
		temp=(temp*((i*(i-1))%mod))%mod;
		temp=(temp*(power(2,mod-2)%mod))%mod;
		ans=(ans+temp)%mod;
	}
	for(int i=1;i<=m;i++)
	{
		int temp=(n*n)%mod;
		temp=(temp*add)%mod;
		temp=(temp*((i*(i-1))%mod))%mod;
		temp=(temp*(power(2,mod-2)%mod))%mod;
		ans=(ans+temp)%mod;
	}
	cout<<ans%mod;
	return 0;
}