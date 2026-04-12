#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (int i = (int)a; i < (int)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265359
#define EPS 1e-12

bool used[10];
int n, m;
vector<int> g[50];

int main(void)
{
  vector<int> data;
  cin >> n >> m;
  REP(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int ans = 0;
  for(int i=0; i<n; ++i) data.push_back(i);
  do {
    if(data[0] != 0) continue;
    bool ff = true;
    for(int i=0; i<n-1; ++i) {
      bool flag = false;
      for(int j: g[data[i]]) {
        if(j == data[i+1]) {
          flag = true;
        }
      }
      if(!flag) ff = false;
    }
    if(ff) ans++;
  } while(next_permutation(data.begin(), data.end()));

  cout << ans << endl;

  return 0;
}
