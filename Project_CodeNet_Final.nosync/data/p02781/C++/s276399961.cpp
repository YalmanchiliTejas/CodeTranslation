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

string S;
int K;
ll dp[101][4][2];

ll rec(int idx, int k, bool upmost) {
  ll& ret = dp[idx][k][upmost];

  if (ret >= 0) return ret;
  if (idx == S.size()) { return k == 0; }

  ret = 0;

  if (upmost) {
    if (idx > 0) {
      ret += rec(idx + 1, k, S[idx] == 0);
    }
    else {
      ret += rec(idx + 1, k, 0);
    }
    if (k) {
      REP(d, 1, S[idx] + 1) {
        ret += rec(idx + 1, k - 1, S[idx] == d);
      }
    }
  }
  else {
    ret += rec(idx + 1, k, 0);
    if (k) {
      REP(d, 1, 10) {
        ret += rec(idx + 1, k - 1, 0);
      }
    }
  }

  return ret;
}

int main() {
  cin >> S >> K;
  rep(i, S.size()) S[i] -= '0';
  rep(i, 101) rep(j, 4) rep(k, 2) dp[i][j][k] = -1;
  cout << rec(0, K, 1) << "\n";
}
