#include <bits/stdc++.h>

const int MOD = 1000000007;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define copy(from, to) copy(from.begin(), from.end(), back_inserter(to))
#define _sort(a) sort(a.begin(), a.end())
#define _sortd(a) sort(a.rbegin(), a.rend())
#define reverse(s) reverse(s.begin(), s.end())
#define p(s) cout << (s) << endl

typedef long long ll;
using namespace std;

template<class T>
void load(vector<T> &v, int n) {
  for (int i = 0; i < n; ++i) {
    T t;
    cin >> t;
    v.push_back(t);
  }
}

template<class T>
T max(vector<T> &v) {
  return *max_element(v.begin(), v.end());
}

template<class T>
T min(vector<T> &v) {
  return *min_element(v.begin(), v.end());
}

void py(bool isUpper = false) {
  if (isUpper) {
    p("YES");
  } else {
    p("Yes");
  }
}

void pn(bool isUpper = false) {
  if (isUpper) {
    p("NO");
  } else {
    p("No");
  }
}

int main() {
  int h, w;
  cin >> h >> w;

  char board[101][101];
  bool mark_x[101] = {false};
  bool mark_y[101] = {false};
  rep(i, h) {
    rep(j, w) {
      char c;
      cin >> c;
      board[i][j] = c;
      if (c == '#') {
        mark_x[i] = true;
        mark_y[j] = true;
      }
    }
  }

  rep(i, h) {
    if (!mark_x[i]) continue;
    rep(j, w) {
      if (!mark_y[j]) continue;
      cout << board[i][j];
    }
    cout << endl;
  }

  rep(i, h) {
    rep(j, w) {
      if (board[i][j] == '#') {

      }
    }
  }
}