#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O3")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds; 
template <typename T> 
void DEBUG_ARR(vt<T> a,char c)
{
	f(i,0,a.size())cout<<a[i]<<c;
	cout<<"\n";
}

lli tmod(lli x,lli m){return (x%m+m)%m;}//USE AT YOUR OWN RISK
lli power(lli x, lli y) 
{
    lli res = 1;  
   
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x)%mod; 
        y = y>>1; 
        x = (x*x)%mod;  
    }
    if(res<0)
       res+=mod; 
    return res; 
}


// lli fact[2000009];
// lli ncr(lli n,lli r){
//     lli ans=fact[n];
//     if(r>n)return 0;
//     ans=(ans*power(fact[n-r],mod-2))%mod;
//     ans=(ans*power(fact[r],mod-2))%mod;
//     return ans;
// }

int main() 
{ 
    fastio;
    // fact[0]=1;
    // f(i,1,2000009)fact[i]=(fact[i-1]*i)%mod;
    int t;
    // cin>>t;
    t=1;
    // int temp=t;
    while(t--){
      lli n,s;cin>>n>>s;
      lli a[n];f(i,0,n)cin>>a[i];
      lli dp[n][s+1],dp2[n][s+1];
      memset(dp,0,sizeof dp);
      memset(dp2,0,sizeof dp2);
      f(i,0,s+1){
        dp[0][i]=(i==0)||(i==a[0]);
        dp2[0][i]=(i==0)||(i==a[0]);
      }
      f(i,1,n){
        dp[i][0]=(((i+1)*(i+2))/2)%mod2;
        dp2[i][0]=i+1;
        f(j,1,s+1){
          dp[i][j]=(dp[i-1][j]+(j==a[i])+(j>=a[i])*dp2[i-1][j-a[i]]+dp2[i-1][j])%mod2;
          dp2[i][j]=(dp2[i-1][j]+(j==a[i])+(j>=a[i])*dp2[i-1][j-a[i]])%mod2;
          // cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp2[i][j]<<"\n";
        }
      }
      cout<<tmod(dp[n-1][s],mod2)<<"\n";
    }

    return 0; 	
}

