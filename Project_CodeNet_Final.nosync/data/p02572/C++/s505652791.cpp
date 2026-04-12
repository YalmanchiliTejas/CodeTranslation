#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)



long long modInverse(long long a, long long m) 
{ 
    long long m0 = m; 
    long long y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
       long long q = a / m; 
        long long t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 


int main()
{
    fast_cin;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    const ll M=1e9+7;
    ll N;
    cin>>N;
    vector<ll> A(N);

    ll tot_sum=0,sq_sum=0;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        tot_sum=(tot_sum+A[i])%M;
        ll temp=(A[i]*A[i])%M;
        sq_sum=(sq_sum+temp)%M;
    }
    tot_sum=(tot_sum*tot_sum)%M;
    ll ans=(tot_sum-sq_sum+M)%M;
    
    ll inv=modInverse(2,M);
    ans=(ans*inv)%M;

    cout<<ans<<"\n";

}
