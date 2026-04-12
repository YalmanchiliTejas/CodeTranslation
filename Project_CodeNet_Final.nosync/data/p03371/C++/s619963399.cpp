#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define FOR(i, first, last) for (int i = (first); i < (last); ++i)
#define REP(i, n) FOR(i, 0, n)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) std::cerr << #x << " = " << (x) << std::endl;
#define DUMPR(v) REP(_i,v.size()){std::cerr<< #v << "[" << _i << "] = " << (v[_i]) << std::endl;}
#define CIN_VEC(v,N) {v.clear(); v.reserve(N); REP(i,N){typename decltype(v)::value_type x; cin>>x; v.emplace_back(x);}};
#define DECL_CIN(type,valname) type valname; cin >> valname;

inline int to_int(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T> inline string to_string(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}

typedef unsigned long long ull;
typedef unsigned long ul;

int main() {
  DECL_CIN(int,A);
  DECL_CIN(int,B);
  DECL_CIN(int,C);
  DECL_CIN(int,X);
  DECL_CIN(int,Y);

  int a = A*X + B*Y;

  int z = min(X,Y);
  int b = A*(X-z) + B*(Y-z) + C*2*z;

  int c = C*2*max(X,Y);

  DUMP(a);
  DUMP(b);
  cout<<min(min(a,b),c)<<endl;

  return 0;
}
