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

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> a;
  rep(i, n){
    ll x;
    cin >> x;
    a.pb(x);
  }
  ll k = 0;
  while(true){
    ll s = 0;
    rep(i, n){
      s += a[i] / n;
    }
    k += s;
    bool flag = true;
    rep(i, n){
      a[i] = (a[i] % n) + s - (a[i] / n);
      if(a[i] >= n)flag = false;
    }
    if(flag)break;
  }
  cout << k << endl;
	return 0;
}
