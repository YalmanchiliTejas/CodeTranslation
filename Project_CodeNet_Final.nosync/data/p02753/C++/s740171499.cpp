#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define EACH(i, a) for (auto &&i : a)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define RFOR(i, a, b) for (int i = (int)b - 1; i >= (int)a; --i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FOR(i, 1, int(n) + 1)
#define RREP(i, n) RFOR(i, 0, n)
#define RREPS(i, n) RFOR(i, 1, int(n) + 1)
#define ALL(x) (x).begin(), (x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define debug(x) cout << #x << ": " << x << endl

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define INF (1L << 30)
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <class T>
void pv(T a, T b) {
  for (T i = a; i != b; ++i) cout << *i << " ";
  cout << endl;
}
template <class T>
void pvp(T a, T b) {
  for (T i = a; i != b; ++i)
    cout << "(" << i->first << ", " << i->second << ") ";
  cout << endl;
}
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int in() {
  int x;
  scanf("%d", &x);
  return x;
}

using ll = long long;
#define int ll

//**********

signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string n;
  cin >> n;
  if (n == "AAA" | n== "BBB"){
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  // cout << pow(n, 2) << endl;

  return 0;
};
