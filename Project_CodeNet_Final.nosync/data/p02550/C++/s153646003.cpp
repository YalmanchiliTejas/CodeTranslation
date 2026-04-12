#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))

#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed

bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }

ll solve(ll N, ll X, ll M) {
  vector<ll> a_vec{0, X};

  ll a_i = X;
  ll i = 1;
  ll loop_l_i = 1;
  vector<ll> a_sum_vec{0, X};

  while (i < N) {
    a_i = (a_i * a_i) % M;
    auto itr_found = find(a_vec.begin() + 1, a_vec.end(), a_i);

    if (itr_found != a_vec.end()) {
      loop_l_i = distance(a_vec.begin(), itr_found);
      break;
    }

    a_vec.push_back(a_i);
    a_sum_vec.push_back(a_sum_vec.back() + a_i);
    i++;
  }

  ll loop_sum = a_sum_vec.back() - a_sum_vec[loop_l_i - 1];
  ll loop_count = (N - loop_l_i + 1) / (i - loop_l_i + 1);
  ll single_r_i = loop_l_i - 1 + (N - loop_l_i + 1) % (i - loop_l_i + 1);
  ll ans = loop_sum * loop_count + a_sum_vec[single_r_i];
  return ans;
}

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, X, M;
  cin >> N >> X >> M;

  // main procedure
  ll ans = solve(N, X, M);

  // output
  cout << ans << endl;

  return 0;
}