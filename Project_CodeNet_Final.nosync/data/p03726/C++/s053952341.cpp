#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MOD = (int)1e9 + 7;

class modint {
  int v;
public:
  modint (): v(0) { }
  modint (ll v): v((v + MOD) % MOD) { }

  bool operator== (modint x) { return v == x.v; }
  bool operator!= (modint x) { return v != x.v; }

  modint operator+ (modint x) { return v + x.v; }
  modint operator- (modint x) { return v - x.v; }
  modint operator* (modint x) { return (ll)v * x.v; }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }

  int operator* () { return v; }
};

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 105000;

int N;
vector<int> gph[N_];
int deg[N_];
bool chk[N_];

int main() {
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int a, b; scanf("%d%d", &a, &b);
    gph[a].push_back(b);
    gph[b].push_back(a);
    deg[a] += 1;
    deg[b] += 1;
  }

  try {
    if(N <= 2) throw "Second";

    priority_queue< pii, vector<pii>, greater<pii> > pq;
    for(int i = 1; i <= N; i++) {
      pq.push(pii(deg[i], i));
    }

    auto go = [&pq](int u) {
      chk[u] = true;
      for(int v : gph[u]) if(!chk[v]) pq.push(pii(--deg[v], v));
    };

    while(!pq.empty()) {
      int d, u; tie(d, u) = pq.top(); pq.pop();
      if(deg[u] != d || chk[u]) continue;

      if(deg[u] == 0) throw "First";

      go(u);

      for(int v : gph[u]) if(!chk[v]) {
        go(v);
        break;
      }
    }
    throw "Second";
  }catch(const char* s) {
    cout << s << endl;
  }
  return 0;
}
