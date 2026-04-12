#include<bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
#define mem(x,y) memset(x,y,sizeof(x))  
#define lli long long int
#define ll long long 
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define BS binary_search
#define pii pair<lli,lli>
const long long int mod=1000000007;
//const long long int mod=998244353;
const long double PI=3.141592653589793;
const long long int inf=1e18;
const long long int inf2=LLONG_MAX;
#define setBitCount(x) __builtin_popcountll(x)
#define all(a) (a).begin(), (a).end()
#define all_r(a) (a).rbegin(), (a).rend()
lli gcd(lli a,lli b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
// calculating (x^y)%p
lli power(lli x,lli y,lli p)
{
    lli res = 1;      
    x = x % p;  
    while (y > 0)
    {
        if (y & 1) //y is odd  
        res = (res*x) % p;
        y = y>>1; 
        x = ( (x%p)*(x%p) )% p;  
    }
    return res%p;
}
// calculating modular inverse using fermat little theorem
lli modInverse(lli n,lli p) 
{
    return power(n, p-2, p)%p;
}

// policy based data structures !!
#define ordered_set tree<lli, null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
// s.order_of_key (k) : Number of items strictly smaller than k
// *(s.find_by_order(k)) : K-th element in a set (counting from zero)
lli dp[3005][3005];
lli a[3005];
/*
lli fun(lli i,lli j)
{
   if(i==j)
   return a[i];
   
   if(j-i==1)
   return max(a[i],a[j]);
   
   if(dp[i][j]!=-1)
   return dp[i][j];
   
   lli ans1=a[i]+min(fun(i+2,j),fun(i+1,j-1));
   lli ans2=a[j]+min(fun(i,j-2),fun(i+1,j-1));
   lli ans=max(ans1,ans2);
   
   dp[i][j]=ans;
   return ans;
}
*/
void solve()
{
   lli n;
   cin>>n;
   
   lli sum=0;
   for(lli i=1;i<=n;i++)
   {
      cin>>a[i];
      sum+=a[i];
   }
   for(lli i=1;i<=n;i++)
   dp[i][i]=a[i];
   
   for(lli i=1;i<n;i++)
   dp[i][i+1]=max(a[i],a[i+1]);
   
   for(lli len=3;len<=n;len++)
   {
      for(lli i=1;i<=n-len+1;i++)
      {
         lli j=len+i-1;
         dp[i][j]=max(a[i]+min(dp[i+2][j],dp[i+1][j-1]),a[j]+min(dp[i+1][j-1],dp[i][j-2]));
      }
   }
   
   lli ans=dp[1][n];
   ans=2*ans-sum;
   cout<<ans;
   
}
int main()
{
   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lli T;
    //cin>>T;
    T=1;
    while(T--)
    {
        solve();
    }




    return 0;
}