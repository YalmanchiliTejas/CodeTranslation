#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using ll = long long;
using P = pair<long long, long long>;
using MATRIX = vector< vector<ll> >;

long long sum[200001];
long long N;
long long a[200000];
const long long MOD = 1000000007;

int main() {
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  sum[N] = 0;
  rep(i, N) {
    sum[N-i-1] = sum[N-i] + a[N-i-1];
    sum[N-i-1] %= MOD;
  }
  long long ans = 0;
  rep(i, N) {
    ans += a[i] * sum[i+1];
    ans %= MOD;
  }
  cout << ans << endl;
  // rep(i, N) {
  //   cout << sum[i] << " ";
  // }
  // cout << endl;
  return 0;
}