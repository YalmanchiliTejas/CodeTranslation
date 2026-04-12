#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
using db = long double;
using ii = pair<int, int>;

const int N = 2e5+5, LG = 19, MOD = 1e9+7;
const int SQ =320;
const long double EPS = 1e-7;
int n;
ll a[200005];
ll sum[200005][2];
ll dp[200005][3];
bool vis[200005][3];
ll solve(int idx, int state){
  if(idx>n){
    if(state==0)return -1e15;
    return 0;
  }
  ll &ret = dp[idx][state];
  if(vis[idx][state])
    return ret;
  vis[idx][state]=1;
  ret=solve(idx+2,state)+a[idx];
  if(state<2)ret=max(ret,solve(idx+1,state+1));
  return ret;
}
void trace(int idx, int state){
  if(idx>n){
    return;
  }
  if(solve(idx+2,state)+a[idx]==solve(idx,state)){
//    cout<<idx<<' ';
    trace(idx+2,state);
  } else {
    trace(idx+1,state+1);
  }


}
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif

  cin>>n;
  f(i,1,n+1){
    cin>>a[i];
    sum[i][0]=sum[i-1][0];
    sum[i][1]=sum[i-1][1];
    sum[i][i&1]+=a[i];
  }
//  cout<<solve(1,0)<<'\n';
  trace(1,0);
  if(n%2==0){
    ll ans =max(sum[n][0],sum[n][1]);
    for(int i = 1; i + 1 <= n; i++){
      int cntL[2] = {};
      int cntR[2] = {};
      cntL[1] = i / 2;
      cntL[0] = (i-1) / 2;
      cntR[1] = n / 2 - (i+2)/2;
      cntR[0] = n / 2 - (i + 1) / 2;
      f(x,0,2)
        f(y,0,2){
//          cout<<cntL[x]<<' '<<cntR[y]<<'\n';
          assert((cntL[x]+cntR[y])<=n/2);
          if(cntL[x]+cntR[y]==n/2){
            ans=max(ans,sum[i-1][x]+sum[n][y]-sum[i+1][y]);
          }
        }
    }
    cout<<ans<<'\n';
  } else {
    ll ans =max(sum[n][0],sum[n-1][1]);
    ans=max(ans,sum[n][1]-sum[1][1]);
    for(int i = 1; i + 1 <= n; i++){
      int cntL[2] = {};
      int cntR[2] = {};
      cntL[1] = i / 2;
      cntL[0] = (i-1) / 2;
      cntR[1] = (n+1) / 2 - (i+2)/2;
      cntR[0] = n / 2 - (i + 1) / 2;
      f(x,0,2)
        f(y,0,2){
//          cout<<cntL[x]<<' '<<cntR[y]<<'\n';
          assert((cntL[x]+cntR[y])<=n/2);
          if(cntL[x]+cntR[y]==n/2){
            ans=max(ans,sum[i-1][x]+sum[n][y]-sum[i+1][y]);
          }
        }
    }
    cout<<max(ans,solve(1,0))<<'\n';
  }

  return 0;
}
