#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
 
 
 
   ll power(ll x, ll p) {
    
    	ll res = 1;
    	while (p) {
    		if (p & 1) res = (res * x) % mod;
    		x = (x*x) % mod;
    		p >>= 1;
    	}
    	return res;
    }
    
    ll f(ll A[], int n) 
{ 
   
    ll array_sum = 0; 
    for (int i = 0; i < n; i++) 
        array_sum = (array_sum%mod + A[i]%mod )%mod ; 
  
  
    ll sq = (array_sum * array_sum)%mod ; 
  
   
    ll in = 0; 
    for (int i = 0; i < n; i++) 
        in =(in +  (A[i]*A[i])%mod)%mod  ; 
       
       ll rs = (((sq - in + mod)%mod) * (power(2,mod-2)%mod )) %mod;
  
    return  rs;
} 
 
int main(void){
ll n; 
cin >> n;
ll a[n];
for (int i =  0 ; i < n; i++)
cin >> a[i];
cout << f (a , n );
}
