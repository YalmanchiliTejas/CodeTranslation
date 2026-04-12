 //#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

ll Pow(ll A, ll N){
  if (N == 0) return 1;
  else{
    if (N % 2 == 0){
      return Pow(A * A % Mod, N / 2) % Mod;
    }else{
      return A * Pow(A * A % Mod, N / 2) % Mod;
    }
  }
}


int main(){

  int N; cin >> N;
  ll ans = Pow(3, N);
  
  ll Pow2 = 1, nCr = 1;
  ll sum = 1;
  for (ll i = 1; i < N / 2; i++){
    Pow2 *= 2; Pow2 %= Mod;

    nCr *= N + 1 - i; nCr %= Mod;
    nCr *= Pow(i, Mod - 2); nCr %= Mod;

    sum += Pow2 * nCr % Mod;
    sum %= Mod;
  }
  ans -= sum * 2; ans %= Mod;

  if (ans < 0) ans += Mod;
  
  cout << ans << endl;
  

  return 0;
}
