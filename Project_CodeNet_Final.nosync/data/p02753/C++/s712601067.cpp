#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <set>
#include <string.h>

using namespace std;

typedef long long ll;

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define REP3(i,st,en) for(ll (i)=(st);(i)<(en);(i)++)

using P = pair<ll, ll>;
const int MOD = 1e9+7;
const ll INF = 1e+14;
const double PI = 3.14159265349;

// Extended Print Func
template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& input){
    os << "[ ";
    REP(i, input.size()){
        os << input[i];
        if (i < input.size()-1) { os << " "; }
    }
    os << " ]";
    return os;
}
void print() { std::cout << "\n"; }
template<class T, class... A> void print(const T& first, const A&... rest) { std::cout << first << " "; print(rest...); }
template<class... A> void print(const A&... rest) { print(rest...); }



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  ll ans = 0;
  if (S[0]!=S[1]){
      ans = 1;
  } else if (S[1]!=S[2]){
      ans = 1;
  } else if (S[2]!=S[0]){
      ans = 1;
  }
  
  cout << ((ans==0) ? "No" : "Yes") << "\n";
  return 0;
}
