#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IFOR(v,it) for(VI::iterator it=(v).begin();it!=(v).end();++it)

int N, M;
int solve(vector<vector<bool> >& edge, bool visited[9], int start) {
  bool allVisited = true;
  int count = 0;
  REP(i, N) {
    if (!visited[i]) {
      allVisited = false;
      if (edge[start][i]) {
        visited[i] = true;
        count += solve(edge, visited, i);
        visited[i] = false;
      }
    }
  }
  if (allVisited)
    return 1;
  return count;
}

int main() {
  cin >> N >> M;

  vector<vector<bool> > edge;
  REP(i, N) {
    vector<bool> v(N, false);
    edge.PB(v);
  }
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    edge[a-1][b-1] = true;
    edge[b-1][a-1] = true;
  }
  bool visited[8];
  fill(visited, visited + 8, false);
  visited[0] = true;
  cout << solve(edge, visited, 0) << endl;

  return 0;
}
