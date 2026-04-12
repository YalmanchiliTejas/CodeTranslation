#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>
#include <map>
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define rep(i,n) for (int i=0; i<n;++i)
typedef long long ll;
using namespace std;
const ll MOD = 1e9+7LL;
int N;
ll A[200005];
ll SUM[200005];

int main() {
  INCANT;
  cin >> N;
  rep(i, N) cin >> A[i];
  SUM[N-1] = 0ll;
  for (int i=N-2; i>=0; i--) {
    SUM[i] = SUM[i+1]+A[i+1];
    SUM[i]%=MOD;
  }
  ll ans = 0ll;
  rep(i, N-1) {
    ans+=SUM[i]*A[i];
    ans%=MOD;
  }
  cout << ans << "\n";
  return 0;
}