/*
  Hey , lakshay 05
  while( ! ( succeed == try)); // Follow this
  Don't compare yourself with anyone in the world,if you do so it means you are insulting yourself -> Bill Gates
  
*/

#include <bits/stdc++.h>
#define ll long long
#define RUNFAST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>
#define pi vector<pair<ll,ll>>
#define fi first
#define se second
#define pb push_back
#define sz size()
#define pt1(a) cout<<a<<" ";
#define pt2(a,b) cout<<a<<" "<<b<<" ";
#define pt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define sort(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define eb emplace_back
#define mp make_pair
#define MOD 1000000007 // 998244353
using namespace std;
 
ll visited[210000]={0}; 
vector<ll>vg[210000];

// Print vector

void printv(vector<ll> v)
{
   for(auto x:v)
   cout<<x<<" ";
}

// Important Functions 

// DFS
void dfs(ll current)
{
    ll i,y;
    visited[current]=1;
 //   cout<<current<<" ";
    for(i=0;i<vg[current].size();i++)
    {
        y=vg[current][i];
        if(visited[y]==0)
        dfs(y);
    }
}
 
// BFS

void bfs(ll current)
{
    ll x,y,i;
    queue<ll>q;
    q.push(current);
    visited[current]=1;
    while(!q.empty())
    {
        x=q.front();
   //     cout<<x<<" ";
        q.pop();
        visited[x]=1;
        for(i=0;i<vg[x].size();i++)
        {
            y=vg[x][i];
            if(visited[y]==0)
            {
                visited[y]=1;
                q.push(y);
            }
        }
    }
}

ll fact(ll n)
{
    ll p=1;
    for(ll i=1;i<=n;i++)
    p*=i;
    return p;
}

// Prime Numbers
void checkprime(ll N) {
        ll count = 0;
        for( ll i = 1;i * i <=N;++i ) {
             if( N % i == 0) {
                 if( i * i == N )
                         count++;
                 else       // i < sqrt(N) and (N / i) > sqrt(N)
                         count += 2;
              }
        }
        if(count == 2)
        {
           // prime number   
        }
}        

// IO File
void IO()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
}

// Multiplicative Inverse

ll power(ll x, unsigned ll y, unsigned ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y / 2, m) % m; 
    p = (p * p) % m; 
  
    return (y % 2 == 0) ? p : (x * p) % m; 
} 

ll modInverse(ll a,ll m) 
{ 
     return power(a, m - 2, m); 
     
} 
  
// LCM

ll lcm(ll a,ll b)
{  return (a*b)/__gcd(a,b);  
}

vector<ll> primeFactors(ll n)  
{  
    vector<ll>v;
    // Print the number of 2s that divide n  
    while (n % 2 == 0)  
    {  
        v.pb(2);  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            v.pb(i);  
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        v.pb(n);
    
    return v;    
}  




/* ---------------------------------------------------------------------------------------------------------*/ 
 
 void lakshay()
 {
          ll i,z=0,c,d,y=0,x,l=0,a,b,s=0,j,m,n,p=1,q,k,r;
          bool ok=true;
          cin>>n;
          vec v(n);
          for(i=0;i<n;i++)
          {
              cin>>v[i];
              s+=v[i];
    //          s%=MOD;
              s=(s+MOD)%MOD;
          }
   //       cout<<s;
          for(i=0;i<v.size();i++)
          {
              s=s-v[i];
            s=(s+MOD)%MOD;
             // s%=MOD;
         //     v[i]%=MOD;
           v[i]=(v[i]+MOD)%MOD;
              k=(s*v[i]);
              k%=MOD;
              k=(k+MOD)%MOD;
              z+=k;
              z=(z+MOD)%MOD;
          }
          pt1(z);
 }
 
int main() 
{  RUNFAST
    ll num;
num=1;
//cin>>num;
while(num--)
{ 
lakshay();
cout<<"\n";
}
return 0;
}