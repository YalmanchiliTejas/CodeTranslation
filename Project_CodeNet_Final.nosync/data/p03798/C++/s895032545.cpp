
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <queue> 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <numeric>  
#include <functional>
#include <cassert>
#include <bitset>
#include <cctype>  
#include <iomanip> 
#include <limits>  
#include <regex>
// std::numeric_limits<int>::max(), min()
// std::setprecision(X)
// std::islower(), std::isupper(), std::tolower, std::toupper
// std::accumulate(m.begin(), m.end(), 0LL);
// std::sort(begin(),end()) // 0, 1, 2, 3 ,4 (default, less);
// std::priority_queue<int, vector<int>, less<int>> que; // 4, 3, 2, 1 (defualt, less) : 
// if ( std::regex_match(S, std::regex("(dream|dreamer|erase|eraser)*")) ) std::cout << "YES" << std::endl;
 
#define rep(i, n) for(int i = 0; i < (int)(n);    i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;

ll gcd ( ll a, ll b ) { if ( b == 0 ) return a; else return gcd ( b, a%b ); }
ll lcm ( ll a, ll b ) { return a * b / gcd(a, b); }

int N; 
std::string s; 
int sol(bool isSHEEP0, bool isSHEEP1, bool print = false) {
  std::vector<bool> isSHEEP(N);
  isSHEEP[0] = isSHEEP0;
  isSHEEP[1] = isSHEEP1;
  for(int i=2; i<N; i++) {
    if ( s[i-1] == 'o' && isSHEEP[i-1]  ) isSHEEP[i] =  isSHEEP[i-2];
    if ( s[i-1] == 'x' && isSHEEP[i-1]  ) isSHEEP[i] = !isSHEEP[i-2];
    if ( s[i-1] == 'o' && !isSHEEP[i-1] ) isSHEEP[i] = !isSHEEP[i-2];
    if ( s[i-1] == 'x' && !isSHEEP[i-1] ) isSHEEP[i] = isSHEEP[i-2];
  }

  if ( print ) {
    rep(i,N) { if ( isSHEEP[i] ) std::cout << "S"; else std::cout << "W"; }
    std::cout << std::endl;
  }

  auto check = [&](int x) -> bool {
    if ( s[x] == 'o' &&  isSHEEP[x] ) return isSHEEP[(x-1+N)%N] ==  isSHEEP[(x+1)%N];
    if ( s[x] == 'x' &&  isSHEEP[x] ) return isSHEEP[(x-1+N)%N] == !isSHEEP[(x+1)%N];
    if ( s[x] == 'o' && !isSHEEP[x] ) return isSHEEP[(x-1+N)%N] == !isSHEEP[(x+1)%N];
    if ( s[x] == 'x' && !isSHEEP[x] ) return isSHEEP[(x-1+N)%N] ==  isSHEEP[(x+1)%N];
    return false;
  };
  if ( check(N-1) && check(0) ) return true;
  else return false;
}

int main (void) {
  std::cin.tie(0);  std::ios::sync_with_stdio(false);
  std::cin >> N;
  std::cin >> s;

  bool rtn = false;
  rtn = sol(true, true);
  if ( rtn ) {
    sol(true,true,true);
    return 0;
  }

  rtn = sol(false, true);
  if ( rtn ) {
    sol(false,true,true);
    return 0;
  }

  rtn = sol(true, false);
  if ( rtn ) {
    sol(true,false,true);
    return 0;
  }

  rtn = sol(false, false);
  if ( rtn ) {
    sol(false,false,true);
    return 0;
  }

  std::cout << -1 << std::endl;  

  
  return 0;
}
