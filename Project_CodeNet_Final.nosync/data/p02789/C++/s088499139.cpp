#include <bits/stdc++.h>
#include <ctime>
#include <unordered_map>
#include <stdlib.h>
using namespace std;
#define ll  long long int
#define mod 1000000007
#define modd 998244353
#define com(a,n) for(ll i=0;i<n;i++) cin>>a[i];
#define pri(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<endl;
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
/*__builtin_clz();
__builtin_ctz();
__builtin_popcount();*/
int main()
{
    ll n,m;
    cin>>n>>m;
    if(n==m)
    cout<<"Yes"<<"\n";
    else 
    cout<<"No"<<"\n";
    cerr << "\nTime elapsed: " << 1000 * clock()/CLOCKS_PER_SEC << "ms\n";
}





// bool prime[100000];

// // int gcdExtended(int a, int b, int *x, int *y) ;
// ll modInverse(int a, int m) 
// { 
//     int x, y; 
//     int g = gcdExtended(a, m, &x, &y); 
//     // if (g != 1) 
//     //     cout << "Inverse doesn't exist"; 
//     // else
//     // { 
//         // m is added to handle negative x 
//         int res = (x%m + m) % m; 
//         return res; 
//     // } 
// } 
  
// // // C function for extended Euclidean Algorithm 
// int gcdExtended(int a, int b, int *x, int *y) 
// { 
//     // Base Case 
//     if (a == 0) 
//     { 
//         *x = 0, *y = 1; 
//         return b; 
//     } 
  
//     int x1, y1; // To store results of recursive call 
//     int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
//     // Update x and y using results of recursive 
//     // call 
//     *x = y1 - (b/a) * x1; 
//     *y = x1; 
  
//     return gcd; 
// } 
// ll modu(ll x)
// {
//     if(x<0)
//     {
//         x+=mod;
//     }
//     else 
//     {
//         x=x%mod;
//     }
//     return x;
// }

// void SieveOfEratosthenes(int n) 
// { 
//     // Create a boolean aay "prime[0..n]" and initialize 
//     // all entries it as true. A value in prime[i] will 
//     // finally be false if i is Not a prime, else true. 
     
//     memset(prime, true, sizeof(prime)); 
  
//     for (int p=2; p*p<=n; p++) 
//     { 
//         // If prime[p] is not changed, then it is a prime 
//         if (prime[p] == true) 
//         { 
//             // Update all multiples of p greater than or  
//             // equal to the square of it 
//             // numbers which are multiple of p and are 
//             // less than p^2 are already been marked.  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
//     prime[1]=false;
  
//     // Print all prime numbers 
//     // for (int p=2; p<=n; p++) 
//     //    if (prime[p]) 
//     //       cout << p << " "; 
// } 
// ll power(ll x, unsigned ll y, ll p) 
// { 
//     ll res = 1;      // Initialize result 
  
//     x = x % p;  // Update x if it is more than or  
//                 // equal to p 
  
//     while (y > 0) 
//     { 
//         // If y is odd, multiply x with result 
//         if (y & 1) 
//             res = (res*x) % p; 
  
//         // y must be even now 
//         y = y>>1; // y = y/2 
//         x = (x*x) % p;   
//     } 
//     return res; 
// } 