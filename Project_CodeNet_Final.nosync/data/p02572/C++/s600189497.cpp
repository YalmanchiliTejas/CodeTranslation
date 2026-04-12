#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef tuple<int, int, int> ituple;

// const int INF = INT_MAX;
// const ll INF = LLONG_MAX;
const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (200000 + 2)

void exec(){
  int n;
  ll a[MAX_N], sum = 0, ans = 0;
  cin >> n;

  for (int i = 0; i < n; i++){
    scanf("%lld", &a[i]);
    sum = (sum + a[i]) % MOD;
  }

  for (int i = 0; i < n-1; i++){
    sum -= a[i];
    if (sum < 0) {
      sum += MOD;
    }
    ans = (ans + (a[i] * sum % MOD)) % MOD;
  }

  cout << ans << endl;

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
