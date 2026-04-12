// https://atcoder.jp/contests/abc164/tasks/abc164_f

#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 1
#if DEBUG
  #define _GLIBCXX_DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int N_MAX = 500;
const int ALL_0 = 0;
const int ALL_1 = 1;
const int HAS_0 = 2;
const int HAS_1 = 3;

int N;
vector<int> S;
vector<int> T;
vector<ull> U;
vector<ull> V;

int line_pat(int s, ull u, int k) {
  ull f = u >> k & 1;
  if (s == 0) {
    return f ? ALL_1 : HAS_0;
  } else {
    return f ? HAS_1 : ALL_0;
  }
}

int main() {
  cin >> N;
  S = vector<int>(N);
  REP(i, N) cin >> S[i];
  T = vector<int>(N);
  REP(i, N) cin >> T[i];
  U = vector<ull>(N);
  REP(i, N) cin >> U[i];
  V = vector<ull>(N);
  REP(i, N) cin >> V[i];

  vector<vector<ull>> a = vector<vector<ull>>(N, vector<ull>(N, 0ULL));
  REP (k, 64) {
    vector<int> rp = vector<int>(N);
    REP(i, N) rp[i] = line_pat(S[i], U[i], k);
    vector<int> cp = vector<int>(N);
    REP(i, N) cp[i] = line_pat(T[i], V[i], k);

    vector<int> r1 = vector<int>(N, 0);
    vector<int> c1 = vector<int>(N, 0);

    REP(i, N) REP(j, N) {
      if (rp[i] == ALL_1 && cp[j] == ALL_0) {
        // cout << "rp[" << i << "]=ALL_1, cp[" << j << "] == ALL_0" << endl;
        cout << "-1" << endl;
        return 0;
      }
      if (rp[i] == ALL_0 && cp[j] == ALL_1) {
        // cout << "rp[" << i << "]=ALL_0, cp[" << j << "] == ALL_1" << endl;
        cout << "-1" << endl;
        return 0;
      }

      if (rp[i] == ALL_1 || cp[j] == ALL_1) {
        a[i][j] |= 1ULL << k;
        r1[i]++; c1[j]++;
      } else if (rp[i] == HAS_1 && cp[j] == HAS_1) {
        a[i][j] |= 1ULL << k;
        r1[i]++; c1[j]++;
      }
    }

    int j = 0;
    REP(i, N) {
      if (rp[i] == HAS_0 && r1[i] == N) {
        cout << "-1" << endl;
        return 0;
      }
      if (!(rp[i] == HAS_1 && r1[i] == 0)) continue;
      while(j < N && !(cp[j] == HAS_0 && N - c1[j] > 1)) j++;
      if (j >= N) {
        cout << "-1" << endl;
        return 0;
      }
      a[i][j] |= 1ULL << k;
      r1[i]++; c1[j]++;
    }

    int i = 0;
    REP(j, N) {
      if (cp[j] == HAS_0 && c1[j] == N) {
        cout << "-1" << endl;
        return 0;
      }
      if (!(cp[j] == HAS_1 && c1[j] == 0)) continue;
      while(i < N && !(rp[i] == HAS_0 && N - r1[i] > 1)) i++;
      if (i >= N) {
        cout << "-1" << endl;
        return 0;
      }
      a[i][j] |= 1ULL << k;
      r1[i]++; c1[j]++;
    }
  }

  REP(i, N) REP(j, N) {
    cout << a[i][j];
    if (j == N - 1) cout << endl;
    else cout << " ";
  }
}
