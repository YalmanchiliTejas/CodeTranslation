// Don't be dead serious about your life --  it's just like a program
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minutes 
// Do not treat CP as a placement thing, love it and enjoy it, you will succeed for sure.  

#include <bits/stdc++.h>
using namespace std;
typedef  long long  int ll;
typedef long double ld;
typedef unsigned long long int ull;
//fundamentals
#define pb push_back
#define pf push_front
#define lb(v,val)  (lower_bound(v.begin(),v.end(),val)-v.begin())
#define ub(v,val)  (upper_bound(v.begin(),v.end(),val)-v.begin())
#define line cout<<"\n";
#define sortv(v) sort(v.begin(),v.end())
#define sortvd(v) sort(v.begin(),v.end(),greater<ll>())
#define lcm(a,b) (a*b/gcd(a,b))
#define all(v) ((v).begin(),(v).end())
#define v_at_in(n) *p.find_by_order(ll n)
#define mp make_pair
//loops
#define f(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define f0 for(ll i=0;i<n;i++)
#define f1 for(ll i=1;i<=n;i++)
#define fr for(ll i=n-1;i>=0;i--)
//input of array
#define inarray ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
// starter pack
#define test ll T;cin>>T;while(T--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//maximum and minimum
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))
#define endl "\n"
//some values
#define PI 3.14159265
const ll MOD=1000000000+7;
const ll MOD1 = 998244353;
const ll Val9=1000000000;
const ll Val6=1000000;
vector<ll>vd;
void no_of_divisors(ll n){
 for (ll i = 1; i <= sqrt(n); i++) {
  if (n % i == 0){
   if(n/i==i)
    {vd.pb(i);
    }
   else
   {vd.pb(i);vd.pb(n/i);
   }
  }
 }
 // no_of_divisors==vd.size();
}

ll pwr(ll x, ll y){
 ll r=1;
 while(y>0){
  if(y&1)
   r=r*x;
  x*=x;
  y>>=1;
 }
 return r;
}

ll pwrm(ll x, ll y, ll m){
 x%=m;
 ll r=1;
 while(y>0){
  if(y&1)
   r=r*x%m;
  x=x*x%m;
  y>>=1;
 }
 return r;
}
int isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;

    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;

    return 1;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a%b);
}
vector<ll>vprime;
vector<ll>vsqr;
void SieveOfEratosthenes(ll n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (ll p=2; p<=n; p++)
    {  if (prime[p])
       {vprime.pb(p);vsqr.pb(p*p);}
    }
}
 bool vis[Val6]={false};
vector<ll>v[Val6];   // Define dfs
vector<ll>ans;
void dfs(ll s,ll k)
{
    
    ll p=v[s].size();
    vis[s]=true;             // Change node to true
    f(i,0,v[s].size())      // Loop iterating till depth of that particular node
    {
        if(vis[v[s][i]]==false&&v[s][i]!=k)
        {   
            dfs(v[s][i],k);  // Recursive implementation or like backtraping to vist all the nodes in depth   
        }                   // & there neighbour nodes at depth
    }
} 

void bfs(vector<ll>v[],ll n)
{
    queue<ll>q;
   // ll level[Val6]={0};
    q.push(n);
   // level[n]=1;
    vis[n]=true;
    ll dist=0;
    while(!q.empty())
    {  
        ll p=q.front();
        q.pop();
        dist++;
        f(i,0,v[p].size())
        {
            if(vis[v[p][i]]==false){
            //level[ v[ p ][ i ] ] = level[ p ]+1;  
           // d[v[p][i]]=dist;
            q.push(v[ p ][ i ]);
            vis[ v[ p ][ i ] ] = true;}
        }
    }
}

ll nCr(ll n, ll r) 
{ 
    ll ans=1;
    f(i,0,r)
    {
        ans*=n-i;
        ans/=i+1;
    }
    return ans;
} 

int findMaxGCD(int arr[], int n) 
{ 
    // Calculating MAX in array 
    int high = 0; 
    for (int i = 0; i < n; i++) 
        high = max(high, arr[i]); 
  
    // Maintaining count array 
    int count[high + 1] = {0}; 
    for (int i = 0; i < n; i++) 
        count[arr[i]]++; 
  
    // Variable to store the 
    // multiples of a number 
    int counter = 0; 
  
    // Iterating from MAX to 1 
    // GCD is always between 
    // MAX and 1. The first 
    // GCD found will be the 
    // highest as we are  
    // decrementing the potential 
    // GCD 
    for (int i = high; i >= 1; i--) 
    { 
        int j = i; 
       counter = 0; 
    
        // Iterating from current 
        // potential GCD 
        // till it is less than 
        // MAX 
        while (j <= high) 
        { 
            // A multiple found 
  
            if(count[j] >=2) 
               return j; 
  
           else if (count[j] == 1)          
                counter++;          
  
            // Incrementing potential 
            // GCD by itself 
            // To check i, 2i, 3i.... 
            j += i; 
  
            // 2 multiples found, 
            // max GCD found 
            if (counter == 2)          
                return i; 
        } 
    } 
} 
int findGCD(int arr[], int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 
ll findProductSum(ll A[], ll n) 
{ 
    // calculating array sum (a1 + a2  ... + an) 
    ll array_sum = 0; 
    for (ll i = 0; i < n; i++) 
        array_sum = (array_sum%MOD+A[i]%MOD)%MOD; 
       //array_sum=array_sum%MOD;
    // calcualting square of array sum 
    // (a1 + a2 + ... + an)^2 
    ll array_sum_square = ((array_sum%MOD) *( array_sum%MOD))%MOD; 
    // array_sum_square=array_sum_square%MOD;
    // calcualting a1^2 + a2^2 + ... + an^2 
    ll individual_square_sum = 0; 
    for (ll i = 0; i < n; i++) 
    individual_square_sum = (individual_square_sum%MOD+((A[i]%MOD)*(A[i]%MOD))%MOD)%MOD; 
    // required sum is (array_sum_square - 
    // individual_square_sum) / 2 
    ll x= ((array_sum_square%MOD-individual_square_sum%MOD+MOD)%MOD); 
    return (x%MOD*pwrm(2,MOD-2,MOD))%MOD;
} 
int main()
{
#ifdef ENABLE_FILE_IO
freopen("testfile.txt", "r", stdin);
freopen("outfile.txt", "w", stdout);
#endif
 
fast;
// Shuru karte hai bina kisi backchodi ke_____
{ 
    ll n;cin>>n;inarray
    cout<<findProductSum(a,n);

}
// End of program Logic

    cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
