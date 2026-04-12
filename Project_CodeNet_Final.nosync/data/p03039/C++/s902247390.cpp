#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define MP make_pair
#define F first
#define S second
#define inf 10000000000000
#define vll vector<ll>
using namespace std;
const int N=200005;
ll fact[N];
ll expo(ll x,ll y,ll m=mod){
    ll res=1LL;
    while(y){
        if(y&1) res=(res*x)%m;
        x=(x*x)%m;
        y/=2;
    }
    return res;
}
ll ncr(ll n,ll r)
{
	ll res=fact[n];
	res=(res*expo(fact[r],mod-2))%mod;
	res=(res*expo(fact[n-r],mod-2))%mod;
	return res;
}
void solve()
{
	ll n,m,k,i,j,p,q,ans=0;
	cin>>n>>m>>k;
	fact[0]=1;
	for(i=1;i<=n*m;i++)
		fact[i]=(fact[i-1]*i)%mod;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			{
				ans=(ans+ncr(n*m-2,k-2)*(((i*i-(i*(i+1))/2)*m)%mod))%mod;
				ans=(ans+ncr(n*m-2,k-2)*(((j*j-(j*(j+1))/2)*n)%mod))%mod;

			}		
					
		
	//ans=(ans*expo(2,mod-2))%mod;
	cout<<ans;

}
 
int main() {
    
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
 
    
    return 0;
}