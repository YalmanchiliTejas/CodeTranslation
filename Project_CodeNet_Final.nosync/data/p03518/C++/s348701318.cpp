#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int N;
int A[200];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  rep(i, N) cin >> A[i];
  vector<int> seq;
  rep(t, N) {
    int pos = -1;
    rep(x, N) if (A[x] == N-1-t) pos = x;
    if (pos == N-1-t) continue;
    // [pos+1, N-1-t]
    for (int i=1; i<=N; i++) {
      seq.pb(1);
      if (pos+1 <= i && i <= N-1-t) swap(A[i-1], A[i]), seq.pb(N-1);
    }
    //rep(i, N) cout<<A[i]<<",";cout<<"\n";
  }
  assert(is_sorted(A, A+N));
  cout << seq.size() << "\n";
  for (int x : seq) cout << x << "\n";
  return 0;
}
