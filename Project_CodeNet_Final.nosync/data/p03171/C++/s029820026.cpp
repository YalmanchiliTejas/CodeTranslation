#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i, N) for (int i = 0; i < (int)N; i++)
#define FORIN(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define MOD 1000000007
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

using Pi = pair<int, int>;
using ll = long long;
const int INF = 1 << 28;

string to_string(string s) {
  return s;
}

template <class T>
string to_string(vector<T> v) {
  string ret = "{";
  for (int i = 0; i < v.size() - 1; ++i) {
    ret += to_string(v[i]) + ",";
  }
  if (v.size() > 0) {
    ret += to_string(v.back());
  }
  ret += "}";
  return ret;
}

void debug() {
  cerr << endl;
}

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head head, Tail... tail) {
  cout << to_string(head);
  print(tail...);
}

void get() {}

template <class Head, class... Tail>
void get(Head& head, Tail&... tail) {
  cin >> head;
  get(tail...);
}

template <class T>
void getv(vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i)
    cin >> vec[i];
}

ll a[3000];
ll memo[3000][3000][2];

inline ll search(int l, int r, int turn) {
  if (memo[l][r][(turn + 1) / 2] == -1LL << 60) {
    if (l == r) {
      if (turn > 0) {
        memo[l][r][1] = a[l];
      } else {
        memo[l][r][0] = -a[l];
      }
    } else {
      if (turn > 0) {
        memo[l][r][1] = max(search(l + 1, r, turn * -1) + a[l] * turn,
                            search(l, r - 1, turn * -1) + a[r] * turn);
      } else {
        memo[l][r][0] = min(search(l + 1, r, turn * -1) + a[l] * turn,
                            search(l, r - 1, turn * -1) + a[r] * turn);
      }
    }
  }
  return memo[l][r][(turn + 1) / 2];
}

int main() {
  int N;
  cin >> N;
  FOR(i, N) cin >> a[i];
  FOR(i, N) FOR(j, N) FOR(c, 2) memo[i][j][c] = -1LL << 60;
  print(search(0, N - 1, 1));
  return 0;
}