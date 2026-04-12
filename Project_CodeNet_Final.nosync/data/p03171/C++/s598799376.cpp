//  Mayank Agarwal
//  IIIT Hyderabad



#include<bits/stdc++.h>
using namespace std;
const long long int M = 1000000007; 
#define ll long long int
#define ld double
#define pb push_back
#define mp make_pair
ll power(ll x, ll y,  ll p) 
{ 
    ll res = 1;      
    x = x % p;   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;x = (x*x) % p; 
    } return res%p; 
} 
ll modinver(ll a,ll b)
{
    return (power(a,1,M)*power(b,M-2,M))%M;
}
void SieveOfEratosthenes(int n) 
{   
    bool prime[10005]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
ll dp[3002][3002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    std::vector<ll> v(n);
    for(ll& x:v)
    {
    	cin>>x;
    }
    for (int l = n-1; l >=0; --l)
    {
    	for (int r = l; r < n ; ++r)
    	{
    		if(l==r)
    		{
    			dp[l][r]=v[l];
    		}
    		else
    			dp[l][r]=max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
    	}
    }
    cout<<dp[0][n-1]<<'\n';
}
