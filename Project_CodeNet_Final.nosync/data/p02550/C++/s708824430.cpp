/*                                  /   \                                 */      
/*                                 /*****\                               */
/*     Jai Shree Mataji           /       \ |\| |_| $ |-| K             */
#include<vector>
#include<iostream>
#include<algorithm>                
#include<string.h>                 
#include<bits/stdc++.h>            
#include<cstring>                  
#include<map>                     
#include<cmath>                  
#include<set>
using namespace std;            
#define ll long long int        
#define ld long double
#define MOD 1000000007 
#define PI 3.1415926535897932384626433832795                                               
#define YY cout<<"YES"
#define NN cout<<"NO"
#define ee cout<<"\n"
#define ne cout<<"-1"
#define pb push_back 
#define fi first
#define se second
#define mkp make_pair    
#define sall(v ) sort(v.begin(), v.end())      
#define all(v )  v.begin(), v.end()      
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#define vl vector<ll>
#define vll vector< pair<ll,ll> > 
#define mpl map<ll, ll>
#define pr pair<ll,ll>
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b) {return (a.second < b.second); }
ll pow1(ll n,ll p){if(p==0)return 1;ll x=pow1(n, p/2);x=(x*x)%MOD;if(p%2==0) return x%MOD;else return (x*n)%MOD;}
ll pd(ll x,ll y){if(x%y==0) return x/y;else return x/y+1;}  
void SieveOfEratosthenes(ll  n, bool prime[], 
                         bool primesquare[], ll  a[]) 
{ 
    // Create a boolean array "prime[0..n]" and 
    // initialize all entries it as true. A value 
    // in prime[i] will finally be false if i is 
    // Not a prime, else true. 
    for (ll  i = 2; i <= n; i++) 
        prime[i] = true; 
  
    // Create a boolean array "primesquare[0..n*n+1]" 
    // and initialize all entries it as false. A value 
    // in squareprime[i] will finally be true if i is 
    // square of prime, else false. 
    for (ll  i = 0; i <= (n * n + 1); i++) 
        primesquare[i] = false; 
  
    // 1 is not a prime number 
    prime[1] = false; 
  
    for (ll  p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then 
        // it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p 
            for (ll  i = p * 2; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    ll j = 0; 
    for (ll  p = 2; p <= n; p++) { 
        if (prime[p]) { 
            // Storing primes in an array 
            a[j] = p; 
  
            // Update value in primesquare[p*p], 
            // if p is prime. 
            primesquare[p * p] = true; 
            j++; 
        } 
    } 
} 
  
// Function to count divisors 
ll countDivisors(ll  n) 
{ 
    // If number is 1, then it will have only 1 
    // as a factor. So, total factors will be 1. 
    if (n == 1) 
        return 1; 
  
    bool prime[n + 1], primesquare[n * n + 1]; 
  
    ll  a[n]; // for storing primes upto n 
  
    // Calling SieveOfEratosthenes to store prime 
    // factors of n and to store square of prime 
    // factors of n 
    SieveOfEratosthenes(n, prime, primesquare, a); 
  
    // ans will contain total number of distinct 
    // divisors 
    ll  ans = 1; 
  
    // Loop for counting factors of n 
    for (ll  i = 0;; i++) { 
        // a[i] is not less than cube root n 
        if (a[i] * a[i] * a[i] > n) 
            break; 
  
        // Calculating power of a[i] in n. 
        ll cnt = 1; // cnt is power of prime a[i] in n. 
        while (n % a[i] == 0) // if a[i] is a factor of n 
        { 
            n = n / a[i]; 
            cnt = cnt + 1; // incrementing power 
        } 
  
        // Calculating the number of divisors 
        // If n = a^p * b^q then total divisors of n 
        // are (p+1)*(q+1) 
        ans = ans * cnt; 
    } 
  
    // if a[i] is greater than cube root of n 
  
    // First case 
    if (prime[n]) 
        ans = ans * 2; 
  
    // Second case 
    else if (primesquare[n]) 
        ans = ans * 3; 
  
    // Third case 
    else if (n != 1) 
        ans = ans * 4; 
  
    return ans; // Total divisors 
} 
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);	
	  ll t=1;


//	   cin>>t;
	      while(t--)
{
/*
10000000000 10 99959*/
ll n,m,j,k,l,x,i;
cin>>n>>x>>m;
mpl M;
ll a[m],b[m];
ll ans=0;
ll value=x%m;
vl v[m];
ll d=1;
for(i=0;i<m;i++)
{	
    b[i]=x;
	x=(x*x)%m;
}
for(i=0;i<m;i++)
{   v[value].pb(i);
	if(M[value]==1)
	{
	j=i;
	d=v[value][1]-v[value][0];
	break;
	}
	a[i]=value;
	M[value]++;
	value=((value)*(value))%m;
}
//cout<<value<<" "<<j<<" "<<v[value][0]<<" "<<v[value][1];
//ee;

if(n<=m)
fo(i,n)
ans+=b[i];
else
{
	fo(i,v[value][0])
	ans+=a[i];
	n-=v[value][0];
	ll gap=0;
	for(ll i=v[value][0];i<v[value][1];i++)
	gap+=a[i];
//	cout<<n<<" "<<gap<<" "<<d;
//	ee;
	ans+=gap*(n/d);
	x=value;
	fo(i,n%d)
	{
		ans+=x;
		x=(x*x)%m;
	}
}

cout<<ans;
ee;











}
return 0;
}


