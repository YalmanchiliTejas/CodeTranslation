#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define loop(x) for(int i=0;i<x;i++)
#define sc(x) scanf("%lld",&x)
#define pr(x) printf("%lld\n",x)
#define dd fflush(stdout)
#define what_is(x) cerr << #x << " is " << x << endl;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mt make_tuple //use tie
#define eb emplace_back
typedef tuple<int,int,int> State;//use in dijkstra

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
 int n;
ll a[1000000+1];
ll dp[3004][3100];
ll solve(int st,int end ){
  ll ans=0;
  if(st>end)
    return 0;
  if(st==end)
    return a[st];
    if(dp[st][end]!=-1)
    {//cout<<"ys"<<endl;
    return dp[st][end];
    }
  ans=max(a[st]+min(solve(st+1,end-1),solve(st+2,end)),a[end]+min(solve(st+1,end-1),solve(st,end-2)));
  return dp[st][end]=ans;
}
int main(){
    IOS;   
    // int n;
   memset(dp,-1,sizeof dp);
    cin>>n;
    ll ans=0;
  loop(n)
  {cin>>a[i];
  ans+=a[i];
  }
  cout<<(2*solve(0,n-1)-ans)<<endl;
     
}
// https://atcoder.jp/contests/dp/tasks/dp_d
// https://codeforces.com/contest/1131/problem/C
 
//csjosh