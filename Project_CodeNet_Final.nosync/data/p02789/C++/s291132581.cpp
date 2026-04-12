#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 

ll max(ll a,ll b)
{
	if(a>b)
		return a;
	return b;
}

ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
} 

void find(vector <int> &a,ll n,int size,int i,int cur,int d,bool *flag)
{
    double y=(d/cur);
        ll temp=cur-1+ceil(y);
        if(temp<=n)
            *flag=1;
    while(i<size)
    {
        
        //cur*=a[i];
        find(a,n,size,i+1,cur*a[i],d,flag);
        //cur/=a[i];
        i++;
    }
}

int main()
{
    
   
    int n,m;
    cin>>n>>m;
    if(n==m)
        cout<<"Yes\n";
    else
        cout<<"No\n";


	return 0;
}
