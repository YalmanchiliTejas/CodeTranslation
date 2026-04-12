#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <functional>
#include <array>
#include <climits>
//#include "debug.h"
using namespace std;
 
#define A first
#define B second
 
typedef long long ll;
constexpr int MOD = 1000000007;
 
template<typename T>
void print(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
  if (start < 0) start = 0;
  if (end < 0) end = int(v.size());
 
  for (int i = start; i < end; i++)
    cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

inline int mulmd(ll a, ll b){
  ll ret = (a * b) % MOD;
  return (int) ret;
}

inline int power(ll x, ll y, int m){
  ll res = 1;
  x = x % m;
  while(y > 0){
    if(y & 1){
      res = mulmd(res, x);
    }
    y = y >> 1;
    x = mulmd(x, x);
  }
  return (int) res;
}

inline int submd(ll a, ll b){
  ll ret = (a - b);
  if(ret < 0) ret += MOD;
  return (int) ret;
}

inline int addmd(ll a, ll b){
  ll ret = (a + b) % MOD;
  return (int) ret;
}

inline int invPow(ll a){
  return power(a, MOD - 2, MOD);
}

inline int divmd(ll a, ll b){
  ll ret = mulmd(a, invPow(b));
  return (int) ret;
}

int suf[200005];

void solve() {
  int N; cin >> N;
  vector<int> A(N); for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = N - 1; i >= 0; i--){
    if(i == N - 1) suf[i] = A[i];
    else suf[i] = addmd(suf[i + 1], A[i]);
  }
  int ans = 0;
  for(int i = 0; i < N; i++){
    ans = addmd(ans, mulmd(A[i], suf[i + 1]));
  }
  cout << ans;
}

 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  //cin >> T;
  while(T--){
    solve();
  }
}