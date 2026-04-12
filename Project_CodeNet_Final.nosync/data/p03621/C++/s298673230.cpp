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

const int MAX_N = 1e4 + 5;

Modint fact [MAX_N];
Modint ifact [MAX_N];

Modint choose (int n, int r) {
  return fact[n] * ifact[r] * ifact[n - r];
}

Modint seqc [MAX_N]; // # of sequences length N with _exactly_ K diff values
Modint curc [MAX_N];

int main () {
  fact[0] = Modint(1);
  for (int i = 1; i < MAX_N; i++) {
    fact[i] = fact[i - 1] * Modint(i);
  }

  for (int i = 0; i < MAX_N; i++) {
    ifact[i] = inv(fact[i]);
  }

  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;
  int n = s.size();
  
  int K = 0; // # of 1s that exist only in s
  int B = 0; // # of 1s that exist both in s and t
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (t[i] == '1') B++;
      else K++;
    }
  }

  /*
  int K, B;
  cin >> K >> B;
  */

  if (K == 0) {
    cout << fact[B] * fact[B] << endl;
    exit(0);
  }
  
  // cerr << K << " " << B << endl;
  
  for (int i = 1; i <= K; i++) {
    curc[i] = exp(Modint(i), K) * choose(K, i);
    if (i % 2 != K % 2) {
      curc[i] = -curc[i];
    }
  }

  for (int i = K; i < MAX_N; i++) {
    if (i != K) {
      for (int j = 1; j <= K; j++) {
        curc[j] *= Modint(j);
      }
    }

    for (int j = 1; j <= K; j++) {
      seqc[i] += curc[j];
    }
  }

  Modint ans (0);
  for (int i = K; i <= K + B; i++) {
    // split type B in two groups
    Modint cur = choose(B, i - K);

    // # of orderings in the left half
    cur *= fact[i - K];

    // # of orderings in the right half
    cur *= fact[B - (i - K)] * fact[B - (i - K)];

    // # of splittings
    cur *= seqc[i];

    // interleaving
    cur *= choose(K + B, i);
    
    ans += cur;
    // cerr << i << " " << cur << endl;
  }

  // orderings + pairings of colors
  ans *= fact[K];

  cout << ans << endl;
}
