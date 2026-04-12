#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=998244353;
    ll n=nxtl(),s=nxtl();
    vector <ll> v(n);
    generate(all(v),nxtl);
    vector <vector <ll> > dp;
    vector <ll> row;
    row.resize(s+1,0);
    dp.resize(n,row);
    if(v[0]<=s)
        dp[0][v[0]]+=1;
    vector <ll> prefix(s+1);
    prefix=dp[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]<=s)
            (dp[i][v[i]]+=(i+1))%=mod;
        for(int j=s;j-v[i]>=0;j--)
            (dp[i][j]+=prefix[j-v[i]])%=mod;
        for(int j=0;j<=s;j++)
            prefix[j]=(prefix[j]+dp[i][j])%mod;
    }
    ll test=0;

    for(int i=0;i<n;i++)
        {
            test=(test+dp[i][s]*(n-i))%mod;
        }
    cout<<test<<endl;

    return 0;   
}


 
 
