#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, long long> pdl;

const long double pi = 3.141592653589793;

#define debug(x) cout << #x << " = " << (x) << endl;
#define rep(i, n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair
#define mod 1000000007


int n, x, y;
vector<pii> vx;
vector<pii> vy;
vector<pll> g[1<<20];
vector<bool> visited(1<<20, false);
vector<ll> dist(1<<20, LONG_LONG_MAX);

int main() {
  ios::sync_with_stdio(false);
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  cin>>n;
  rep(i, n) {
      cin>>x>>y;
      vx.pb({x, i});
      vy.pb({y, i});
  }

  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());

  rep(i, vx.size()-1) {
      int wt = vx[i+1].first-vx[i].first;
      int x = vx[i].second;
      int y = vx[i+1].second;

      g[x].pb({wt, y});
      g[y].pb({wt, x});

      wt = vy[i+1].first-vy[i].first;
      x = vy[i].second;
      y = vy[i+1].second;

      g[x].pb({wt, y});
      g[y].pb({wt, x});
  }

  set<pll> pq;
  pq.insert({0, 1});
  ll answer = 0;


  while(not pq.empty()) {
      pii temp = *(pq.begin());
      pq.erase(pq.begin());
      if(visited[temp.second]) continue;
      visited[temp.second]=1;
      dist[temp.second]=temp.first;
      answer = answer + (long long)(temp.first);
      for(auto&z:g[temp.second]) {
          if(not visited[z.second] and z.first < dist[z.second]) {
              pq.erase({dist[z.second], z.second});
              dist[z.second]=z.first;
              pq.insert({z.first, z.second});
          }
      }
  }

  cout<<answer<<endl;

  return 0;
}
