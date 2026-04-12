//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

#define mod 104857601
#define pb push_back
#define ep emplace_back
#define fr first
#define sc second
#define linf  (((1ll << 62) - 1) << 1)
#define inf (((1 << 30) - 1) << 1)

const double eps = 0.000000001;
#define ll long long
#define leps 1e-18
#define mkp make_pair
#define mpi unordered_map<int, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) begin(v), end(v)
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

// Utils
random_device rd;
mt19937 mt(rd());

const int N_ = 100001;
vector<int> primes;
int *least_prime;
void cieve() {
  least_prime = new int[N_];
  fill(least_prime, least_prime + N_, -1);

  for (int i = 2; i < N_; i++) {
    if (least_prime[i] == -1) {
      least_prime[i] = i;
      primes.pb(i);
    }
    for (auto &c: primes) {
      if (c * i >= N_ || c > least_prime[i]) break;
      least_prime[c * i] = c;
    }
  }
}

template<typename NType>
NType gcd(NType a, NType b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template<typename NType>
NType lcm(NType a, NType b) { return a / gcd(a, b) * b; }
template<typename NType>
NType phi(NType n_) {
  NType ans = n_;
  for (NType i = 2; i * i <= n_; i++) {
    if (n_ % i == 0) {
      while (n_ % i == 0) n_ /= i;
      ans -= ans / i;
    }
  }
  if (n_ > 1) ans -= ans / n_;
  return ans;
}

int binpow(ll a, int n, const int M = mod) {
  ll res = 1;
  while (n) {
    if (n & 1) {
      res = (a * res) % M;
      n--;
    } else {
      a = (a * a) % M;
      n >>= 1;
    }
  }
  ((res %= M) += M) %= M;
  return res;
}
// End of Utils

//ofstream cout("/Users/user/Desktop/test.txt");

void solve(int T) {
  int n;
  cin >> n;
  if(n >= 30){
    cout << "Yes";
  } else cout << "No" << endl;
}

#define MULTIPLE_TEST 0
#define PRECALC_CIEVE 0
int main(int argc, char const *argv[]){
  if (PRECALC_CIEVE) cieve();
  int t{1};
  if (MULTIPLE_TEST) scanf("%d\n", &t);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int i = 1;
  while (t-- > 0) {
    solve(i++);
  }
}
