#include <iostream>
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

Modint exp (Modint a, ll k) {
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

const int MAX_N = 105;

int arr [MAX_N];

int depc [MAX_N][MAX_N];
// depc[i][j] should be the # of deps at position i
// that started at >= j

Modint dp [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<pair<int, int>> stk; // <i, h>
  stk.push_back(make_pair(1, 0));
  int curh = arr[1];

  for (int i = 2; i <= n; i++) {
    if (arr[i] > curh) {
      stk.push_back(make_pair(i, curh));
      curh = arr[i];
    }

    if (arr[i] < curh) {
      while (stk.back().second >= arr[i]) {
        depc[i - 1][stk.back().first] += curh - stk.back().second;
        curh = stk.back().second;
        stk.pop_back();
      }

      depc[i - 1][stk.back().first] += curh - arr[i];
      curh = arr[i];
    }
  }

  while (!stk.empty()) {
    depc[n][stk.back().first] += curh - stk.back().second;
    curh = stk.back().second;
    stk.pop_back();
  }
  depc[n][1]--;
  
  for (int i = 1; i <= n; i++) {
    for (int j = MAX_N - 2; j >= 0; j--) {
      depc[i][j] += depc[i][j + 1];
    }
  }
  
  dp[1][0] = Modint(2) * exp(Modint(2), depc[1][1]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      // put in the opposite color
      dp[i + 1][j] += dp[i][j] * exp(Modint(2), depc[i + 1][j + 1]);
      // put in the same color
      dp[i + 1][i] += dp[i][j] * exp(Modint(2), depc[i + 1][i + 1]);
    }
  }
  
  Modint ans (0);
  for (int j = 0; j < n; j++) {
    ans += dp[n][j];
  }

  cout << ans << endl;
}
