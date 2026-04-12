#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
using namespace std;

 ll mod=1e9 +7;


const ll M=500006;
ll f[M],inv[M];
ll expo(ll base,ll exponent){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
void compute(){
    f[0]=1;
    rep(i,1,M-1){
        f[i]=(1LL*i*f[i-1])%mod;
    }
    inv[M-1]=expo(f[M-1],mod-2);
    for(ll i=M-2;i>=0;i--){
        inv[i]=(1LL*(i+1)*inv[i+1])%mod;
    }
}
ll C(ll n,ll r){
    return (1LL*((1LL*f[n]*inv[r])%mod)*inv[n-r])%mod;
}

vector<bool>  prime(1000002,true);
void Sieve() 
{ 
   
    for (int p=2; p*p<=1000001; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=1000001; i += p) 
                prime[i] = false; 
        } 
    } 
}

int main()
{

	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w", stdout);
 //    #endif

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    compute();

    ll tests=1,t=1;
   // cin>>tests;
    while(tests--)
    {
    	ll i,n;
    	cin>>n;
    	vector<ll>a(n+1);
    	rep(i,1,n) cin>>a[i];
    	for(i=n;i>=1;i-=2)
    	{cout<<a[i]<<" ";}
    	if(i==0) i=1;
    	else i=2;
    	while(i<=n)
    	{
    		cout<<a[i]<<" ";
    		i+=2;
    	}
    }

	return 0;
}