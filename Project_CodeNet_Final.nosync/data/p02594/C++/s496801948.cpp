#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define powerof2 ()
#define mp make_pair
#define pi acos(-1)
using ll = long long;
const ll M = 1000000007;
const ll M1= 998244353;
using vl = vector<ll>;
using pll =  pair<ll,ll>;
ll power(ll x,ll y){
	if(y==0)
		return 1;
	ll res=power(x,y/2);
	res=(res*res);
	if(y&1)
		res=(res*x);
	return res;
}
 
ll powermod(ll x,ll y,ll mod){
	if(y==0)
		return 1;
	ll res=powermod(x,y/2,mod);
	res=(res*res)%mod;
	if(y&1)
		res=(res*x)%mod;
	return res;
}
/*ll binarysearch(ll va)
{
	ll n=1;
	ll l=va+1,u=n;
	ll st=num.order_of_key(va);
	while(l+1<u)
	{
		m=(l+u)/2;
		ll in=num.order_of_key(m);
		if(in-st==m-va)
		{
			l=m;
		}
		else
		{
            u=m;
		}
	}
	if(num1.find(l)==num1.end())
		return l;
	return u;
}*/
void solve(){
	int x;
	cin>>x;
	if(x>=30) cout<<"Yes\n";
	else cout<<"No\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
 
    for(int i=1;i<=t;i++)
    {//cout<<"Case #"<<i<<": ";
    solve();}
    return 0;
}
