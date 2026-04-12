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
#define bit(n) (1ll<<(n))

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

// ========== end of template ==========

int main(int argc, char** argv) {
  int N;
  cin >> N;
  vi H(N);
  for (int i=0; i<N; i++) {
    cin >> H[i];
  }

  vi mm(N);
  mm[0] = H[0];
  for (int i=1; i<N; i++) {
    mm[i] = max({mm[i-1], H[i]});
  }

  int ret = 0;
  for (int i=0; i<N; i++) {
    if (H[i] == mm[i]) ret++;
  }

  cout << ret << endl;


  return 0;
}
