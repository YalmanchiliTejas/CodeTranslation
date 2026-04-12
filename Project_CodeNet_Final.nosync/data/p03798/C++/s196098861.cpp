#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

int N;
string s;
char t[1010101];

void init_t() {
  rep(i, 0, N) { t[i] = 0; }
}

void print_t() {
  rep(i, 0, N) { cout << t[i]; }
}

bool check_t() {
  if (s[N - 1] == 'o') {
    if (t[N - 1] == 'S') {
      if (t[N - 2] == t[0]) {
        return true;
      }
    } else {
      if (t[N - 2] != t[0]) {
        return true;
      }
    }
  } else {
    if (t[N - 1] == 'S') {
      if (t[N - 2] != t[0]) {
        return true;
      }
    } else {
      if (t[N - 2] == t[0]) {
        return true;
      }
    }
  }

  return false;
}

bool check_t_top() {
  if (s[0] == 'o') {
    if (t[0] == 'S') {
      if (t[N - 1] == t[1]) {
        return true;
      }
    } else {
      if (t[N - 1] != t[1]) {
        return true;
      }
    }
  } else {
    if (t[0] == 'S') {
      if (t[N - 1] != t[1]) {
        return true;
      }
    } else {
      if (t[N - 1] == t[1]) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  cin >> N;
  cin >> s;

  char tzero[] = {'S', 'S', 'W', 'W'};
  char tone[] = {'S', 'W', 'S', 'W'};

  rep(j, 0, 4) {
    init_t();
    t[0] = tzero[j];
    t[1] = tone[j];
    repe(i, 1, N - 2) {
      if (t[i] == 'S') {
        if (s[i] == 'o') {
          t[i + 1] = t[i - 1];
        } else {
          t[i + 1] = t[i - 1] == 'S' ? 'W' : 'S';
        }
      } else {
        if (s[i] == 'o') {
          t[i + 1] = t[i - 1] == 'S' ? 'W' : 'S';
        } else {
          t[i + 1] = t[i - 1];
        }
      }
    }
    if (check_t() && check_t_top()) {
      print_t();
      return 0;
    }
    // cout << j << " ";
    // rep(i, 0, N) { cout << t[i]; }
    // cout << endl;
  }

  cout << -1 << endl;
  return 0;
}
