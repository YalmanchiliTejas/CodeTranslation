#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
template<class T> using vv=vector<vector< T > >;

int main() {
  int n, q;
  cin >> n >> q;
  vi a(q);
  vi b(q);
  rep (i, q) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  int current = 0;
  vi used(n, 0);
  used[1] = 1;
  rep (i, q) {
    if (current == a[i]) {
      current = b[i];
    } else if (current == b[i]) {
      current = a[i];
    }
    swap(used[a[i]], used[b[i]]);
    if (current == 0) {
      used[1] = 1;
    } else if (current == n-1) {
      used[n-2] = 1;
    } else {
      used[current-1] = used[current+1] = 1;
    }
  }
  used[current] = 1;
  int ans = 0;
  rep (i, n) {
    ans += used[i];
  }
  printf("%d\n", ans);

  return 0;
}
