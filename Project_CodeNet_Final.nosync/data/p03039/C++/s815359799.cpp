#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli long long int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf pop_front()
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define inf 1000000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define vll vector<lli>
#define eps 0.000001
#define endl '\n'
#define mo 998244353
 
using namespace std ;
 
#define MAXN 10000000 + 2
 
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

lli power(lli x, lli y, lli p) 
{ 
    lli res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
// Returns n^(-1) mod p 
lli modInverse(lli n, lli p) 
{ 
    return power(n, p-2, p); 
} 
  
// Returns nCr % p using Fermat's little 
// theorem. 
lli nCrModPFermat(lli n, lli r, lli p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
    // Fill factorial array so that we 
    // can find all factorial of r, n 
    // and n-r 
    lli fac[n+1]; 
    fac[0] = 1; 
    for (lli i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

lli gcdExtended(lli a, lli b, lli *x, lli *y); 
  
// Function to find modulo inverse of b. It returns 
// -1 when inverse doesn't 

  
// Function to compute a/b under modlo m 
lli modDivide(lli a, lli b, lli m) 
{ 
    a = a % m; 
    lli inv = modInverse(b, m); 
    //if (inv == -1) 
       //cout << "Division not defined"; 
    return (inv * a) % m; 
} 
  
// C function for extended Euclidean Algorithm (used to 
// find modular inverse. 
lli gcdExtended(lli a, lli b, lli *x, lli *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    lli x1, y1; // To store results of recursive call 
    lli gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
  

int main()
{
////////////////////////////////////////////
    fastio;
    
    lli n,m,k;
    cin>>n>>m>>k;

    lli cnt=0;
    loopl(i,1,n+1)
    {
        loopl(j,1,m+1)
        {
            lli cnt1=0,cnt2=0;
            lli p1 = j-1 , p2 = m-j;

            cnt1 = (n*((p1*(p1+1)/2 )%mod  + (p2*(p2+1)/2 )%mod ))%mod;

            p1 = i-1 , p2 = n-i;
            cnt2 = (m*((p1*(p1+1)/2 )%mod  + (p2*(p2+1)/2 )%mod ))%mod;

            cnt = (cnt+cnt1+cnt2)%mod ;  
        }
    }
   // cout<<cnt<<endl;
    //cout<<nCrModPFermat(n*m-2,k-2,mod)<<endl;
    lli pp = (nCrModPFermat(n*m-2,k-2,mod)*cnt)%mod ;
    cout<<modDivide(pp,2,mod)<<endl;


}
