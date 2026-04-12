#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv=vector<vector< T > >;

vvi g;
vector<set<int> > gs;
vi degree;

set<int> universe;

void remove(int u, int v) {
  for (int w : gs[v]) {
    gs[w].erase(v);
  }
  universe.erase(u);
  universe.erase(v);
}

int degree1(int u) {
  int cnt = 0;
  for (int v : gs[u]) {
    if ((int)gs[v].size() == 1) {
      cnt += 1;
    }
  }
  return cnt;
}

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  gs.resize(n);

  rep (i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a -= 1;
    b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
    gs[a].insert(b);
    gs[b].insert(a);
  }

  rep (i, n) {
    universe.insert(i);
  }

  deque<int> deg1;
  rep (i, n) {
    if ((int)gs[i].size() == 1) {
      deg1.push_back(i);
    }
  }

  while ((int)deg1.size() >= 2) {
    int u = deg1.front();
    debug(u);
    deg1.pop_front();
    bool continue_flag = false;
    for (int v : gs[u]) {
      if (degree1(v) >= 2) {
        printf("First\n");
        return 0;
      }
      if ((int)gs[v].size() <= 2) {
        remove(u, v);
        if ((int)gs[v].size() == 2) {
          for (int w : gs[v]) {
            if (w != u && (int)gs[w].size() == 1) {
              deg1.push_front(w);
            }
          }
        }
        continue_flag = true;
        break;
      }
      if (continue_flag) { continue; }
      deg1.push_back(u);
    }
  }

  if ((int)universe.size() == 1) {
    printf("First\n");
  } else {
    printf("Second\n");
  }

  return 0;
}
