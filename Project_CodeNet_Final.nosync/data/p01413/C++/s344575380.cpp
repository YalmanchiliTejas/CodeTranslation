#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

typedef long long lli;

const lli INF = 1LL<<60;
const int MAXN = 9;
const int MAXT = 10005;
const int MAXW = 10005;

int N, M, W, T;
map<string, pair<lli,lli> > item;
int X[MAXN], Y[MAXN];
vector<pair<string, lli> > citem[MAXN];

lli cost[1<<MAXN], adv[1<<MAXN], dp[MAXT];

inline lli dist(lli x1, lli y1, lli x2, lli y2) {
  return labs(x2-x1) + labs(y2-y1);
}

int main() {
  while(cin >> N >> M >> W >> T) {
    item.clear();
    for(int i = 0; i < MAXN; ++i) citem[i].clear();

    for(int i = 0; i < M; ++i) {
      string S;
      lli V, P;
      cin >> S >> V >> P;
      item[S] = make_pair(V, P);
    }

    for(int i = 0; i < N; ++i) {
      int L;
      cin >> L >> X[i] >> Y[i];
      while(L--) {
        string R;
        lli Q;
        cin >> R >> Q;
        citem[i].push_back(make_pair(R, Q));
      }
    }

    // cost
    fill(cost, cost+(1<<MAXN), INF);
    for(int b = 1; b < (1<<N); ++b) {
      vector<int> id;
      for(int i = 0; i < N; ++i) {
        if(b & (1<<i)) id.push_back(i);
      }
      int num = id.size();
      do {
        lli tmp = dist(0, 0, X[id[0]], Y[id[0]]);
        for(int i = 0; i+1 < num; ++i) {
          tmp += dist(X[id[i]], Y[id[i]], X[id[i+1]], Y[id[i+1]]);
        }
        tmp += dist(X[id[num-1]], Y[id[num-1]], 0, 0);
        cost[b] = min(cost[b], tmp);
      } while(next_permutation(id.begin(), id.end()));
    }

    // adv
    fill(adv, adv+(1<<MAXN), 0);
    for(int b = 1; b < (1<<N); ++b) {
      vector<pair<int, int> > v;
      for(int i = 0; i < N; ++i) {
        if(b & (1<<i)) {
          for(int j = 0; j < citem[i].size(); ++j) {
            string &s = citem[i][j].first;
            lli p = citem[i][j].second;
            v.push_back(make_pair(item[s].first, item[s].second-p));
          }
        }
      }
      int num = v.size();
      lli dp[W+1];
      fill(dp, dp+W+1, 0);
      for(int i = 0; i <= W; ++i) {
        for(int j = 0; j < num; ++j) {
          if(i - v[j].first < 0) continue;
          dp[i] = max(dp[i], dp[i-v[j].first] + v[j].second);
        }
      }
      adv[b] = dp[W];
    }

    fill(dp, dp+T+1, 0);
    for(int i = 0; i <= T; ++i) {
      for(int b = 1; b < (1<<N); ++b) {
        if(i-cost[b] < 0) continue;
        dp[i] = max(dp[i], dp[i-cost[b]] + adv[b]);
      }
    }
    cout << dp[T] << endl;
  }
  return 0;
}