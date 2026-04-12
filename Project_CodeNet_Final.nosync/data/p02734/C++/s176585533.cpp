#include <iostream>

using namespace std;

typedef long long ll;
 
const int MOD = 998244353; // change if needed
 
struct Modint {
  ll val;
  
  Modint (ll _val = 0)
    : val(_val % MOD) {}
 
  Modint operator+ (Modint other) const {
    return Modint(val + other.val);
  }
 
  void operator+= (Modint other) {
    val += other.val;
    val %= MOD;
  }
 
  Modint operator- () const {
    return Modint(MOD - val);
  }
 
  Modint operator- (Modint other) const {
    return Modint(val + MOD - other.val);
  }
 
  void operator-= (Modint other) {
    val += MOD - other.val;
    val %= MOD;
  }
 
  Modint operator* (Modint other) const {
    return Modint(val * other.val);
  }
 
  void operator*= (Modint other) {
    val *= other.val;
    val %= MOD;
  }
 
  bool operator== (Modint other) const {
    return val == other.val;
  }
 
  bool operator!= (Modint other) const {
    return val != other.val;
  }
};
 
Modint exp (Modint a, int k) {
  if (k == 0) {
    return Modint(1);
  } else if (k % 2 == 0) {
    Modint half = exp(a, k / 2);
    return half * half;
  } else {
    return a * exp(a, k - 1);
  }
}
 
Modint inv (Modint a) {
  return exp(a, MOD - 2);
}
 
ostream& operator<< (ostream& out, Modint p) {
  out << p.val;
  return out;
}

const int MAX_N = 3e3 + 5;

Modint dp [MAX_N][MAX_N];
Modint cdp [MAX_N][MAX_N];

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, S;
  cin >> n >> S;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  Modint ans (0);
  for (int i = 1; i <= n; i++) {
    dp[i][arr[i]] = Modint(i);
    for (int j = arr[i] + 1; j < MAX_N; j++) {
      dp[i][j] = cdp[i - 1][j - arr[i]];
    }

    for (int j = 0; j < MAX_N; j++) {
      cdp[i][j] = cdp[i - 1][j] + dp[i][j];
    }

    ans += dp[i][S] * Modint(n - i + 1);
  }
  cout << ans << endl;
}
