#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define ALL(a) begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)
#define SORT(a) stable_sort(ALL(a))
#define RSORT(a) stable_sort(RALL(a))
#define REV(a) reverse(ALL(a))
#define UNIQUE(a) a.erase(unique(ALL(a)), end(a))
#define lambda(i) [=](auto i)
#define compare(i, j) [=](auto i, auto j)
#define min_of(a) *min_element(ALL(a))
#define max_of(a) *max_element(ALL(a))
#define sum(a) accumulate(ALL(a), 0)
#define count_of(a, i) count(ALL(a), i)
#define lower(a, i) (int)(lower_bound(ALL(a), i) - begin(a))
#define upper(a, i) (int)(upper_bound(ALL(a), i) - begin(a))
#define binary(a, i) binary_search(ALL(a), i)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define sz(a) (int)(a).size()
#define REP(i, n) for (decltype(+n) i = 0; i < (n); i++)
#define RREP(i, n) for (auto i = n - 1; i != static_cast<decltype(i)>(-1); i--)
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (auto i = b - 1; i >= a; i--)
#define EACH(i, a) for (auto&& i: (a))
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

int ceil_div(int X, int Y) {
  return (X - 1) / Y + 1;
}

struct vertex {
  vector<int> adj = vi(0);
};

struct union_find {
  vi data;
  union_find(int size) : data(size, -1) { }
  bool union_set(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find_set(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

vi cum(vi V) {
  vi U(sz(V));
  partial_sum(ALL(V), begin(U));
  return U;
}

void solve() {
  int a, b, c, x, y;
  int ans = 0;
  cin >> a >> b >> c >> x >> y;
  int mxy = min(x, y);
  if (a + b > c * 2) {
    ans += mxy * c * 2;
  } else {
    ans += mxy * (a + b);
  }
  x -= mxy;
  y -= mxy;
  if(x > 0) {
    ans += x * min(a, c * 2);
  } else {
    ans += y * min(b, c * 2);
  }

  cout << ans << endl;
  // REP(i, n) {
  //   cout << a[i];
  // }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(15);
  solve();
}
