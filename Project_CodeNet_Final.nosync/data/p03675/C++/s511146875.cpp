#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define ALL(a) (a).begin(),(a).end()
#define ITER(e, v) for(const auto& e : v)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<"\n"

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  IN(N);

  deque<int> q;
  REP(i, N) {
    IN(a);
    if (i % 2 == 1)
      q.push_back(a);
    else
      q.push_front(a);
  }
  if (N % 2 == 0) {
    reverse(ALL(q));
  }
  bool first = true;
  ITER(e, q) {
    if (first)
      cout << e;
    else
      cout << " " << e;
    first = false;
  }
  cout << "\n";

  return 0;
}
