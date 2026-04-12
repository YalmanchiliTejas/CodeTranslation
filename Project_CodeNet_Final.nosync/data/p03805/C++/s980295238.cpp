#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define INF 1100000000
#define LLINF 1100000000000000000
#define MOD 1000000007
#define FI first
#define SE second
#define MP make_pair

using namespace std;
typedef long long ll;


int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> ajmt(N, vector<bool>(N));
  REP(i, M) {
    int a, b; cin >> a >> b;
    a--, b--;
    ajmt[a][b] = ajmt[b][a] = true;
  }

  vector<int> v(N);
  REP(i, N) v[i] = i;
  int ans = 0;
  do {
    bool flag = true;
    REP(i, N - 1) {
      if (!ajmt[v[i]][v[i + 1]]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  } while (next_permutation(v.begin() + 1, v.end()));
  cout << ans << endl;
  return 0;
}