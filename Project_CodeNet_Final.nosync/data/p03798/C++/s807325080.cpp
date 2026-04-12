#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n;
string s;
vector<int> ans;

void display() {
  rep(i, 0, n) {
    if (ans[i] == 0)
      cout << "S";
    else
      cout << "W";
  }
  cout << endl;
}

bool check(int t, int bef, int aft) {
  if (ans[t] == 0) {
    if ((s[t] == 'o' && ans[aft] == ans[bef]) ||
        (s[t] == 'x' && ans[aft] != ans[bef]))
      return true;
  } else {
    if ((s[t] == 'x' && ans[aft] == ans[bef]) ||
        (s[t] == 'o' && ans[aft] != ans[bef])) {
      return true;
    }
  }

  return false;
}

bool sol(int target, int bef_target) {
  ans[0] = target;
  ans[n - 1] = bef_target;
  int bef = n - 1;
  rep(i, 0, n - 2) {
    if ((s[i] == 'o' && ans[i] == 0) || (s[i] == 'x' && ans[i] == 1)) {
      ans[i + 1] = ans[bef];
    } else {
      ans[i + 1] = !ans[bef];
    }
    bef = i;
  }

  if (check(n - 1, n - 2, 0) && check(n - 2, n - 3, n - 1)) {
    display();
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;

  ans.resize(n, -1);
  if (sol(0, 0))
    return 0;
  if (sol(0, 1))
    return 0;
  if (sol(1, 0))
    return 0;
  if (sol(1, 1))
    return 0;
  cout << "-1" << endl;
}
