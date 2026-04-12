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
#define endl "\n"
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
lli d;
string s;
lli dp[10005][105];
lli fun(lli n,lli sum)
{
   if(n==0)
   {
      if(sum==0)
      return 1;
      else
      return 0;
   }
   
   if(dp[n][sum]!=-1)
   return dp[n][sum];
   
   lli ans=0;
   for(lli i=0;i<=9;i++)
   {
      ans=(fun(n-1,(sum+i)%d)+ans)%mod;
   }
   
   dp[n][sum]=ans%mod;
   return ans%mod;
}
lli f(string s)
{
   lli len=s.size();
   lli ans=0;
   lli sum=0;
   for(lli i=0;i<len;i++)
   {
      lli nu=s[i]-'0';
      for(lli j=0;j<nu;j++)
      {
         ans=(fun(len-i-1,(sum+j)%d)+ans)%mod;
      }
      sum+=nu;
      sum%=d;
   }
   ans--;
   ans+=mod;
   ans%=mod;
   return ans;
}
void solve()
{
   cin>>s;
   cin>>d;
   memset(dp,-1,sizeof(dp));
   lli ans=f(s);
   
   lli sum=0;
   for(auto it:s)
   sum+=it-'0';
   
   if(sum%d==0)
   ans++;
   ans%=mod;
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