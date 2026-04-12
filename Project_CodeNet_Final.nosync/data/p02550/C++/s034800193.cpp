#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x, m;
  cin >> n >> x >> m;
  vector<long long> memo(m, 0);
  
  long long ans = 0;
  long long cur = x;
  long long first, last;
  bool en = false;
  for (long long i = 0; i < n; i++) {
    if (memo[cur] > 0) {
      first = memo[cur];
      last = i;
      //cout << "f:" << first << "l:" << last << endl;
      en = true;
      break;
    } else {
      memo[cur] = i;
    }
    ans += cur;
    cur = cur * cur % m;
    //cout << i << " cur:" << cur << " ans:" << ans << endl;
  }
  if (!en) {
    cout << ans << endl;
    return 0;
  }
  long long ans_f = 0, ans_m = 0, ans_l = 0;
  cur = x;
  for (long long i = 0; i < first; i++) {
    ans_f += cur;
    cur = cur*cur % m;
  }
  //cout << "m- cur: " << cur << endl;
  for (long long i = first; i < last; i++) {
    ans_m += cur;
    cur = cur*cur % m;
  }
  long long num = (n - first) / (last - first);
  long long last_s = first + num*(last-first);
  //cout << "num" << num <<"l-ls: " << last_s << " cur: " << cur << endl;
  for (long long i = last_s; i < n; i++) {
    ans_l += cur;
    cur = cur*cur % m;
  }
  cout << (ans_f + ans_m*num + ans_l) << endl;
}