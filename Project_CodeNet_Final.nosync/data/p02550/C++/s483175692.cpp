#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll N, X, M;

void solver_gcd0() {
  ll a = X;
  ll ans = 0;

  for (int i = 0; i < min(N, M); ++i) {
    a += ans;
    a = (a * a) % M;
  }

  cout << ans << endl;
}

void solver_gcd_non0() {
  vector<ll> values;

  ll sum = 0;
  ll a = X;
  bool looped = false;
  map<ll, int> checked;
  for (int i = 0; i < min(N, M); ++i) {
    if (checked[a] >= 1) {
      checked[a]++;
      looped = true;
      break;
    }
    checked[a]++;
    values.push_back(a);

    sum += a;
    a = (a * a) % M;

    if (a == 0) {
      cout << sum << endl;
      return;
    }
  }

  if (!looped) {
    cout << sum << endl;
    return;
  }

  ll head = 0;
  ll head_size = 0;
  ll loop_sum = 0;
  bool in_loop = false;
  vector<ll> loop_values;
  for (int i = 0; i < values.size(); ++i) {
    ll a = values[i];

    if (checked[a] >= 2) {
      in_loop = true;
    }

    if (in_loop) {
      loop_sum += a;
      loop_values.push_back(a);
    } else {
      head_size++;
      head += a;
    }
  }

  ll ans = head;
  ll loop_size = loop_values.size();
  ll loop_cnt = (N - head_size) / loop_size;
  ll remain = (N - head_size) % loop_size;
  fprintf(stderr, "%d: head: %lld, loop_size: %lld, loop_cnt: %lld, remain: %lld, sum: %lld\n",
      looped, head, loop_size, loop_cnt, remain, sum);

  if (loop_cnt == 0) {
    cout << sum << endl;
    return;
  }

  ans += loop_cnt * loop_sum;

  for (int i = 0; i < remain; ++i) {
    ans += loop_values[i];
  }

  cout << ans << endl;
}

int main() {
  cin >> N >> X >> M;

  ll g = gcd(X, M);

  if (g == 0) {
    solver_gcd0();
  } else {
    solver_gcd_non0();
  }

  return 0;
}
