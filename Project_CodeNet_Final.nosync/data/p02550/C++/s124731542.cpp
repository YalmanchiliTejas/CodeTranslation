#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, x, m;
  cin >> n >> x >> m;

  ll cur = x % m, cnt = 0, sum = x % m, loop_offset = -1;
  bool has_loop = false;
  vector<int> loop, loop_offsets(m + 1, -1);
  while (cur > 1 && cnt < n - 1) {
    cur = (cur * cur) % m;
    if (loop_offsets[cur] > -1) {
      has_loop = true;
      loop_offset = loop_offsets[cur];
      break;
    }

    loop_offsets[cur] = loop.size();
    loop.push_back(cur);
    sum += cur;
    cnt++;
  }

  vector<ll> loop_csum{0};
  for (int i = loop_offset; i < loop.size(); ++i) {
    loop_csum.push_back(loop_csum.back() + loop[i]);
  }

  ll remain = n - cnt - 1;
  if (!has_loop) {
    sum += remain * cur;
  } else {
    ll loop_sz = loop_csum.size() - 1;
    sum += (remain / loop_sz) * loop_csum.back();
    sum += loop_csum[remain % loop_sz];
  }

  cout << sum << '\n';

  return 0;
}