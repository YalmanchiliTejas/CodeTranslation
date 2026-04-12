#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<vector<int> > vec(n, vector<int>(0));
  REP(i, m) {
    int temp1, temp2; cin >> temp1 >> temp2; --temp1; --temp2;
    vec[temp1].push_back(temp2);
    vec[temp2].push_back(temp1);
  }
  vector<int> num(n-1); FOR(i, 1, n) num[i-1] = i;
  int ans = 0;
  do {
    vector<int> temp(n);
    temp[0] = 0;
    REP(i, n-1) temp[i+1] = num[i];
    bool ok = true;
    REP(i, n-1) {
      bool hantei = false;
      for (int aa : vec[temp[i]]) {
        if (aa == temp[i+1]) {
          hantei = true;
          break;
        }
      }
      if (!hantei) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  } while (next_permutation(ALL(num)));
  cout << ans << "\n";
  return 0;
}
