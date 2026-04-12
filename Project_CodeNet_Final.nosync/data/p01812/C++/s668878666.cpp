#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T> void operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) cin >> e; }

typedef long long ll;
int const inf = 1<<29;

int main() {

  int N, M, K; cin >> N >> M >> K;

  map<int, int> mp, mprev;
  int darkcnt = 0;

  rep(i, M) {
    int d; cin >> d; d--;
    mp[d] = darkcnt;
    mprev[darkcnt++] = d;
  }

  vector<vector<int>> G(N);

  rep(i, N) {
    rep(k, K) {
      int to; cin >> to; to--;
      G[i].push_back(to);
    }
  }

  int dp[1 << M];
  rep(i, 1 << M) dp[i] = inf;

  dp[(1 << M) - 1] = 0;
  queue<int> q;
  q.push((1 << M) - 1);

  while(!q.empty()) {
    auto const S = q.front(); q.pop();
    rep(to_dir, K) {
      auto T = S;
      auto TAdd = 0;
      rep(from, M) {
        if(T >> from & 1) {
          T &= ~(1 << from);
          auto to = G[mprev[from]][to_dir];
          if(mp.find(to) != mp.end()) {
            TAdd |= 1 << mp[to];
          }
        }
      }
      T |= TAdd;
      if(dp[T] > dp[S] + 1) {
        dp[T] = dp[S] + 1;
        q.push(T);
      }
    }
  }

  cout << dp[0] << endl;
  
  return 0;
}