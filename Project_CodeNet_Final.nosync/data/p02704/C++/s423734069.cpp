#include <iostream>
#include <vector>
#include <utility>

#define rep(i) for (int i = 0; i != n; i += 1)

using std::cin;
using std::cout;
using std::vector;
using std::swap;
using vi = vector<int>;

template<class T>
void transpose(int n, vector<vector<T>>& a) {
  rep(i) {
    for (int j = 0; j != i; j += 1) {
      swap(a[i][j], a[j][i]);
    }
  }
}

vector<vi> solve(int n, vi s, vi t, vi u, vi v) {
  vector<vi> a(n, vi(n, 0));
  rep(i) {
    rep(j) {
      if (s[i] == 1) {
        if (t[j] == 1) {
          if (u[i] != v[j]) {
            return a;
          }
        }
        else {
          if (u[i] == v[j]) {
            v[j] = 2;
          }
        }
        a[i][j] = u[i];
      }
      else {
        if (t[j] == 1) {
          if (u[i] == v[j]) {
            u[i] = 2;
          }
          a[i][j] = v[j];
        }
      }
    }
  }
  vi fs, ft;
  rep(i) {
    if (s[i] == 0) {
      fs.push_back(i);
    }
    if (t[i] == 0) {
      ft.push_back(i);
    }
  }
  bool td = false;
  if (fs.size() > ft.size()) {
    td = true;
    swap(s, t);
    swap(u, v);
    swap(fs, ft);
    transpose(n, a);
  }

  if (fs.size() == 1) {
    int i = fs[0];
    for (int j : ft) {
      if (v[j] == 2) {
        a[i][j] = u[i];
      }
      else {
        a[i][j] = v[j];
      }
    }
  }
  if (fs.size() >= 2) {
    int cs = 0;
    rep(i) {
      if (s[i] == 1) continue;
      int ct = 0;
      rep(j) {
        if (t[j] == 1) continue;
        a[i][j] = cs ^ ct;
        ct ^= 1;
      }
      cs ^= 1;
    }
  }

  if (td) {
    transpose(n, a);
  }
  return a;
}

int main() {
  using u64 = unsigned long long;

  int n;
  cin >> n;
  vi s(n), t(n);
  vector<u64> u(n), v(n);
  for (auto& e : s) cin >> e;
  for (auto& e : t) cin >> e;
  for (auto& e : u) cin >> e;
  for (auto& e : v) cin >> e;

  vector<vector<u64>> ans(n, vector<u64>(n, 0));
  for (int i = 0; i != 64; i += 1) {
    vi s_ = s, t_ = t;
    vi u_(n), v_(n);
    rep(j) {
      u_[j] = u[j] >> i & 1;
      v_[j] = v[j] >> i & 1;
      s_[j] ^= u_[j];
      t_[j] ^= v_[j];
    }
    auto ans_ = solve(n, s_, t_, u_, v_);
    rep(j) {
      rep(k) {
        ans[j][k] |= u64(ans_[j][k]&1) << i;
      }
    }
  }
  bool f = true;
  const auto ch = [&]() {
    rep(i) {
      if (s[i] == 0) {
        u64 a = ~u64(0);
        rep(j) {
          a &= ans[i][j];
        }
        f &= a == u[i];
      }
      else {
        u64 a = 0;
        rep(j) {
          a |= ans[i][j];
        }
        f &= a == u[i];
      }
    }
  };
  ch();
  transpose(n, ans);
  swap(s, t);
  swap(u, v);
  ch();
  transpose(n, ans);
  if (not f) {
    std::cout << "-1\n";
    return 0;
  }
  rep(i) {
    rep(j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
