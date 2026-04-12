//https://atcoder.jp/contests/abc134/tasks/abc134_e
//E - Sequence Decomposing
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
  ll N; cin>>N;
  vector<ll> an(N);
  for(auto&& a:an) cin>>a;

  multiset<ll> lis;
  for(const auto& a:an){
    auto it = lis.lower_bound(a);
    if(it != lis.begin()){
      --it;
      lis.erase(it);
    }
    lis.insert(a);
  }
  //dump(lis);
  cout<<lis.size()<<endl;
  return 0;
}