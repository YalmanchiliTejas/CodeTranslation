#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

typedef int Weight;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;

typedef long long ll;

struct M {
  int v, p;
  M(int v, int p) : v(v), p(p) {}
  M(){}
};

// Â§ÀÈµ
ll knapsack(vector<int> v, vector<int> w, int W) {
  ll dp[W+1];
  memset(dp,0,sizeof(dp));
  REP(i,v.size())
    for(int j=w[i]; j <= W; ++j) 
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
  return dp[W];
}

int main() {
  int n,m,w,t;
  cin >> n >> m >> w >> t;
  map<string, M> ma;
  vector<int> kati0, weight0;
  REP(i,m) {
    string s;
    int v,p;
    cin >> s>>v>>p;
    ma[s] = M(v,p);
    kati0.push_back(v);
    weight0.push_back(p);
  }
  int l[n],x[n],y[n];
  vector<string> r[n];
  vector<int> q[n];
  REP(i,n) {
    cin >> l[i]>>x[i]>>y[i];
    REP(j,l[i]) {
      string a;
      int b;
      cin >> a >> b;
      r[i].push_back(a);
      q[i].push_back(b);
    }
  }
  int dis[n];                // (0,0)©çÌ£
  Matrix g(n, Array(n, INF));
  REP(i,n) {
    REP(j,n) {
      g[i][j] = abs((x[i]-x[j])) + abs(y[i]-y[j]);
    }
    dis[i] = abs(x[i]) + abs(y[i]);
  }


  vector<int> v, time;
  
  for (int S=1; S<(1<<n); ++S) {
    int size = 0;
    vector<int> perm;
    REP(i,n) if (S>>i&1) perm.push_back(i);
    // ÅZn~gÂHvZ
    int mincost = INF;
    do {
      int cost = dis[perm[0]];
      REP(i,perm.size()-1) {
        cost += g[perm[i]][perm[i+1]];
      }
      cost += dis[perm[perm.size()-1]];
      mincost = min(mincost, cost);
    } while(next_permutation(ALL(perm)));
//    cout << "mincost = " << mincost << endl;

    // ÅåvvZ@ibvTbNâè
    vector<int> kati, weight;
    REP(i,perm.size()) {
      REP(j,l[perm[i]]) {
        kati.push_back(ma[r[perm[i]][j]].p-q[perm[i]][j]);
        weight.push_back(ma[r[perm[i]][j]].v);
      }
    }
    // FOR(it, kati)
    //   cout << *it << " ";
    // cout << endl;
    // FOR(it, weight)
    //   cout << *it << " ";
    // cout << endl;

    int maxkati = knapsack(kati, weight, w);
//    cout << "maxkati = " << maxkati << endl;

    v.push_back(maxkati);
    time.push_back(mincost);
  }
  cout << knapsack(v, time, t) << endl;
}