#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cout << #x << ": " << x << ", "
#define debugln(x) cout << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  deque<int> que;
  rep(i, n) {
    int a; cin >> a;
    que.push_back(a);
  }
  sort(que.begin(), que.end());

  deque<int> que2 = que;

  int before = -1;
  long ans1 = 0;
  int first;
  rep(i, n) {
    int now;
    if (i%2 == 0) {
      now = que.front(); que.pop_front();
    } else {
      now = que.back(); que.pop_back();
    }
    if (i == 0) {
      first = now;
    } else if (i < n-1) {
      ans1 += abs(now - before);
    } else {
      ans1 += max(abs(now-before), abs(now-first));
    }
    before = now;
  }

  before = -1;
  long ans2 = 0;
  rep(i, n) {
    int now;
    if (i%2 != 0) {
      now = que2.front(); que2.pop_front();
    } else {
      now = que2.back(); que2.pop_back();
    }
    if (i == 0) {
      first = now;
    } else if (i < n-1) {
      ans2 += abs(now - before);
    } else {
      ans2 += max(abs(now-before), abs(now-first));
    }
    before = now;
  }
  cout << max(ans1, ans2) << endl;
}