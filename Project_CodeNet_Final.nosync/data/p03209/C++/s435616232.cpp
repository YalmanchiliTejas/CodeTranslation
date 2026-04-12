#pragma region header
#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define SORT(a) stable_sort(all(a))
#define RSORT(a) stable_sort(rall(a))
#define rev(a) reverse(all(a))
#define uniq(a) a.erase(unique(all(a)), end(a))
#define lambda(i) [=](auto i)
#define compare(i, j) [=](auto i, auto j)
#define min_of(a) *min_element(all(a))
#define max_of(a) *max_element(all(a))
#define sum(a) accumulate(all(a), 0)
#define count_of(a, i) count(all(a), i)
#define lower(a, i) (lower_bound(all(a), i) - begin(a)) // use member func for set
#define upper(a, i) (upper_bound(all(a), i) - begin(a))
#define binary(a, i) binary_search(all(a), i)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define sz(a) (int)(a).size()
#define rep1(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define rrep1(i, n) for (auto i = n - 1; i != static_cast<decltype(i)>(-1); i--)
#define rep2(i, a, b) for (auto i = (a); i < (b); i++)
#define rrep2(i, a, b) for (auto i = b - 1; i >= a; i--)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep2, rep1) (__VA_ARGS__)
#define rrep(...) GET_MACRO(__VA_ARGS__, rrep2, rrep1) (__VA_ARGS__)
#define each(i, a) for (auto &&i : (a))
using namespace std;

const int INF = 1e18;
const int MOD = 1e9 + 7;
int mod_add(int A, int B) { return (A + B) % MOD; }
int mod_sub(int A, int B) { return (A + MOD - B) % MOD; }
int mod_mul(int A, int B) { return ((A % MOD) * (B % MOD)) % MOD; }
int mod_bipow(int X, int Y) {
  if (Y == 0) return 1;
  else if (Y == 1) return X % MOD;
  else if (Y % 2 == 0) {
    int Z = mod_bipow(X, (int)(Y / 2));
    return mod_mul(Z, Z);
  } else {
    int Z = mod_bipow(X, (int)(Y / 2));
    return mod_mul(mod_mul(Z, Z), X);
  }
}
int mod_inv(int X) { return mod_bipow(X, MOD - 2); }
int mod_div(int A, int B) { return mod_mul(A, mod_inv(B)); }

template <class T>
bool amin(T &A, T B) {
  if (A > B) {
    A = B;
    return true;
  }
  return false;
}
template <class T>
bool amax(T &A, T B) {
  if (A < B) {
    A = B;
    return true;
  }
  return false;
}

vi divisors(int N) {
  vi ret;
  for (int i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      ret.pb(i);
      if (i * i != N) ret.pb(N / i);
    }
  }
  SORT(ret);
  return ret;
}

map<int, int> prime_factors(int N) {
  map<int, int> ret;
  for (int i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      ret[i]++;
      N /= i;
    }
  }
  if (N != 1) ret[N]++;
  return ret;
}

int ceil_div(int X, int Y) { return (X - 1) / Y + 1; }

vi cum(vi V) {
  vi U(sz(V));
  partial_sum(all(V), begin(U));
  return U;
}

struct union_find {
  vi data;
  union_find(int size) : data(size, -1) {}
  bool union_set(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool find_set(int x, int y) { return root(x) == root(y); }
  int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  int size(int x) { return -data[root(x)]; }
};

struct vertex {
  vector<int> adj = vi(0);
};
#pragma endregion header

// MOD = 1e9 + 7;


void solve(int n, int x){
  vi c(n + 1);
  c[0] = 1;
  rep(i, n)c[i + 1] = c[i] * 2 + 3;
  int ans = 0;
  int l = n - 1, d = x;
  while(true){
    if(l == -1) {
      ans += min(1ll, max(0ll, d));
      break;
    }
    if(d >= c[l] + 1 && d <= c[l] + 3) {
      if(d >= c[l] + 2)ans++;
      if(l == 0 && d == c[l] + 3)ans++;
      ans += c[l] / 2 + 1;
      break;
    } else if(d > c[l] + 3) {
      ans += c[l] / 2 + 2;
      d -= c[l] + 2;
    } else {
      d--;
    }
    l--;
  }
  cout << ans << endl;
}


#pragma region main
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;
  int x;
  cin >> x;
  solve(n, x);
}
#pragma endregion main
