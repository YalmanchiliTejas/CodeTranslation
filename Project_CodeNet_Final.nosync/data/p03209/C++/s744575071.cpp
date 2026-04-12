#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
     
     
#define fs first
#define sc second
     
using namespace std;
     
     
typedef long long ll;
typedef pair<ll, ll> P;


ll rec(ll n, ll x){
  if(x == 0) return 0;
  if(n == 0 && x == 1) return 1;

  ll n_layer = (1LL << (n+2)) - 3;
  ll buf = 0;
  ll xp = x;
  if(x == n_layer){
    return (1LL << (n+1)) - 1;
  }
  else if(x >= (n_layer - 3)/2 + 2){
    buf += (1LL << n);
    xp = x - ((n_layer - 3)/2 + 2);
  } else if(x == (n_layer - 3)/2 + 1){
    return (1LL << n) - 1;
  } else {
    xp = x - 1;
  }

  // cout << "n=" << n << endl;
  // cout << "nl=" << n_layer << endl;
  // cout << "xp=" << xp << endl;
  
  return buf + rec(n - 1, xp);
}
     
int main(){
  ll N, X;

  cin >> N >> X;

#ifdef DEBUG
  cout << "N=" << N << " X=" << X << endl;
#endif

  cout << rec(N, X) << endl;
  
  return 0;
}
