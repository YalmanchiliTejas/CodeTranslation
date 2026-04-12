#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< long long > vll;
typedef pair< int,int > ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define mp  make_pair
#define mod 1000000007
#define mod2 998244353
#define all(c) c.begin(),c.end()
#define tr(c,i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) (c.find(x) != c.end())
#define cpresent(c,x) (find(all(c),x) != c.end())
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define fo(i,n) for(ll i=0;i<n;i++)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define nl "\n"
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

unsigned long long factorial[1000004]; 
    /*factorial[0] = 1; 
    for (int i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % mod3; 
    }*/




unsigned long long power(unsigned long long x, 
                         int y, int p) 
{ 
    unsigned long long res = 1; // Initialize result 
  
    x = x % p; // Update x if it is more than or 
    // equal to p 
  
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res * x) % p; 
  
        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x * x) % p; 
    } 
    return res; 
} 



  
// Returns n^(-1) mod p 
unsigned long long modInverse(unsigned long long n, int p) 
{ 
    return power(n, p - 2, p); 
} 
unsigned long long nc(unsigned long long n, 
                                 int r, int p) 
{ 
    // Base case 
    if (r == 0) 
        return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
 
  
    return (factorial[n]* modInverse(factorial[r], p) % p * modInverse(factorial[n - r], p) % p) % p; 
} 



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   ll n;
   cin>>n;
   ll a[n+1];
   fo(i,n){
       cin>>a[i+1];
   }
   ll s1=0,s2=0;
   fo(i,n){
       s1+= a[i+1];
       s1%=mod;
       s2+= (a[i+1]*a[i+1])%mod;
       s2%=mod;
   }
   
   ll p = (s1*s1)%mod;
   p -= s2;
   if(p<0){
       p+= mod;
   }
   
   p*= (modInverse(2,mod));
   p%=mod;
   cout<<p;
    

    


	return 0;
}
