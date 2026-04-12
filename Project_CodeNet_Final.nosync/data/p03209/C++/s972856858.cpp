
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> 
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> ostream & operator << (ostream & out, vector<T> const & v) {
  for (auto &&a: v) out << a << " "; out << endl; return out;
}
template <class T> void dump(T &a) { cout << a << endl; }
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }


int N; ll X;

ll rec(int n, ll x) {
  if (n==0) return 1;
  if (x==1) return 0;

  ll bp = (1LL<<(n+1)) - 3;
  ll p = (1LL<<(n)) - 1;
  if (x <= bp + 1) return rec(n-1, x-1);
  if (x == bp + 2) return p + 1;
  if (x <= (bp+1) * 2) return p + 1 + rec(n-1, x-bp-2);
  return p * 2 + 1;
}

void solve() {
  cin >> N >> X;
  cout << rec(N, X) << endl;
}
int main() {
 
  solve();

  return 0;
}
