#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#define fo(i,n) for(long long i=0;i<n;i++)
#define ll long long int
#define inf 999999999999999999
#define pb push_back
#define fi first
#define se second
#define vi vector<ll>
#define vii vector<vector<ll>>
#define pi pair<ll,ll>
#define mp make_pair
#define MOD 1000000007
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); ++it)
#define fio ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
//cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
//freopen("explicit.in", "r", stdin);
//freopen("explicit.out", "w", stdout);
 
void SieveOfEratosthenes() 
{ 
    bool prime[10000001];
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=10000000; p++) 
    { 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (ll i=p*p; i<=10000000; i += p) {
                prime[i] = false; 
            }
        } 
    }  
} 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b)
{
	if(b%a==0)
	   return a;
	return gcd(b%a,a);
}
ll nCrModpDP(ll n, ll r, ll p) 
{ 
    ll C[r+1]; 
    memset(C, 0, sizeof(C));   
    C[0] = 1;
    for (ll i = 1; i <= n; i++) 
    {
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
ll nCrModp(ll n, ll r, ll p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
   ll ni = n%p, ri = r%p; 
  
   return (nCrModp(n/p, r/p, p) * 
           nCrModpDP(ni, ri, p)) % p; 
} 
long long int moduloMultiplication(long long int a, 
                            long long int b, 
                            long long int mod) 
{ 
    long long res = 0;
    a %= mod; 
  
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 
int32_t main() 
{
    fio
	ll i,n,t,l,r,c,h,k,m,maxi,d,x;
	long long int j;
	cin>>n;
	ll a[n];
	for(j=0;j<n;j++)
		cin>>a[j];
	ll sum[n+1]={0};
	sum[n-1]=a[n-1];
	for(j=n-2;j>=0;j--)
	{
		sum[j]=(a[j]+sum[j+1]);
	}
	ll ans=0;
	// cout<<sum[1]<<endl;;
	for(j=0;j<n;j++)
	{
		c=(a[j]);
		d=(sum[j+1]);
		ans=(ans%MOD+moduloMultiplication(d,c,MOD)%MOD)%MOD;
		// ans=ans%MOD;
	}
	cout<<ans;
}


	

		