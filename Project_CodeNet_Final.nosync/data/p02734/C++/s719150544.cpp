class range { // Range Iterator
  struct _Impl {
    int it;const bool rev;
    explicit constexpr _Impl(int it_, bool rev=false):it(it_), rev(rev) {}
    int operator*() { return it; }
    bool operator!=(_Impl& r) { return it!=r.it; }
    void operator++() { rev?--it:++it; }
  };
  const _Impl i,n;
public:
  explicit constexpr range(int n): i(0), n(n<0?0:n) {}
  explicit constexpr range(int i, int n): i(i,n<i), n(n) {}
  const _Impl& begin() { return i; }
  const _Impl& end() { return n; }
};

#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using usize = uint64_t;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    const i64 M = 998244353;
    i64 n, s;
    cin >> n >> s;
    auto a = vector<i64>(n, 0);
    for (usize i: range(n)) {
        cin >> a[i];
    }
    auto dp = vector<vector<i64>>(s + 1, vector<i64>(3));
    dp[0][0] = 1;
    for (usize i: range(n)) {
        auto dp_next = dp;
        for (usize j: range(s + 1)) {
            dp_next[j][1] += dp[j][0];
            dp_next[j][1] %= M;
            dp_next[j][2] += dp[j][0] + dp[j][1];
            dp_next[j][2] %= M;
            if (static_cast<i64>(j) + a[i] <= s) {
                dp_next[j + a[i]][1] += (dp[j][0] + dp[j][1]);
                dp_next[j + a[i]][1] %= M;
                dp_next[j + a[i]][2] += (dp[j][0] + dp[j][1]);
                dp_next[j + a[i]][2] %= M;
            }
        }
        dp = dp_next;
    }
    cout << dp[s][2] << endl;
    return 0;
}
