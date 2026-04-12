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
#include <limits>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define repr(i, n) for(int i = n-1;i >= 0;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

const long double pi = 3.141592653589793;
const int mod = 1e9 + 7;

ll A[1<<20];int N;ll dp[1<<20];

int main() {

 // freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);

 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
cin>>N;
rep(i,N) {
  cin>>A[i];
  if(i == 0) dp[i] = A[i];
  else dp[i] = (dp[i-1] + A[i])%mod;
}
ll ans=0;
for(int i = 1;i < N;i++) {
  ans += A[i]*dp[i-1];
  ans %= mod;
}
cout<<ans;

 return 0;
}
