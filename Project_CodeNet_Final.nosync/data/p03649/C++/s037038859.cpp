#include <bits/stdc++.h>
#pragma once
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
typedef long double lb;
#define int long long
#define double long double
#define endn "\n"
typedef pair<int,int> P;
const int MOD = 1000000007;
const ll INF = 1e16;
const double EPS = 1e-10;
const double PI = 3.141592653589793;
template<class T> inline bool chmin(T& a, T b){if(a>b){a = b;return 1;}return 0;}
template<class T> inline bool chmax(T& a, T b){if(a<b){a = b;return 1;}return 0;}
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 


////////////////////////////////////////////////////////////////////
vector<int> divisor(int n){
  vector<int> ret;
  for(int i = 1;i*i <= n;i++){
    if(n % i == 0){
      ret.push_back(i);
      if(n/i != i)ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
map<int, int> prime_factor(int n){
  map<int, int> ret;
  for(int i = 2;i*i <= n;i++){
    while(n % i == 0){
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1){
    ret[n] = 1;
  }
  return ret;
}
////////////////////////////////////////////////////////////////////

int n,a[60], b[60];
signed main(){
  cin>>n;rep(i,n)cin>>a[i];
  int ans = 0;
  while(true){
    int sum = 0, m = 0;
    rep(i,n){
      b[i] = a[i]/n;
      ans += b[i];
      sum += b[i];
    }
    rep(i,n){
      a[i] = (a[i]%n) + sum - b[i];
      chmax(m, a[i]);
    }
    if(m < n)break;
  }
  cout << ans << endl;
}
