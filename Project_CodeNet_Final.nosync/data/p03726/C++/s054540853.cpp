#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define _size(X) (int)((X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 100000;
int N;
int a[MAX_N], b[MAX_N];
int match[MAX_N];

vector<int> G[MAX_N];

bool dfs(int par, int v) {
    for (int i = 0; i < G[v].size(); ++i) {
        if (G[v][i] != par) {
            if (!dfs(v, G[v][i])) {
                return false;
            }
        }

    }

    if (match[v] < 0) {
        if (par < 0 || match[par] >= 0) return false;
        else match[v] = match[par] = v;
    }

    return true;
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  rep(i, N-1) cin >> a[i] >> b[i];
  rep(i, N-1) { 
      --a[i]; --b[i]; 
      G[a[i]].push_back(b[i]);
      G[b[i]].push_back(a[i]);
  }


  memset(match, -1, sizeof(match));
  if (dfs(-1, 0)) {
      cout << "Second" << endl;
  } else {
      cout << "First" << endl;
  }
 
  return 0;
}
