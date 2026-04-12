#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
 
using namespace std;

 ll mod=1e9+7;
 
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}

ll expo2(ll base,ll exponent)
{
	ll ans=1;
	while(exponent!=0)
	{
		if(exponent & 1) ans=(1LL*ans*base);
		base=(1LL*base*base);
		exponent>>=1;
	}
	return ans;
}

vector<bool>  prime(90000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=90000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=90000001; i += p) 
                prime[i] = false; 
        } 
    } 
}


int main()
{
    
    // #ifndef ONLINE_JUDGE
    //     freopen ("data.in","r",stdin);
    //     freopen ("E.out","w",stdout);
    // #endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // Sieve();
    int tests=1;
    // cin>>tests;
    while(tests--)
    {	
    	ll i,j,n,sum=0;
    	cin>>n;
    	vector<ll>a(n);
    	rep(i,0,n-1) {cin>>a[i];sum+=a[i];}
    	ll ans=0;
    	rep(i,0,n-1)
    	{
    		sum-=a[i];
    		ans+=(a[i]*((sum)%mod))%mod;
    		ans%=mod;
    	}
    	cout<<ans;
    }
    	return 0;
    
}