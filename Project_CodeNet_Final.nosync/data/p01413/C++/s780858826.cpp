#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i=(k);i<int(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
constexpr int INF = 1000000000;

int main() {
  int n,m,w,t;
  cin>>n>>m>>w>>t;
  map<string, pair<int,int>> mp;
  REP(i,m) {
    string s;
    int v,p;
    cin>>s>>v>>p;
    mp[s] = make_pair(v,p);
  }
  vector<tuple<int,int,int>> vt;
  vector<vector<pair<string,int>>> vr(n);
  REP(i,n) {
    int l,x,y;
    cin>>l>>x>>y;
    vt.emplace_back(l,x,y);
    REP(j,l) {
      string r;
      int q;
      cin>>r>>q;
      vr[i].emplace_back(r,mp[r].second-q);
    }
  }
  vector<vector<int>> d(n+1, vector<int>(n+1));
  REP(i,n)REP(j,n) {
    int xi,xj,yi,yj;
    tie(ignore,xi,yi) = vt[i];
    tie(ignore,xj,yj) = vt[j];
    d[i][j] = abs(xi-xj) + abs(yi-yj);
  }
  REP(i,n) {
    int x,y;
    tie(ignore,x,y) = vt[i];
    d[i][n] = d[n][i] = abs(x) + abs(y);
  }
  vector<vector<int>> dist(1<<(n+1), vector<int>((n+1),INF));
  REP(i,n) dist[1<<i][i] = d[n][i];
  REP(i,1<<(n+1)) {
    REP(j,n+1) {
      if ((i>>j)&1) {
        REP(k,n+1) {
          if ((i>>k)&1) continue;
          dist[i|(1<<k)][k] = min(dist[i|(1<<k)][k], dist[i][j] + d[j][k]);
        }
      }
    }
  }
  vector<pair<int,int>> candi;
  REP(i,1<<n) {
    map<string, int> price;
    REP(j,n) {
      if ((i>>j)&1) {
        for (auto p : vr[j]) {
          string r;
          int q;
          tie(r, q) = p;
          if (price.count(r)) {
            price[r] = max(price[r], q);
          } else {
            price[r] = q;
          }
        }
      }
    }
    vector<int> dp(w+1);
    for (auto p : price) {
      string r;
      int q;
      tie(r, q) = p;
      int we = mp[r].first;
      REP(j,w+1-we) {
        dp[j+we] = max(dp[j+we], dp[j] + q);
      }
    }
    candi.emplace_back(dist[i|(1<<n)][n], dp[w]);
  }
  vector<int64_t> dp(t+1);
  for (auto p : candi) {
    int64_t tm, q;
    tie(tm, q) = p;
    REP(i,t+1-tm) {
      dp[i+tm] = max(dp[i+tm], dp[i] + q);
    }
  }
  cout << dp[t] << endl;
  return 0;
}