#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod=1e9+7;

int ans=0;
int power(int x, unsigned int y, int p)  
{  
  if(x==0)
    return 1;
    int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
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

signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  
  cout.tie(0);   

  #ifndef ONLINE_JUDGE
      if(fopen("INPUT.txt","r"))
      {
      freopen ("INPUT.txt" , "r" , stdin);
      freopen ("OUTPUT.txt" , "w" , stdout);
      }
  #endif  

  int n,m,k;
  cin>>n>>m>>k;
  int f=0;
  for(int i=1;i<=n;i++)
  {
    int z=(n-i);
    f+=(z*(z+1))/2;
    z=i-1;
    f+=(z*(z+1))/2;
    f%=mod;    
  }
  f*=((m*m))%mod;
  f%=mod;
  int t=0;
  for(int i=1;i<=m;i++)
  {
    int z=(m-i);
    t+=(z*(z+1))/2;
    z=i-1;
    t+=(z*(z+1))/2;
    t%=mod;    
  }
  t*=((n*n))%mod;
  t%=mod;
  f+=t;
  f%=mod;
  f*=power(2,mod-2,mod);
  f%=mod;
  for(int i=0;i<k-2;i++)
  {
    f*=(n*m-2-i)%mod;
    f%=mod;
    f*=power(i+1,mod-2,mod);
    f%=mod;
  }
  cout<<f;

}