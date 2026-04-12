#include "bits/stdc++.h"
#define LF '\n'
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef int64_t i64;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;
template<class Itr> void dump(Itr begin, Itr end) { for (;begin != end; ++begin) clog << *begin << LF; }

signed main()
{
  cin.tie(nullptr), ios::sync_with_stdio(false);
  string s = "";
  char a,b,c;
  cin>>a>>b>>c;
  s += a;
  s += b;
  s += c;

  cout << (stoi(s) % 4 == 0 ? "YES" : "NO") << LF;

  return 0;
}

