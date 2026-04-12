#include <bits/stdc++.h>
#include <variant>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a;
  cin>>a;
  if (a>=30) {
    cout<<"Yes\n";
  }else{
    cout<<"No\n";
  }
  return 0;
}
