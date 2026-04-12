#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n,x,m;
  cin >> n >> x >> m;

  vector<int> mod_last(m);
  vector<int> x_arr;
  x_arr.push_back(x);
  int idx = 1;
  int val = x;
  mod_last[x] = idx;
  while(true) {
    idx++;
    x = x * x;
    x %= m;
    if(mod_last[x] != 0) {
      val = x;
      break;
    }
    x_arr.push_back(x);
    mod_last[x] = idx;
  }

  int before = 0;
  int before_sum = 0;
  int N = (int)x_arr.size();
  for (int i = 0; i < N; i++) {
    if(x_arr[i] == val) {
      idx = i;
      break;
    }
    before_sum += x_arr[i];
    before++;
  }

  int loop = 0;
  int loop_sum = 0;
  for (int i = idx; i < N; i++) {
    loop_sum += x_arr[i];
    loop++;
  }

  int ans = 0;
  for (int i = 0; i < min(before,n); i++) {
    ans += x_arr[i];
  }
  n -= before;
  if(n > 0) {
    ans += loop_sum * (n/loop);
    for (int i = 0; i < (n%loop); i++) {
      ans += x_arr[idx + i];
    }
  }
  cout << ans << '\n';
}


