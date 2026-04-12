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
set<pii> se;
vector<pii> vi;
vector<pii> rvi;
map<pii, int> ma;
vector<pll> g[1<<20];
vector<bool> visited(1<<20, false);
vector<ll> dist(1<<20, LONG_LONG_MAX);

bool comparator(const pii& u, const pii& v) {
    if(u.second < v.second) return true;
    return u.first < v.first;
}

int weight1(int i) {
    int x = vi[i].first-vi[i+1].first;
    int y = vi[i].second-vi[i+1].second;
    return min(abs(x), abs(y));
}

int weight2(int i) {
    int x = rvi[i].first-rvi[i+1].first;
    int y = rvi[i].second-rvi[i+1].second;
    return min(abs(x), abs(y));
}

int main() {
  std::ios::sync_with_stdio(false);
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  cin>>n;
  rep(i, n) {
      cin>>x>>y;
      se.insert({x, y});
  }

  for(auto it = se.begin();it != se.end();it++) {
      vi.pb(*it);
      rvi.pb({(*it).second, (*it).first});
  }

  sort(rvi.begin(), rvi.end());
  rep(i, vi.size()) {
      swap(rvi[i].first, rvi[i].second);
      ma[vi[i]] = i+1;
  }

  rep(i, vi.size()-1) {
      g[i+1].pb({weight1(i), i+2});
      g[i+2].pb({weight1(i), i+1});

      int x = ma[rvi[i]];
      int y = ma[rvi[i+1]];
      g[x].pb({weight2(i), y});
      g[y].pb({weight2(i), x});
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
