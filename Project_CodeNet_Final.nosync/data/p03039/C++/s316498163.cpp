#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef long double ld;

typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;

constexpr ll MOD = 1e9+7;
constexpr int INF = 1<<30;
constexpr ll  LINF = 1LL<<60;

#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define ABS(a,b) ((a)<(b)?(b)-(a):(a)-(b))
#define nbit(n) (1ll<<(n))

// sort(begin(x), end(x), greater<ll>());
// lower_bound(a.begin(), a.end(), val): a[i] ≥ valである最左の位置
// upper_bound(a.begin(), a.end(), val): a[i] > valである最左の位置

// Returns minimum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
  return a;
}

// Returns maximum of a and b.
// If a is less b, a is set to b.
template<typename T>
T chmax(T& a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

// a = (a+b)%MOD;
void addmod(ll& a, ll b) {
  a = (a+b)%MOD;
}

template <typename T>
void dumpContents(const T& v, const string& msg)
{
  cerr << "### " << msg << " ###\n";
  for (const auto& x : v) {
    cerr << x << " ";
  }
  cerr << endl;
}

struct before_main_function {
  before_main_function() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(20)<<fixed;
    #define endl "\n"
  }
} before_main_function;

// Calculate aCb mod 1000000007 in O(SIZE)
template<int SIZE>
struct Combination {
  static constexpr long long mod = 1000000007;

  long long inv[SIZE+1];           // modでの逆元
  long long factorial[SIZE+1];     // modでの階乗
  long long invfactorial[SIZE+1];  // modでの階乗の逆元

  Combination() {
    inv[1] = 1;
    // po()を使えばO(N log p)だが、O(N)で計算するアルゴリズム
    for (int i=2; i<=SIZE; i++) {
      inv[i] = mod - (mod/i)*inv[mod%i] % mod;
    }

    factorial[0] = invfactorial[0] = 1;
    for (int i=1; i<=SIZE; i++){
      factorial[i] = factorial[i-1] * i % mod;
      invfactorial[i] = invfactorial[i-1] * inv[i] % mod;
    }
  }

  long long operator()(long long a, long long b) const {
    if (b<0 || a<b) return 0;

    return (invfactorial[b] * invfactorial[a-b]) % mod * factorial[a] % mod;
  }
};
// ========== end of template ==========
int N, M, K;
int NCELLS;

int cellToI(int x, int y) {
  assert(0<=x);
  assert(x<M);
  assert(0<=y);
  assert(y<N);

  return x+y*M;
}

pii iToCell(int index) {
  assert(0<=index);
  assert(index < NCELLS);

  int x = index%M;
  int y = index/M;
  return make_pair(x, y);
}

ll calcSum(ll a, ll b) {
  ll ret = 0;

  if (b > 0) {
    ll tmp = 0;
    tmp += a*(a+1)/2;
    ll e = M-1-a;
    tmp += e*(e+1)/2;

    ret = (ret + tmp*b)%MOD;
  }
  ret = (ret + a*(a+1)/2)%MOD;

//cerr << "a: " << ret << endl;

  ll tmp = b*(b+1)/2;

//cerr << "b: " << tmp*M << endl;

  ret = (ret + tmp*M%MOD)%MOD;

  return ret;
}

constexpr int NCELL_MAX = 2*1e5+1;
Combination<NCELL_MAX> combi;

int main2(int argc, char** argv) {
  cin >> N >> M >> K;
  NCELLS = N*M; // [0, NCELLS)

  ll ret = 0;

  for (int i=1; i<NCELLS; i++) {
     pii p = iToCell(i);
     ll tmp = calcSum(p.first, p.second);

     tmp = tmp * combi(N*M-2, K-2) %MOD;

     ret = (ret + tmp)%MOD;
  }

  cout << ret << endl;
  return 0;
}

ll calc(ll X, ll Y) {
  ll ret = 0;
  for (ll d=1; d<=X; d++) {
     ll tmp = (X-d)*Y%MOD*Y%MOD;
     tmp = d*tmp%MOD*combi(X*Y-2, K-2)%MOD;
     ret = (ret+tmp)%MOD;
  }
  return ret;
}

int main(int argc, char** argv) {
  cin >> N >> M >> K;

  cout << (calc(N,M)+calc(M,N))%MOD << endl;
  return 0;
}

