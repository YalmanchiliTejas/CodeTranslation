#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

vector<ll> len(51, -1); 

ll dl(ll n) {
  if (len[n]!=-1) return len[n];
  if (n==0) return len[n] = 1;
  return len[n] = 2 * dl(n-1) + 3;
}

ll dfs(ll n, ll x) {
  // cout << n << " " << x << " " << len[n-1] << endl;;
  if (n==0) return 1;
  if (x==1) return 0;
  else if (x<=len[n-1]+1) return dfs(n-1, x-1);
  else if (x==len[n-1]+2) return pow(2,n);
  else if (x<=2*len[n-1]+2) return pow(2,n)+dfs(n-1, x-(len[n-1]+2));
  else return pow(2,n+1)-1;
}

int main() {
  ll N, X; cin >> N >> X;
  dl(N);
  cout << dfs(N, X) << endl;
  return 0;
}