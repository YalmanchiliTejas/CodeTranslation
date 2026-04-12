#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mkp make_pair
#define rep(i,s,f) for(i=s;i<f;i++)
#define db cout<<'h'<<'i'<<endl 
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define vi vector<int>
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define mod 1000000007
#define mod2 998244353
#define space 1000
//<<fixed << setprecision(9)

ll EE(ll a, ll b, ll *x, ll *y)
{
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1;
    ll gcd = EE(b%a, a, &x1, &y1); 
  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

ll inverse(ll a, ll m)
{
    ll x,y;
    EE(a,m,&x,&y);
    if(x<0) x += m;
    return x;
}

ll choose(ll n,ll k)
{
	ll i;
	ll num=1,den=1;
	for(i=2;i<=k;i++)
	{
		den*=i;
		den%=mod;
	}
	for(i=n-k+1;i<=n;i++)
	{
		num*=i;
		num%=mod;
	}
	
	i=num*inverse(den,mod);
	i%=mod;
	return i;
}

int main()
{
    int n,i,j,t,a;
    boost;
    int m,k;
    cin>>n>>m>>k;

    ll ans=0,temp;
    rep(i,1,n)
    {
        temp= (ll)(n-i)*(n-i+1)/2;
        temp%=mod;
        temp*=((ll)m*m)%mod;
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }
    swap(n,m);
    rep(i,1,n)
    {
        temp= (ll)(n-i)*(n-i+1)/2;
        temp%=mod;
        temp*=((ll)m*m)%mod;
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }
    ans*=choose((ll)n*m-2,k-2);
    ans%=mod;
    cout<<ans;
    return 0;
}

