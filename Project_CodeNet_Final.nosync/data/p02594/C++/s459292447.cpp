#include <bits/stdc++.h>
using namespace std;

#ifdef local
template <class T> void _E(T x) { cerr << x; } void _E(double x) { cerr << fixed << setprecision(6) << x; } void _E(string s) { cerr << "\"" << s << "\""; } template <class A, class B> void _E(pair<A, B> x) { cerr << '('; _E(x.first); cerr << ", "; _E(x.second); cerr << ")"; } template <class T> void _E(vector<T> x) { cerr << "["; for (auto it = x.begin(); it != x.end(); ++it) { if (it != x.begin()) cerr << ", "; _E(*it); } cerr << "]"; }
void ERR() {} template <class A, class... B> void ERR(A x, B... y) { _E(x); cerr << (sizeof...(y) ? ", " : " "); ERR(y...); }
#define debug(x...) do { cerr << "{ "#x" } -> { "; ERR(x); cerr << "}" << endl; } while(false)
#else
#define debug(...) 114514.1919810
#endif

using ll = long long;


int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false), cin.tie(nullptr);

  int x;
  cin >> x;
  cout << (x >= 30 ? "Yes" : "No") << "\n";
}

