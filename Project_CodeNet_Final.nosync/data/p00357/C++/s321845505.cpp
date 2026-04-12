#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()
struct revran {
  const i64 b, e;
  struct iter {
    i64 i;
    constexpr iter(const i64 i) noexcept: i(i) {}
    void operator++() noexcept { --i; }
    constexpr i64 operator*() const noexcept { return i; }
    constexpr bool operator!=(const iter x) const noexcept { return i != x.i; }
  };
  constexpr revran(const i64 e) noexcept: b(0), e(e) {}
  constexpr revran(const i64 b, const i64 e) noexcept: b(b), e(e) {}
  constexpr iter begin() const noexcept { return iter(e - 1); }
  constexpr iter end() const noexcept { return iter(b - 1); }
};

struct ran {
  const i64 b, e;
  struct iter {
    i64 i;
    constexpr iter(const i64 i) noexcept: i(i) {}
    void operator++() noexcept { ++i; }
    constexpr i64 operator*() const noexcept { return i; }
    constexpr bool operator!=(const iter x) const noexcept { return i != x.i; }
  };
  constexpr ran(const i64 e) noexcept: b(0), e(e) {}
  constexpr ran(const i64 b, const i64 e) noexcept: b(b), e(e) {}
  constexpr iter begin() const noexcept { return iter(b); }
  constexpr iter end() const noexcept { return iter(e); }
  constexpr revran rev() const noexcept { return revran(b, e); }
};

constexpr ran rin(const i64 e) noexcept { return ran(1, e + 1); }
constexpr ran rin(const i64 b, const i64 e) noexcept { return ran(b, e + 1); }

int main() {
  i64 N;
  cin >> N;
  vector<i64> d(N), rd(N);
  for(auto& x: d) cin >> x;
  auto check = [](vector<i64>& R) {
    i64 MAX = 0;
    for(int i = 0;i < R.size();i++) {
      if(MAX < i * 10) {
        return false;
      }
      MAX = max(MAX, R[i] + i * 10);
    }
    return true;
  };
  bool A = check(d);
  reverse(all(d));
  bool B = check(d);
  if(A & B) {
    cout << "yes" << endl;
  }
  else {
    cout << "no" << endl;
  }
}

