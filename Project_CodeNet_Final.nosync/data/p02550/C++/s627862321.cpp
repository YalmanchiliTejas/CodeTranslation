// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using TP = tuple<ll,ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(18);
}
signed main(){
  init_io();
  ll n,x,m,c=0,v,ans=0;
  cin >> n >> x >> m;
  vector<ll> pr(m,-1);
  v = x;
  ll pre=x;
  while(true){
    pre = v;
    v = (v*v)%m;
    if(pr[v]!=-1){
      break;
    }
    pr[v] = c;
    c++;
  }
  ll pv = v,loop_c=c-pr[v],sum;
  v = (v*v)%m;
  sum = v;
  while(v!=pv){
    v = (v*v)%m;
    sum = (sum+v);
  }
  ll val = x;
  ans = x;
  n--;
  while(n!=0){
    val = (val*val)%m;
    if(val==v&&n>=loop_c){
      ans = (ans+(n/loop_c)*sum);
      n -= (n/loop_c)*loop_c;
      val = pre;
    }else{
      ans = (ans+val);
      n--;
    }
  }
  cout << ans << endl;
}
