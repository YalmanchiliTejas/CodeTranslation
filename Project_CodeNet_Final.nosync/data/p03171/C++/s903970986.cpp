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
ll a[3002];
ll dp[3002][3002][2];
ll dequeans(ll i,ll j, ll ch)
{
	if(dp[i][j][ch]!=-1)
	{
		return dp[i][j][ch];
	}
	if(i==j)
	{
		if(ch==0)
			return a[i];
		else
			return -a[i];
	}
	else
	{
		if(ch==0)
		{
			dp[i][j][ch]=max(dequeans(i+1,j,1-ch)+a[i],dequeans(i,j-1,1-ch)+a[j]);
		}
		else{
			dp[i][j][ch]=min(dequeans(i+1,j,1-ch)-a[i],dequeans(i,j-1,1-ch)-a[j]);
		}
	}
	return dp[i][j][ch];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    for (int i = 0; i <=3000; ++i)
    {
    	/* code */
    	for (int j = 0; j <=3000; ++j)
    	{
    		/* code */
    		dp[i][j][0]=-1;
    		dp[i][j][1]=-1;
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i];
    }
    cout<<dequeans(0,n-1,0)<<'\n';
}
