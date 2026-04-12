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

ll level[55];

ll F(int N) {
  auto& ret = level[N];
  if (ret) return ret;
  if (N == 0) return ret = 1;
  return ret = F(N - 1) * 2 + 3;
}

ll dfs(int N, ll X) {
  if (N == 0) {
    assert(X == 1);
    return 1;
  }
  if (X == 1) {
    return 0;
  }

  auto cnt_N_1 = F(N - 1);
  if (X <= cnt_N_1 + 1) {
    return dfs(N - 1, X - 1);
  }
  else if (X == 2 + cnt_N_1) {
    return dfs(N - 1, cnt_N_1) + 1;
  }
  else if (X <= 2 + 2 * cnt_N_1) {
    return dfs(N - 1, cnt_N_1) + dfs(N - 1, X - 2 - cnt_N_1) + 1;
  }

  return dfs(N - 1, cnt_N_1) * 2 + 1;
}

int main() {
  /*
    5 .. B
    4 .. (N - 1)
    3 .. P
    2 .. (N - 1)
    1 .. B

    X層目が 1 ~ 5 のどのブロックにあるかを決める。
    これを N 回繰り返して、...
  */
  int N; ll X; cin >> N >> X;
  cout << dfs(N, X) << "\n";
}
