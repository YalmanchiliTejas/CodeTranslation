#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
void ad(ll &a,ll b)
{
	a=(a+b)%mod;
}
void mul(ll &a,ll b)
{
	a=(a*b)%mod;
}
vector<ll> fact,seq_inv,fact_inv;
void create_fact_mod(ll num)
{
	fact[0]=1;fact[1]=1;
	for(ll i=2;i<=num;i++) fact[i]=fact[i-1]*i%mod;
}
void create_seq_inv_mod(ll num)
{
	seq_inv[0]=1;seq_inv[1]=1;
	for(ll i=2;i<=num;i++) seq_inv[i]=(mod-mod/i)*seq_inv[mod%i]%mod;
}
void create_fact_inv_mod(ll num)
{
	fact_inv[0]=1;fact_inv[1]=1;
	for(ll i=2;i<=num;i++)
	fact_inv[i]=fact_inv[i-1]*seq_inv[i]%mod;
}
void create_mod_tables(ll num)
{
	fact.resize(num+1);
	seq_inv.resize(num+1);
	fact_inv.resize(num+1); 
	create_fact_mod(num);
	create_seq_inv_mod(num); 
	create_fact_inv_mod(num);
}
ll comb_mod(ll n,ll k)
{
	return fact[n]*fact_inv[n-k]%mod*fact_inv[k]%mod;
}
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll res=0;
	for(ll i=1;i<=n;i++)
	{
		ad(res,i*(n-i));
	}
	mul(res,m*m);
	//cout<<res<<endl;
	ll res1=0;
	for(ll i=1;i<=m;i++)
	{
		ad(res1,i*(m-i));
	}
	mul(res1,n*n);
	ad(res,res1);
	ll a=n*m;
	create_mod_tables(a);
	//cout<<res<<endl;
	mul(res,comb_mod(a-2,k-2));
	cout<<res<<endl;
}