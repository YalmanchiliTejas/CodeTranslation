#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <complex>
#include <vector>
#include<limits>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const long double pi = 3.141592653589793;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define F first
#define S second

// #define COMMENT

/*

const int NN = 200090;
ll fact[NN];
ll finv[NN];
ll inv[NN];

void inverse_modulao() {
  fact[0] = fact[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;

  for(int i = 2;i < NN;i++) {
    fact[i] = fact[i-1]*i%mod;
    inv[i] = mod-mod/i*inv[mod%i]%mod;
    finv[i] = finv[i-1]*inv[i]%mod;
  }
}

ll nCr(int n, int r) {
  return fact[n]*finv[r]%mod*finv[n-r]%mod;
}

*/

int A[1<<20], N;
ll dp[1<<20];

// a b c d e f g h
//   1   1   1   1
//
// g h i

ll find_max(int i) {
  if(i == N-1) {
    return 0;
  }

  return max(dp[i+1], A[i] + find_max(i+2));
}

int main() {

//  freopen("input.in","r",stdin);
//  freopen("output.out","w",stdout);

  cin >>  N;
  rep(i, N) cin >> A[i];
  dp[N-1] = A[N-1];
  int i = N-3;
  while(i >= 0) {
    dp[i] = dp[i+2] + A[i];
    i -= 2;
  }

  i = N-2;
  while(i >= 0) {
    dp[i] = max(dp[i+1], A[i]+dp[i+2]);
    i-=2;
  }

  if(N%2==0) {
    cout << dp[0] << endl;
    return 0;
  }

  cout << find_max(0) << endl;


  return 0;
}
