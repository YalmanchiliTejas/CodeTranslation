#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = INT_MAX / 2;

int main() {
  int N; cin >> N;
  vector<int> A(N); cin >> A;
  // A (入力の数列)
  // => P (差の合計が最大になるように A を並び替えた数列)
  // D_i = P_{i + 1} - P_i
  // Σ D1_i = (P_1 - P_0) + (P_2 - P_1) + (P_3 - P_2) + (P_4 - P_3) + ... + (P_{N - 1} - P_{N - 2})
  // Σ D2_i = (P_0 - P_1) + (P_1 - P_2) + (P_2 - P_3) + (P_3 - P_4) + ... + (P_{N - 2} - P_{N - 1})
  // S1 = (P_1 - P_0) + (P_1 - P_2) + (P_3 - P_2) + (P_3 - P_4) + ...
  //    = 2 * (P_1 + P_3 + ...) - 2 * (P_2 + P_4 + ...) - P_0 + P_N

  // 1 2 3 6 8
  // 2 6 1 8 3
  //  4+5+7+5 = 21
  // S = (P_1 - P_0) + (P_1 - P_2) + (P_3 - P_2) + (P_3 - P_4)
  //   = 2 * (P_1 + P_3) - 2 * P_2 - P_0 - P_4
  //   = 2 * (8 + 6) - 2 * 1 - 2 - 3 = 28 - 7 = 21

  // 1 1 3 4 5 9
  // 
  // S = (P_1 - P_0) + (P_1 - P_2) + (P_3 - P_2) + (P_3 - P_4) + (P_5 - P_4)
  //   = 2 * (P_1 + P_3) - 2 * (P_2 + P_4) - P_0 + P_5
  //   = 2 * (5 + 9) - 2 * (1 + 1) - 3 + 4
  //   = 28 - 4 - 3 + 4
  //   = 25

  // 1 5 5
  // 5 1 5
  //  4+4 = 8
  // S1 = (P_1 - P_0) + (P_1 - P_2)
  //    = 2 * P_1 - P_0 - P_2
  //    = 2 * 5 - 5 - 1
  //    = 10 - 6 = 4
  // S2 = (P_0 - P_1) + (P_2 - P_1)
  //    = -2 * P_1 + P_0 + P_2
  //    = -2 * 1 + 5 + 5
  //    = 8

  sort(A.begin(), A.end());
  auto size = (N - 2) / 2;
  auto a1 = [&](){
    ll cand = 0;
    REP(i, (N - size - (N % 2)), N) {
      cand += 2 * A[i];
    }
    rep(i, size) {
      cand -= 2 * A[i];
    }
    cand += -A[size] + (N % 2 ? -1 : 1) * A[size + 1];
    return cand;
  }();
  auto a2 = [&](){
    ll cand = 0;
    REP(i, N - size, N) {
      cand += 2 * A[i];
    }
    rep(i, (size + N % 2)) {
      cand -= 2 * A[i];
    }
    cand += A[size + N % 2] + (N % 2 ? 1 : -1) * A[size + N % 2 + 1];
    return cand;
  }();

  cout << max(a1, a2) << endl;
}
