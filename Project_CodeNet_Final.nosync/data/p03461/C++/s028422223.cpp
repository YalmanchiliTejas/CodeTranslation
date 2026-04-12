#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)
#define ALL(v) (v).begin(), (v).end()
#define CLR(t, v) memset(t, (v), sizeof(t))
template <class T1, class T2>ostream &operator<<(ostream &os, const pair<T1, T2> &a){  return os << "(" << a.first << "," << a.second << ")";}
template <class T>void pv(T a, T b){  for (T i = a; i != b; ++i)    cout << (*i) << " ";  cout << endl;}
template <class T>void chmin(T &a, const T &b){  if (a > b)    a = b;}
template <class T>void chmax(T &a, const T &b){  if (a < b)    a = b;}

int nextInt(){  int x;  scanf("%d", &x);  return x;}

const int INF = 1000000;
const int K = 100;

int D[105][105];
int C[105][105];

struct E {
  int from, to, cost;
};

int main2() {
  int A = nextInt();
  int B = nextInt();
  REP(x, A) REP(y, B) D[x+1][y+1] = nextInt();

  REP(i, K+1) REP(j, K+1) {
    int c = 0;
    for (int x = 1; x <= A; x++) for (int y = 1; y <= B; y++) {
      chmax(c, D[x][y] - i*x - j*y);
    }
    C[i][j] = c;
  }

  bool possible = true;
  for (int x = 1; x <= A; x++) for (int y = 1; y <= B; y++) {
    int d = INF;
    REP(i, K+1) REP(j, K+1) {
      chmin(d, i*x + j*y + C[i][j]);
    }
    if (D[x][y] != d) possible = false;
  }

  if (possible) {
    vector<E> es;
    REP(i, K) es.push_back({i, i+1, -1});
    REP(j, K) es.push_back({299-j-1, 299-j, -2});
    REP(i, K) REP(j, K) {
      es.push_back({i, 299-j, C[i][j]});
    }
    cout << "Possible" << endl;
    cout << 300 << " " << es.size() << endl;
    for (auto e : es) {
      cout << (e.from+1) << " " << (e.to + 1) << " ";
      if      (e.cost == -1) cout << "X";
      else if (e.cost == -2) cout << "Y";
      else                   cout << e.cost;
      cout << endl;
    }
    cout << 1 << " " << 300 << endl;

  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}

int main() {
  for (; !cin.eof(); cin >> ws) main2();
  return 0;
}
