/*
 * cpp_filepath
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> ostream & operator << (ostream & out, vector<T> const & v) {
  for (auto &&a: v) out << a << " "; out << endl; return out;
}
template <class T> void dump(T &a) { cout << a << endl; }
void solve();
int main() { solve(); return 0; }


void solve() {
  string r, g, b;
  cin >> r >> g >> b;
  r += g;
  r += b;
  int n = stoi(r);
  if (n%4==0) cout << "YES";
  else cout << "NO";
  cout << endl;
}
