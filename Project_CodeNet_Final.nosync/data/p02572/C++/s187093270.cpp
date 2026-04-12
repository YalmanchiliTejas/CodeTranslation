#include <bits/stdc++.h>
#define ll                      long long
#define ld                      long double
#define ull                     unsigned long long
#define FIO                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl                    "\n"
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define vll                     vector<ll>
#define pq                      priority_queue
#define uom                     unordered_map
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define mll                     map<ll,ll>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define vvll                    vector<vll>
#define mod                     1000000007
#define MIN                     -1e9
#define pi                      3.1415926535897932384626433832795
 
using namespace std;
 
void INPUT()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}
 
/*
----------------------------------------------------------------
 
   -> Check For Overflows
   -> Out of Bounds
   -> Initialisations of global arrays and variables
   -> Read the Question and the sample test cases carefully
   -> Its not Always Complex, Try to simplify
   -> write it down and try to solve
   -> Have Faith in urself and in ur approach
   -> If it seems totally out of reach, switch to next :)
   -> And Come Back later, if possible ..
 
----------------------------------------------------------------*/
 
 
int power(int x, unsigned int y, int p)  
{  
    int res = 1;  
  
    x = x % p; 
   
    if (x == 0) return 0; 
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}
 
int main() {
 
  FIO
  INPUT();
  int n;
  cin>>n;
  ll a[n];
  fo(i,0,n-1)
  cin>>a[i];
  ll sumsq=0,sqsum=0,s=0,sumr[n]={0};
  // fo(i,0,n-1)
  // {
  //   sumsq+=a[i];
  //   sqsum+=a[i]*a[i];
  // }    
  rfo(i,n-1,0)
  {
    sumr[i]=s+a[i];
    s=sumr[i];
    sumr[i]%=mod;
  }
  ll ans=0;
  // fo(i,0,n-1)
  // {
  //   cout<<sumr[i]<<endl;
  // }
  fo(i,0,n-2)
  {
    ans+=(a[i]*sumr[i+1])%mod;
    ans %= mod;
  }
  cout<<ans%mod<<endl;
  // sqsum=sqsum;
  // sumsq=(sumsq*sumsq);
  // int res=power(2,mod-2,mod);
  // ll ans=(sumsq-sqsum);
  // ans=ans*res;
  // cout<<ans%mod<<endl;
}