#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N,M; cin >> N >> M;
  Graph G(N, vector<int>(N,0));
  rep(i,M) {
    int a,b; cin >> a >> b;
    a--; b--;
    G[a][b] = 1;
    G[b][a] = 1;
  }

  vector<int> num(N);
  rep(i,N) num[i] = i;
  int count = 0;
  do {
    bool can = true;
    if (num[0] != 0) can = false;
    for (int i = 1; i < N; i++) {
      if (G[num[i]][num[i-1]] == 0) can = false;
    }
    if (can) count++;
  } while (next_permutation(num.begin(),num.end()));

  cout << count << endl;
}