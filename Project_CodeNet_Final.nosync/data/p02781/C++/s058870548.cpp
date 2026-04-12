#pragma region header
#include <bits/stdc++.h>
#define int long long
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define mp make_pair
#define mt make_tuple
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i > static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
using namespace std;

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using mii = map<int, int>;
using vm = vector<mii>;
using vvm = vector<vm>;
template <class T>
using less_queue = priority_queue<T>;
template <class T>
using greater_queue = priority_queue<T, vector<T>, greater<T>>;

constexpr int INF = 1e18;

template <class T>
void SORT(T &a) { stable_sort(all(a)); }
template <class T>
void RSORT(T &a) { stable_sort(rall(a)); }
template <class T>
void rev(T &a) { reverse(rall(a)); }
template <class T>
void uniq(T &a) { a.erase(unique(all(a)), end(a)); }
template <class T>
auto min_of(T a) { return *min_element(all(a)); }
template <class T>
auto max_of(T a) { return *max_element(all(a)); }
template <class T>
int sum_of(T a) { return accumulate(all(a), 0ll); }
template <class T, class U>
auto sum_of(T a, U init) { return accumulate(all(a), init); }
template <class T, class U>
int count_of(T a, U i) { return count(all(a), i); }
template <class T, class U>
int lower_index(T a, U i) { return lower_bound(all(a), i) - begin(a); } // use member func for set
template <class T, class U>
int upper_index(T a, U i) { return upper_bound(all(a), i) - begin(a); }
template <class T, class U>
bool binary(T a, U i) { return binary_search(all(a), i); }
template <class T, class U>
bool has(T a, U i) { return find(all(a), i) != end(a); }
template <class T>
int sz(T a) { return a.size(); };

template <class T>
void COUT(T x) { cout << x << endl; }
template <class T, class U>
void COUT(T x, U y) { cout << x << ' ' << y << endl; }
template <class T, class U, class V>
void COUT(T x, U y, V z) { cout << x << ' ' << y << ' ' << z << endl; }
template <class T>
void CSP(T x) { cout << x << ' '; }
template <class T>
void CVEC(T v) {
  int c = v.size() - 1;
  for (size_t i = 0; i < c; i++) cout << v[i] << ' ';
  if (c > -1) cout << v[c];
  cout << endl;
}

template <class T>
bool amin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int ceil_div(int x, int y) { return (x - 1) / y + 1; }

#pragma endregion header

// no MOD


void solve(string n, int k) {
  int l = sz(n);
  if(l < k) {
    COUT(0);
  } else if(k == 1) {
    int ans = n[0] - '0';
    ans += (l - 1) * 9;
    COUT(ans);
  } else if(k == 2) {
    int ans = 81 * (l - 1) * (l - 2) / 2;
    ans += (n[0] - '1') * (l - 1) * 9;
    bool non_zero = false;
    rep(i, 1, l) {
      if(non_zero)ans += 9;
      else if(n[i] > '0') {
        non_zero = true;
        ans += n[i] - '0';
      }
    }
    COUT(ans);
  } else if(k == 3) {
    int ans = 729 * (l - 1) * (l - 2) * (l - 3) / 6;
    ans += (n[0] - '1') * 81 * (l - 1) * (l - 2) / 2;
    bool non_zero = false;
    rep(i, 1, l - 1) {
      if(non_zero) rep(j, i + 1, l)ans += 81;
      else if(n[i] > '0') {
        ans += (n[i] - '1') * (l - i - 1) * 9;
        rep(j, i + 1, l) {
          if(non_zero)ans += 9;
          else if(n[j] > '0') {
            non_zero = true;
            ans += n[j] - '0';
          }
        }
        non_zero = true;
      }
    }
    COUT(ans);
  }
}


#pragma region main
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);

  string n;
  cin >> n;
  int k;
  cin >> k;
  solve(n, k);
}
#pragma endregion main
