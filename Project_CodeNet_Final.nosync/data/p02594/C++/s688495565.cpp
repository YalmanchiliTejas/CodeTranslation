#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,avx2,fma,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0),cin.tie(0), cout.tie(0)
typedef long long ll;


ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
    if (n & 1)
      res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}

//#######################################

int main(){
  boost;

  int n;
  cin>>n;
  if(n>=30)
  cout<<"Yes";
  else 
  cout<<"No";
}

