#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  deque<ll> q;
  for (auto e : A) {
    q.push_back(e);
  }
  ll ans = 0;
  ll right = q.front();
  ll left = right;
  q.pop_front();
  while (!q.empty()) {
    ll back = q.back();
    ll front = q.front();
    ll cand1 = abs(right - back);
    ll cand2 = abs(right - front);
    ll cand3 = abs(left - back);
    ll cand4 = abs(left - front);
    ll maximum_abs = max({cand1, cand2, cand3, cand4});
    ans += maximum_abs;
    if (maximum_abs == cand1) {
      right = back;
      q.pop_back();
    } else if (maximum_abs == cand2) {
      right = front;
      q.pop_front();
    } else if (maximum_abs == cand3) {
      left = back;
      q.pop_back();
    } else if (maximum_abs == cand4) {
      left = front;
      q.pop_front();
    }
  }
  cout << ans << endl;
  return 0;
}