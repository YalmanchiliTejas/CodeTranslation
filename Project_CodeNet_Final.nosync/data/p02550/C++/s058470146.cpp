#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  ll n,x,m;
  cin >> n >> x >> m;
  ll X = x;
  if(n <= 100000){
    ll res = 0;
    rep(i,n){
      res += x;
      x = x*x%m;
    }
    cout << res << "\n";
    return 0;
  }
  ll roop = 0;
  ll sum = 0;
  vector<int> d(m);
  int cnt = 0;
  while(d[x] == 0){
    cnt++;
    d[x] = cnt;
    sum += x;
    x = x*x%m;
    roop++;
  }
  ll res = 0;
  while(X != x){
    res += X;
    sum -= X;
    X = X*X%m;
    n--;
    roop--;
  }
  ll k = n/roop;
  res += k*sum;
  rep(i,n%roop){
    res += x;
    x = x*x%m;
  }
  cout << res << "\n";


  return 0;
}