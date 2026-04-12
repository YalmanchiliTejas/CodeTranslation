#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int A[200000];
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  deque<int> deq;
  bool reversed = false;
  rep(i, N) {
    int a;
    cin >> a;
    if (reversed) deq.push_front(a);
    else deq.push_back(a);
    reversed ^= true;
  }
  if (reversed) {
    rep(i, N) {
      cout << deq.back() << " ";
      deq.pop_back();
    }
  }
  else {
    rep(i, N) {
      cout << deq.front() << " ";
      deq.pop_front();
    }
  }
  cout << "\n";
  return 0;
}
