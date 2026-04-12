#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, 0, N) cin >> A[i];
  vector<int> k(N, 2);
  rep(i, 2, N - 1) {
    k[i] = k[i-1] * -1;
  }
  k[0] = -1;
  if (N % 2)
    k[N-1] = -1;
  else
    k[N-1] = 1;

  sort_(A);
  sort_(k);
  ll ans1 = 0;
  rep(i, 0, N) {
    ans1 += A[i] * k[i];
  }
  rep(i, 0, N) {
    k[i] *= -1;
  }
  sort_(k);
  ll ans2 = 0;
  rep(i, 0, N) {
    ans2 += A[i] * k[i];
  }
  cout << max(ans1, ans2) << endl;
  return 0;
}
