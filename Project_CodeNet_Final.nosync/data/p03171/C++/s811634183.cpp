// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a); i<(b);++i)
#define rep(i, n) FOR(i, 0, n)

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve
ll dp[3001][3001];
int n;
vector<ll> a;

ll calc(int i, int j){
  if(dp[i][j] >= 0)return dp[i][j];
  if(j == i + 1)return a[i];
  ll res = -linf;

  res = max(res, a[i] - calc(i+1, j));
  res = max(res, a[j-1] - calc(i, j-1));

  return dp[i][j] = res;
}

int main(int argc, char const* argv[])
{
  cin >> n;
  a = vector<ll>(n, 0);
  rep(i, n)cin >> a[i];
  rep(i, n+1){
    rep(j, n+1){
      dp[i][j] = -1;
    }
  }
  cout << calc(0, n) << endl;
	return 0;
}
