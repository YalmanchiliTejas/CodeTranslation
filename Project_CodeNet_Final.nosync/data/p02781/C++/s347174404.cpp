#include<bits/stdc++.h>
using namespace std;
#define bolt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define text freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
typedef long long ll;
typedef long double ld;
const ll mod = 1e9+7 ;
const ld pi=3.1415926535897932384626433;
const ll inf = 1e18;
bool isprime(ll n){for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}
ll factorial(ll n){return (n==1 || n==0) ? 1:n*factorial(n-1);}
ll power(ll x,ll y){ll res=1;x=x%mod;while(y>0){if(y&1)res=((res%mod)*(x%mod))%mod;y=y>>1;x=((x%mod)*(x%mod))%mod;}return res;}
ll gcd(ll a,ll b){if (a==0)return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return (a/gcd(a,b)*b);}
ll max(ll a,ll b){ll sol=a>b?a:b;return sol;}
ll min(ll a,ll b){ll sol=a<b?a:b;return sol;}
ll dp[105][4][2];
ll k;
string s;
ll mkc(ll ind,ll noz,ll flag)
{
   if (noz>k)
      return 0;

   if (ind==s.size())
      return noz==k;

   if (dp[ind][noz][flag]!=-1)
   {
      return dp[ind][noz][flag];
   }


   ll ans=0;
   for (char i='0';i<='9';i++)
   {
      if (i<s[ind])
      ans+=mkc(ind+1,noz+(i!='0'),1);
      else
      {
         if (i==s[ind] or flag)
         ans+=mkc(ind+1,noz+(i!='0'),flag);
      }
   }
   dp[ind][noz][flag]=ans;
   return ans;
}
int main()
{
   bolt;
   memset(dp,-1,sizeof(dp));
   cin>>s>>k;
   cout<<mkc(0,0,0);
}
