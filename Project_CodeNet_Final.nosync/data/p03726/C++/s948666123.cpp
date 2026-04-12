#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

// #define FL fflush(stdout)

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
  return scanf("%lld", &x);
}

int GI(int& x) {
  return scanf("%d", &x);
}

#define maxn 100010
int N;
vector<vector<int> > adj;
queue<PII> q1;
bool visited[maxn];
priority_queue<PII> q2;

int main() {
  GI(N);
  adj.resize(N);
  memset(visited, 0, sizeof visited);

  FORN(i, N-1) {
    int a, b;
    GI(a); GI(b);
    a--; b--;
    adj[a].PB(b);
    adj[b].PB(a);
  }

  PII root = MP(0, 0);
  q1.push(root);
  q2.push(root);

  while (q1.size() > 0) {
    PII node = q1.front(); q1.pop();
    visited[node.SS] = true;
    for (auto child : adj[node.SS]) {
      if (!visited[child]) {
        q1.push(MP(node.FF+1, child));
        q2.push(MP(node.FF+1, child));
      }
    }
  }

  memset(visited, 0, sizeof visited);
  while (q2.size() > 0) {
    PII leaf = q2.top(); q2.pop();
//    printf("leaf: %d at depth %d\n", leaf.SS, leaf.FF);

    if (visited[leaf.SS]) continue;

    visited[leaf.SS] = true;
    int n_mark = 0;
    for (auto node: adj[leaf.SS]) {
      if (!visited[node]) {
        visited[node] = true;
        n_mark++;
      }
    }
    assert(n_mark < 2);
//    printf("num marked: %d\n", n_mark);
    if (n_mark == 0) {
      printf("First\n");
      return 0;
    }
  }
  printf("Second\n");
  return 0;
}
