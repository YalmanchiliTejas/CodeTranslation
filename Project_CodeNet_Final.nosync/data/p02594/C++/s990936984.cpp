// Code for A - Air Conditioner
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define FOR(i,x,y) for(ll i=x;i<(ll)(y);i++)

#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

int main() {
  int x;
  cin >> x;

  if (x >= 30) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;

  }
  return 0;
}
