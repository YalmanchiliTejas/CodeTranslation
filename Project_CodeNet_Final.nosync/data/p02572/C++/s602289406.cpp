#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n)cin >> v[i];
  vector<ll> s(n+1,0);
  rep(i,n)s[i+1] = (s[i]+v[i])%MOD;
  ll res = 0;
  rep(i,n){
    ll k = (s[n]-s[i+1]+MOD)%MOD;
    res = (res+k*v[i])%MOD;
  }
  cout << res << "\n";


  return 0;
}