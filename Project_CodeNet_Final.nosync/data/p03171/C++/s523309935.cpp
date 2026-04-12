#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
ll sieve[1000001]={0},i,j;
ll power(ll p, ll k)
{
ll a=1;
while(k)
{
if(k&1)
a=(a*p);
p=(p*p);
k>>=1;
}
return a;
}
using namespace std;
  ll countDivisors(ll n) 
{ 
    ll cnt = 0; 
    for (ll i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
  
            else 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int tc=1;
//cin>>tc;
ll cas=1;
 while(tc--)
 {
	ll n,k;
	cin>>n;
	ll a[n+1];
	for(i=0;i<n;i++)
	cin>>a[i];
	ll dp[n+1][n+1];
	for(int l=n-1;l>=0;l--)
	for(int r=l;r<n;r++)
	{
		if(l==r)
		dp[l][r]=a[l];
		else
		{
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	}
	cout<<dp[0][n-1];
	cout<<"\n"; 
 } 
}
