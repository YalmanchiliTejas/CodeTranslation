#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

int main () {
  cin.tie(0);
  cout << fixed << setprecision(10);

  int n, m, k; cin >> n >> m >> k;
  vector<int> d(m);
  map<int, int> mp;
  for(int i=0;i<m;++i) {
    cin >> d[i];
    d[i]--;
    mp[d[i]] = i + 1;
  }

  vector<vector<int>> v(n, vector<int>(k, 0));
  for(int i=0;i<n;++i) {
    for(int j=0;j<k;++j) {
      cin >> v[i][j];
      v[i][j]--;
    }
  }

  vector<int> dp(1<<m, INF);
  dp[(1<<m) - 1] = 0;
  queue<int> que;
  que.push((1<<m)-1);
  while(!que.empty()) {
    for(int i=0;i<k;++i) {
      int now = que.front(), next = 0;
      for(int j=0;j<m;++j) {
        if(now & 1) {
          if(mp[v[d[j]][i]]) {
            next |= (1 << (mp[v[d[j]][i]] - 1));
          }
        }
        now >>= 1;
      }
      if(dp[next] == INF) {
        que.push(next);
      }
      dp[next] = min(dp[next], dp[que.front()] + 1);
    }
    que.pop();
  }
  cout << dp[0] << endl;
}

