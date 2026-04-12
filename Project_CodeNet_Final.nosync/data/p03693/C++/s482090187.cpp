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
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007

int r, g, b;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> r >> g >> b;
  int x = 100*r+10*g+b;
  if (x % 4 == 0) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}
