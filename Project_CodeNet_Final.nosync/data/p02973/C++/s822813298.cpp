#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int n;
  cin >> n;
  deque<int> que;
  rep(i, n) {
    int a;
    cin >> a;
    int index = lower_bound(que.begin(), que.end(), a) - que.begin();
    if (index == 0) que.push_front(a);
    else que[index-1] = a;
  }
  int ans = que.size();
  cout << ans << '\n';
  return 0;
}