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
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long
#define mod 998244353

ll inv[10000099]; // ith index will store (1/i)%mod
ll finv[10000099]; // ith index will store (1/i!)%mod
ll fact[10000099]; // ith index will store (i!)%mod
ll pow2[10000099];
int N;
ll Npow3 = 1;

void populate(int n) {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    pow2[0] = 1;
    pow2[1] = 2;
    Npow3 = 3;

    for(int i = 2;i <= n;i++) {
        fact[i] = (i*fact[i-1])%mod;
        inv[i] = mod-((inv[mod%i]*(mod/i))%mod);
        finv[i] = (finv[i-1]*inv[i])%mod;
        pow2[i] = (2*pow2[i-1])%mod;
        Npow3 = (3*Npow3)%mod;
    }
}

ll prod(ll x, ll y) {
  return (x*y)%mod;
}

ll add(ll x, ll y) {
  return (x+y)%mod;
}

int main() {
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  cin >> N;
  populate(N);

  N /= 2;

  ll ans = 0;
  for(int i = 1;i <= N;i++) {
      ans = add(ans, prod(prod(fact[2*N], finv[N+i]), prod(finv[N-i], pow2[N-i])));
  }

  ans = (Npow3-2*ans)%mod;
  ans = add(ans, mod);

  cout << ans << endl;

  return 0;
}
