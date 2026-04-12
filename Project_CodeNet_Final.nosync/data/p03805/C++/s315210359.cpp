#include <string.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define REP1(i,n) for(int i=1;i<=(n);++i)

#define SORT(V) sort((V).begin(), (V).end())

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<pair<int, int> > VPII;
typedef long long LL;
typedef vector<long long> VL;
typedef pair<long long,long long> PLL;
typedef vector<pair<long long,long long> > VPLL;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int N, M;
map<int, set<int> > G;

struct S {
  int p;
  int bit;
};

int bfs() {
  int total = 0;
  queue<struct S> q;
  q.push({1, 1});
  while (!q.empty()) {
    int p = q.front().p;
    int bit = q.front().bit;
    q.pop();
    if (bit == ((1 << N) - 1)) {
      ++total;
    } else {
      for (int n : G[p]) {
        if ((bit & (1 << (n - 1))) == 0) {
          q.push({n, bit | (1 << (n - 1))});
        }
      }
    }
  }
  return total;
}

int main() {
  cin >> N >> M;
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    G[a].insert(b);
    G[b].insert(a);
  }
  int a = bfs();
  cout << a << endl;
}
