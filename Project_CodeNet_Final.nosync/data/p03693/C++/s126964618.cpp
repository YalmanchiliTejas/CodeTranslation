// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
signed main(){
  ll r,g,b;
  cin >> r >> g>> b;
  r = r*100 + g*10 + b;
  if(r%4==0) cout <<"YES\n";
  else cout <<"NO\n";
}
