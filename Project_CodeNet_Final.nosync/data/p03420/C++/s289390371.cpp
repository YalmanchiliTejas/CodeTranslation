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
  int N, K; cin >> N >> K;
  ll sum = 0;
  // a = b * q + r

  // b = 0 ... NG
  // b = 1; r = 0
  // b = 2; r = 0, 1
  // ...

  // r >= K より, b >= K + 1
  // b = B; r = K, ..., B - 1
  //        a = B * q + r

  REP(b, K + 1, N + 1) {
    // r = K, ..., B - 1
    // q = 0, ..., N / b (各q に対して B - K 個の r が存在)
    // #a = #q * (B - K) + max(0, (N % B) - K + 1)
    // 但し、K = 0 の場合、b に対して q = 0, r = 0 のケースを取り除く
    sum += N / b * (b - K) + max(0, (N % b) - K + 1);
    if (K == 0) sum--;
  }
  cout << sum << "\n";
}
