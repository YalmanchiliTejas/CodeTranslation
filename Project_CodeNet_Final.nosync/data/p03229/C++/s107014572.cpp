#include <bits/stdc++.h>

using namespace std;

uint64_t eval(const vector<int64_t>& in) {
  deque<int64_t> arr;
  int l = 0, r = in.size() - 1;
  arr.push_back(in[l++]);
  while (l <= r) {
    if (((arr.size() + 1)/ 2) % 2 == 1) {
      if (arr.size() % 2 == 0) {
        arr.push_back(in[r--]);
      } else {
        arr.push_front(in[r--]);
      }
    } else {
      if (arr.size() % 2 == 0) {
        arr.push_back(in[l++]);
      } else {
        arr.push_front(in[l++]);
      }
    }
  }

  uint64_t ans = 0;
  for (size_t i = 1; i < arr.size(); ++i) {
    ans += abs(arr[i] - arr[i - 1]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  uint64_t ans1 = eval(a);
  reverse(a.begin(), a.end());
  uint64_t ans2 = eval(a);
  cout << max(ans1, ans2) << "\n";
}
