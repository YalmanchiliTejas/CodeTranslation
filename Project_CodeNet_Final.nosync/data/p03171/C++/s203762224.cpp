#include <bits/stdc++.h>
using namespace std;

/* Requires GNU C++ */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;

/*
  typedef base_name<
  key,
  mapped,
  key_comp_func,
  tag_specifying_datastructure,
  updating_node_invariants_policy> my_name;


  my_name s;
  s.insert(x);
  s.find_by_order(i); // index->value
  s.order_of_key(x); // value->index
*/

namespace std {
  typedef trie<
    std::string,
    null_type,
    trie_string_access_traits<>,
    pat_trie_tag,
    trie_prefix_search_node_update> pref_trie;

  typedef tree<
    int,
    null_type,
    std::less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update> order_set;
}

#ifdef HACKERLIB
#include "../src/hackerlib.h"
#endif

// a^n  in O(log n)
long long binpow(long long a, long long n) {
  long long res = 1;
  while(n > 0) {
    if(n & 1)
      res = res * a;
    a = a * a;
    n >>= 1;
  }
  return res;
}

long long logB(long long base, long double n) {
  return log(n) / log(base);
}

long long maxPrimeFactor(long long n) {
  long long maxPrime = -1;

  while(n % 2 == 0)
    maxPrime = 2, n >>= 1;

  for(long long i = 3; i <= sqrt(n); i += 2)
    while (n % i == 0)
      maxPrime = i, n = n / i;

  if(n > 2)
    return maxPrime = n;

  return maxPrime;
}

long long gcd(long long a, long long b) {
  if(a == 0)
    return b;
  return gcd(b % a, a);
}

long long lcm(long long a, long long b) {
  return (a * b) / gcd(a, b);
}

long long euler_totient(long long n) {
  long long matches = 0;
  for(long long p = 1; p < n; p++)
    if(gcd(p, n) == 1)
      matches++;
  return matches;
}

// returns <gcd, s, t>
tuple<long long, long long, long long> eea(long long a, long long b) {
  if(a == 0)
    return make_tuple(b, 0, 1);

  auto res = eea(b%a, a);
  return make_tuple(
    get<0>(res),                       // gcd continues up
    get<2>(res) - (b/a) * get<1>(res), // coefficients swapped, higher factors equivalents calculated
    get<1>(res)
  );
}

// Solve x and y for the equation ax + by = c
// Any solution: a(x + n(b/g)) + b(y - n(a/g)) = c
bool linear_diophantine(long long a, long long b, long long c, long long &x, long long &y, long long &g) {
  auto res = eea(abs(a), abs(b));
  g = get<0>(res);
  x = get<1>(res);
  y = get<2>(res);
  if(c % g)
    return false;

  x *= c / g;
  y *= c / g;
  if(a < 0) x = -x;
  if(b < 0) y = -y;
  return true;
}

// Sieve of Eratosthenes: O(n log log n)
vector<bool> prime_sieve(long long n) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;

  for(long long i = 2; i * i <= n; i++)
    if(is_prime[i])
      for(long long j = i * i; j <= n; j += i)
        is_prime[j] = false;

  return is_prime;
}

long long mod_inv(long long n, long long modulo) {
  // Support negative numbers
  n = ((n % modulo) + modulo) % modulo;

  auto eqv = eea(n, modulo);
  if(get<0>(eqv) != 1)
    return 0;

  return ((get<1>(eqv) % modulo) + modulo) % modulo;
}

long long madd(long long x, long long y, long long modulo) {
  return (x + y) % modulo;
}

long long mmult(long long x, long long y, long long modulo) {
  return (x * y) % modulo;
}

long long mpow(long long base, long long exponent, long long modulo) {
  long long res = 1;
  for(int i = 0; i < exponent; i++)
    res = (res * base) % modulo;
  return res;
}

long long mfac(long long n, long long modulo) {
  long long res = 1;
  for(int i = 2; i <= n; i++)
    res = (res * i) % modulo;
  return res;
}

// Slower, DP approach
long long mcombDP(long long n, long long k, long long modulo) {
  long long C[k+1];
  memset(C, 0, sizeof(C));
  C[0] = 1;

  for(long long i = 1; i <= n; i++)
    for(long long j = min(i, k); j > 0; j--)
      C[j] = (C[j] + C[j - 1]) % modulo;
  return C[k];
}

// Lucas theorem
long long mcomb(long long n, long long k, long long modulo) {
  if(k == 0)
    return 1;

  return (
          mcomb(n / modulo, k / modulo, modulo) *
          mcombDP(n % modulo, k % modulo, modulo)
          ) % modulo;
}

vector<string> splitString(string str, char delimiter) {
  vector<string> parts;
  string cur;

  for(char c : str) {
    if(c == delimiter) {
      parts.push_back(cur);
      cur = "";
    } else {
      cur += c;
    }
  }

  parts.push_back(cur);
  return parts;
}
#define ioFix ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define PI (2.0 * acos(0.0))
#define INF (int)1e9
#define LINF (long long)1e18
#define EPS 1e-9

#define ll long long
#define ull unsigned long long
#define ld long double

#define pii pair<int, int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define pcc pair<char, char>
#define pbb pair<bool, bool>

#define tiii tuple<int, int, int>
#define tlll tuple<long long, long long, long long>

#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vld vector<long double>
#define vvld vector<vector<long double>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvs vector<vector<string>>

#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define FOR(i, from, to) for(int (i) = from; (i) < (to); (i)++)
#define RFOR(i, from, to) for(int (i) = to-1; (i) >= (from); (i)--)
#define RANGE(i, from, to) for(int (i) = from; (i) <= (to); (i)++)
#define RRANGE(i, from, to) for(int (i) = to; (i) >= (from); (i)--)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()

#define pb push_back
#define mp make_pair
#define mt make_tuple

#define fillArray(arr, val) std::fill(std::begin(arr), std::end(arr), (val))

#define pow2(x) ((x)*(x))
#define mod(x, m) ((((x) % (m)) + (m)) % (m))
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchVector(v) { for(int xvx = 0; xvx < (v).size(); xvx++) { cout << (v)[xvx] << " "; } cout << endl; }
#define watchArray(arr, n) { for(int xax = 0; xax < (n); xax++) { cout << (arr)[xax] << " "; } cout << endl; }
#define watchMatrix(x, rows, cols) for(int r = 0; r < (rows); r++) { for(int c = 0; c < (cols); c++) { cout << (x)[r][c] << " "; } cout << endl; }


ll dp[3000+1][3000+1][2];
int N;
vll A;

ll solve(int left, int right, int turn) {
  if(dp[left][right][turn]) return dp[left][right][turn];

  if(left == right) {
    if(turn == 0) return dp[left][right][turn] = A[left];
    else return dp[left][right][turn] = -A[left];
  }

  if(turn == 0) {
    return dp[left][right][turn] = max(
               solve(left+1, right, turn^1)+A[left],
               solve(left, right-1, turn^1)+A[right]
               );
  }
  else {
    return dp[left][right][turn] = min(
                                       solve(left+1, right, turn^1)-A[left],
                                       solve(left, right-1, turn^1)-A[right]
                                       );
  }
}

int main() {
  ioFix;
  cin >> N;
  A = vll(N);
  REP(i, N)
    cin >> A[i];

  memset(dp, 0, sizeof(dp[0][0][0]) * (3001) * (3001) * 2);

  cout << solve(0, N-1, 0) << endl;
}
