#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
  int paSize = printArray.size();
  for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
  if (between != '\n') {cerr << endl;}
}

// ------------------------------------------------------------------------------------------

int Len[55], Pat[55];

int rec(int level, int layer) {
  if (level == 0) {
    return 1;
  }

  if (layer <= 1) { // 1
    return 0;
  } else if (layer <= Len[level-1] + 1) { // 2
    return rec(level-1, layer-1);
  } else if (layer <= Len[level-1] + 2) { // 3
    return Pat[level-1] + 1;
  } else if (layer <= 2*Len[level-1] + 2) { // 4
    return Pat[level-1] + 1 + rec(level-1, layer - Len[level-1] - 2);
  } else { // 5
    return  2*Pat[level-1] + 1;
  }
}

signed main() {
  int N, X;
  cin >> N >> X;

  Len[0] = Pat[0] = 1;
  for (int i = 1; i <= N; i++) {
    Len[i] = Len[i-1] * 2 + 3;
    Pat[i] = Pat[i-1] * 2 + 1;
  }

  cout << rec(N, X) << endl;

  return 0;
}