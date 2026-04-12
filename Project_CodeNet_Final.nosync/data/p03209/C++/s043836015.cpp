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
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;

// solve
ll L[52];
ll D[52];

ll calc(int n, ll x){
  if(x == 0)return 0;
  else if(n == 0)return 1;
  else if(x <= L[n-1] + 1)return calc(n-1, x-1);
  else if(x <= 2 + L[n] * 2)return D[n-1] + 1 + calc(n-1, x-2-L[n-1]);
  else return 2 * D[n-1] + 1;
}

int main(int argc, char const* argv[])
{
  int n;
  ll x;
  cin >> n >> x;
  L[0] = 1;
  D[0] = 1;
  rep(i, n){
    L[i+1] = 3 + 2 * L[i];
    D[i+1] = 1 + 2 * D[i];
  }
  cout << calc(n, x) << endl;
	return 0;
}
