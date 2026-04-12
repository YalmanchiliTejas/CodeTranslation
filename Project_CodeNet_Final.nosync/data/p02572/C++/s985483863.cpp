#include<bits/stdc++.h>
 
using namespace std;
long long int modInverse(long long int a, long long int m) 
{ 
    long long int m0 = m; 
    long long int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        long long int q = a / m; 
        long long int t = m; 
  
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
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
long long int const p=1000000007;
cin>>n;
long long int a[n];
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
long long int sum=0;
long long int sum1=0;
for(int i=0;i<n;i++)
{
	sum= (sum + a[i])%(p);
	sum1 = (sum1 + a[i]*a[i])%p;
}

cout<<  ((((sum*sum)%p - sum1 + p)%p)*((modInverse(2,p))%p))%p<<endl;
}

 
 

 
