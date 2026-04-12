#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

using namespace std;
ll power(ll a,ll n)
{
          ll result=1;
          while(n>0)
          {
               if(n&1)
                    result=result*a;
               a=a*a;
               n=n>>1;
          }
          return result;
}
ll lcm(ll a,ll b)
{
          return ((a*b)/__gcd(a,b));
}
bool ispow2(ll n)
{
          return (ceil(log2(n))==floor(log2(n)));
}
bool isprime(ll n)
{
          if(n==1)
               return false;
          else if(n==2)
               return true;
          else
          {
               for(ll i=2;i*i<=n;++i)
               {
                    if(n%i==0)
                         return false;
               }
               return true;
          }
}

ll ncr(ll n,ll r)
{
    if(r > n - r)
          r = n - r;
    ll ans = 1;
    ll i;

    for(i = 1; i <= r; i++)
     {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
void sieve(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
     prime[1]=false;
     prime[0]=false;
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
          cout<<p<<" ";
}
ll findProductSum(ll A[], int n)
{
    ll array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum = (array_sum + A[i])%MOD;


    ll array_sum_square = ((array_sum%MOD) * (array_sum%MOD))%MOD;

    ll individual_square_sum = 0;
    for (int i = 0; i < n; i++)
        individual_square_sum  = (individual_square_sum + ((A[i]%MOD)*(A[i]%MOD))%MOD)%MOD;

     ll a = array_sum_square%MOD;
     ll b = individual_square_sum%MOD;

     ll temp = (((a-b+MOD)%MOD)+MOD)%MOD;
     return temp/2;
    //return (((MOD + array_sum_square - individual_square_sum)%MOD)/2)%MOD;
}
int main()
{
          ios_base::sync_with_stdio(0);
          cin.tie(0);

          int t=1;
          //cin>>t;
          while(t--)
          {
                    int n;
                    cin>>n;
                    ll a[n];
                    for(int i=0;i<n;++i)
                         cin>>a[i];
                    ll ans=0;
                    ll sum=0;
                    for(int i=0;i<n;++i)
                    {
                         ans = (ans + (a[i]*sum)%MOD)%MOD;
                         sum = (sum +a[i])%MOD;
                    }
                    cout<<ans;
          }
          return 0;
}
