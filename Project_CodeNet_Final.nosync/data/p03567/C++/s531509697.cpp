#include "bits/stdc++.h"
#define LF '\n'
#define ALL(x) x.begin(), x.end()
#define iostreamBooster() { cin.tie(nullptr); ios_base::sync_with_stdio(false); }
using namespace std;
typedef int64_t i64;
typedef pair<int,int> pii;
template<class A, class B>inline bool chmax(A &a, const B &b){return b>a ? a=b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b<a ? a=b,1 : 0;}
constexpr int INF = 0x3f3f3f3f;
template<class Itr> void dump(Itr begin, Itr end) { for (;begin != end; ++begin) clog << *begin << LF; }

signed main()
{
  string s;
  cin >> s;
  puts(s.find("AC") < s.length() ? "Yes": "No");

  return 0;
}

