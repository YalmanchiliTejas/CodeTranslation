#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  int N, M; cin >> N >> M;
  int tree[N+1][N+1] = {};
  rep(i, M) {
    int a, b; cin >> a >> b;
    tree[a][b] = 1; tree[b][a] = 1;
  }

  int result = 0;
  int v[N]; rep(i, N) v[i] = i+1;
  do {
    if (v[0]!=1) continue;
    bool ok = true;
    rep(i, N-1) { if (tree[v[i]][v[i+1]]==0) ok = false;}
    if (ok) result++;
  } while( next_permutation(v, v+N) );


  cout << result << endl;
  return 0;
}