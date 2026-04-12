//csjosh

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required
// using namespace __gnu_pbds; //required 
using namespace std;

#define ll long long 
#define loop(x) for(int i=0;i<x;i++)

#define llu unsigned long long 
#define pb push_back
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld\n",x)
#define dd fflush(stdout)
#define what_is(x) cerr << #x << " is " << x << endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mt make_tuple //use tie
#define eb emplace_back
typedef tuple<int,int,int> State;//use in dijkstra
ll mod=1e9+7;
// ll power(ll x,ll y,ll mod){
//  ll ans=1;
//  while(y>0){
//   if(y&1){
//     ans=ans*x;
//   }
//   x=x*x;
//   y=y/2;
//  }
//  return ans;
// }

// typedef tree<
// pair<int, int>,
// null_type,
// less<pair<int, int>>,
// rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
 string s;
 int n;
    int d;
   ll dp[10000+5][105][3];
ll solve(int idx,int tight,int sum){
   
   ll ans=0;
   if(idx==n){
    if(sum%d==0)
    {
      return 1;
    }
    else
      return 0;
   }
   int new_tight;
   if(dp[idx][sum][tight]!=-1)
   { 
    return dp[idx][sum][tight];
   }
  int k=((tight==1)?(s[idx]-'0'):9);
   for(int i=0;i<=k;i++){
    // cout<<i<<" "<<s[idx]<<" "<<tight<<" "<<k<<endl;
    if(tight==1 && i==k){
      new_tight=1;
    }
    else
      new_tight=0;
    ans=(ans+solve(idx+1,new_tight,(sum+i)%d))%mod;
   }
   return dp[idx][sum][tight]=(ans%mod);
}    
int main(){
    IOS;  
   memset(dp,-1,sizeof dp);
    cin>>s>>d;
// index,tight,sum
   n=s.length();
    cout<<((solve(0,1,0)-1+mod)%mod)<<endl;
 }

