#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define int long long
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
template<typename T> void cmax(T &a, T b) { a = max(a, b); }
template<typename T> void cmin(T &a, T b) { a = min(a, b); }

signed main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a));
  deque<int> b;
  b.push_back(a.back());
  b.push_front(a[0]);

  int turn = 0;
  int high = n - 2;
  int low = 1;
  int num = 2;

  while (num < n - 1) {
    int f = turn % 4;
    if (f == 0) {
      b.push_back(a[low]);
      low++;
    } else if (f == 1) {
      b.push_front(a[high]);
      high--;
    } else if (f == 2) {
      b.push_back(a[high]);
      high--;
    } else {
      b.push_front(a[low]);
      low++;
    }
    turn++;
    num++;
  }

  int ans = 0;
  for (auto itr = b.begin(); itr < b.end() - 1; itr++) {
    // cout << *itr << ' ' << *(itr + 1) << endl;
    ans += abs(*itr - *(itr + 1));
  }
  if (3 <= n) {
    int left = abs(b.front() - a[low]);
    int right = abs(b.back() - a[low]);
    ans += max(left, right);
  }

  turn = 0;
  high = n - 2;
  low = 1;
  num = 2;

  deque<int> c;
  c.push_back(a[0]);
  c.push_front(a.back());

  while (num < n - 1) {
    int f = turn % 4;
    if (f == 0) {
      b.push_back(a[high]);
      high--;
    } else if (f == 1) {
      b.push_front(a[low]);
      low++;
    } else if (f == 2) {
      b.push_back(a[low]);
      low++;
    } else {
      b.push_front(a[high]);
      high--;
    }
    turn++;
    num++;
  }
  int sum = 0;
  for (auto itr = c.begin(); itr < c.end() - 1; itr++) {
    // cout << *itr << ' ' << *(itr + 1) << endl;
    sum += abs(*itr - *(itr + 1));
  }
  if (3 <= n) {
    int left = abs(c.front() - a[low]);
    int right = abs(c.back() - a[low]);
    sum += max(left, right);
  }

  cout << max(ans, sum) << endl;
  return 0;
}
