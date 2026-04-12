#include <iostream>

using namespace std;

typedef long long ll;

int MOD = 1; // change if needed

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

ll modexp (ll a, int k, ll m) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 0) {
    ll half = modexp(a, k / 2, m);
    return (half * half) % m;
  } else {
    return (a * modexp(a, k - 1, m)) % m;
  }
}

const int MAX_N = 3e3 + 5;

Modint stirl [MAX_N][MAX_N];
Modint choose [MAX_N][MAX_N];
Modint sign [MAX_N];
Modint tpow [MAX_N * MAX_N];
Modint ttpow [MAX_N];

int main () {
  int n;
  cin >> n >> MOD;

  stirl[0][0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    stirl[i][0] = 0;
    for (int j = 1; j <= n + 1; j++) {
      stirl[i][j] = Modint(j) * stirl[i - 1][j] + stirl[i - 1][j - 1];
    }
  }

  choose[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= n; j++) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }

  sign[0] = 1;
  for (int i = 1; i <= n; i++) {
    sign[i] = sign[i - 1] * Modint(MOD - 1);
  }

  tpow[0] = 1;
  for (int i = 1; i <= n * n; i++) {
    tpow[i] = Modint(2) * tpow[i - 1];
  }

  for (int i = 0; i <= n; i++) {
    ttpow[i] = exp(Modint(2), modexp(2, i, MOD - 1));
  }

  Modint ans = exp(Modint(2), modexp(2, n, MOD - 1));
  for (int k = 1; k <= n; k++) {
    // calculate the # of ways such that the
    // numbers 1..k only appear in one or zero of
    // the given sets

    Modint ways (0);
    for (int m = 0; m <= k; m++) {
      // allocate m spaces for them
      Modint cur_ways = stirl[k + 1][m + 1]; // # of surjective maybe-empty
      cur_ways *= tpow[(n - k) * m]; // ways to complete these rows
      cur_ways *= ttpow[n - k]; // ways to pick other rows
      ways += cur_ways;
    }

    ans += sign[k] * choose[n][k] * ways;
  }

  cout << ans << endl;
}
