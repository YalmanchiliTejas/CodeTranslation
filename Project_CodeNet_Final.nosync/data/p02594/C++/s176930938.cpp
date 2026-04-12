#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define db long double
#define all(a) a.begin(),a.end()
#define pb push_back
#define f(i,l,u) for(ll i=l;i<u;i++)
#define lb lower_bound
#define ub upper_bound
#define pii pair<ll,ll> 

unsigned long long fac[200001]; 
void powe(ll p)
{

    fac[0] = 1; 
    for (int i = 1; i <= 200001; i++) 
        fac[i] = (fac[i - 1] * i) % p; 

}

unsigned long long power(unsigned long long x, 
                         ll y, ll p) 
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
unsigned long long modInverse(unsigned long long n, ll p) 
{ 
    return power(n, p - 2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
unsigned long long nCrModPFermat(unsigned long long n, 
                                 ll r, ll p) 
{ 
    // Base case 
    if (r == 0) 
        return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p; 
} 
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}


int main() {
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
ll t=1;
//cin>>t;
while(t--)
{
ll te;
cin>>te;
if(te>=30)
cout<<"Yes";
else
cout<<"No";
    
    
    
}




return 0;
}