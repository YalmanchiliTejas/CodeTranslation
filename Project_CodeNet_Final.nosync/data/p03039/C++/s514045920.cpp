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
#include <stdio.h>
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

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll Pow(ll a, ll n){
  if (n == 0) return 1;
  if (n % 2 == 0) return Pow(a * a % MOD, n / 2);
  else return Pow(a * a % MOD, n / 2) * a % MOD;
}

ll N, M, K;
int main(){
  scanf("%lld%lld%lld", &N, &M, &K);

  ll cnt = 1;
  for (ll i = 1; i <= K - 2; i++){
    cnt *= N * M - i - 1; cnt %= MOD;
    cnt *= Pow(i, MOD - 2); cnt %= MOD;
  }

  ll Xans = 0;
  for (ll i = 1; i <= M; i++){
    Xans += N * N * (M - i) * i;
    Xans %= MOD;
  }

  ll Yans = 0; 
  for (ll i = 1; i <= N; i++){
    Yans += M * M * (N - i) * i;
    Yans %= MOD;
  }

  ll ans = (Xans + Yans) % MOD;
  ans *= cnt; ans %= MOD;
  cout << ans << endl;

  return 0;
}
