#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7; // change if needed

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

const int MAX_N = 2e5 + 5;

Modint dp [MAX_N];
Modint cdp [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  if (s[0] == 'B') {
    for (int i = 0; i < m; i++) {
      if (s[i] == 'R') s[i] = 'B';
      else s[i] = 'R';
    }
  }

  vector<int> blocks;
  for (int i = 0; i < m; i++) {
    if (s[i] == 'R') {
      if (i == 0 || s[i - 1] == 'B') {
        blocks.push_back(0);
      }
      blocks.back()++;
    }
  }

  if (s.back() == 'R') {
    blocks.pop_back();
  }

  if (blocks.empty()) {
    // special case
    // just count the # of assignments
    // such that the blue things are singletons
    Modint ans (1 + n); // the all-red case
    dp[1] = Modint(1);
    cdp[1] = Modint(1);
    for (int i = 2; i < n; i++) {
      dp[i] = cdp[i - 2];
      cdp[i] = cdp[i - 1] + dp[i];
      ans += Modint(n + 1 - i) * dp[i];
    }
    cout << ans << endl;
    return 0;
  }

  int ub = n;
  for (int block : blocks) {
    if (block % 2 == 1) {
      ub = min(ub, block + 1);
    }
  }

  ub = min(ub, blocks[0] + 1);
  if (ub % 2 == 1) {
    ub++;
  }

  // do some DP to count the # of ways
  // to split a circle into odd-length pieces
  // separated by singleton pieces
  // such that each segment has length <= lb

  if (n % 2 != 0) {
    cout << 0 << endl;
    return 0;
  }
  
  Modint ans (0);
  dp[1] = Modint(1);
  cdp[1] = Modint(1);
  if (n <= ub) {
    ans += Modint(n) * dp[1];
  }
  
  for (int i = 3; i <= n; i += 2) {
    dp[i] = cdp[i - 2] - cdp[max(0, i - ub - 2)];
    cdp[i] = cdp[i - 2] + dp[i];

    if (n + 1 - i <= ub) {
      ans += Modint(n + 1 - i) * dp[i];
    }
  }

  cout << ans << endl;
}
