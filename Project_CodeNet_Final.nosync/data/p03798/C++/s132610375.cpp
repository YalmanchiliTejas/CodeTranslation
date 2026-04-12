#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

typedef long long ll;
//typedef pair<int,int> Pint;
typedef pair<ll, ll> P;
//typedef pair<int, pair<int, int>> P;
//typedef tuple<int,int,int> T;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define revrep(i, n) for(ll i = n-1; i >= 0; i--)
ll max(ll a, ll b){return (a > b) ? a : b;}
ll min(ll a, ll b){return (a < b) ? a : b;}
ll Mypow(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x;
    k /= 2;
  }
  return res;
}

ll INFL = 1LL << 60;//10^18 = 2^60
int INF = 1 << 30;//10^9
ll MOD  = 1000000007;
//vector<int> dy = {0,0,1,-1};
//vector<int> dx = {1,-1,0,0};

int main(){
  int N; cin >> N;
  string S; cin >> S;
  bool l = 1;
  vector<int> K(N+1, 0);
  //SS
  K[0] = 1; K[1] = 1;
  for(int i = 2; i <= N; i++){
    if(K[i-1] == 1 && K[i-2] == 1 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 1 && K[i-2] == 0 && S[i-1] == 'x') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 0 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 1 && S[i-1] == 'x') K[i] = 1;
  }
  if(K[0] == 1){
    if(S[0] == 'o'){
      if(K[N-1] != K[1]) l = 0;
    }else{
      if(K[N-1] == K[1]) l = 0;
    }
  }else{
    if(S[0] == 'o'){
      if(K[N-1] == K[1]) l = 0;
    }else{
      if(K[N-1] != K[1]) l = 0;
    }
  }
  if(K[0] == K[N] && l){
    rep(i, N){
      if(K[i] == 1) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    return 0;
  }
  rep(i, N+1) K[i] = 0; l = 1;
  //SW
  K[0] = 1; K[1] = 0;
  for(int i = 2; i <= N; i++){
    if(K[i-1] == 1 && K[i-2] == 1 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 1 && K[i-2] == 0 && S[i-1] == 'x') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 0 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 1 && S[i-1] == 'x') K[i] = 1;
  }
  if(K[0] == 1){
    if(S[0] == 'o'){
      if(K[N-1] != K[1]) l = 0;
    }else{
      if(K[N-1] == K[1]) l = 0;
    }
  }else{
    if(S[0] == 'o'){
      if(K[N-1] == K[1]) l = 0;
    }else{
      if(K[N-1] != K[1]) l = 0;
    }
  }
  if(K[0] == K[N] && l){
    rep(i, N){
      if(K[i] == 1) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    return 0;
  }
  rep(i, N+1) K[i] = 0; l = 1;
  //WS
  K[0] = 0; K[1] = 1;
  for(int i = 2; i <= N; i++){
    if(K[i-1] == 1 && K[i-2] == 1 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 1 && K[i-2] == 0 && S[i-1] == 'x') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 0 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 1 && S[i-1] == 'x') K[i] = 1;
  }
  if(K[0] == 1){
    if(S[0] == 'o'){
      if(K[N-1] != K[1]) l = 0;
    }else{
      if(K[N-1] == K[1]) l = 0;
    }
  }else{
    if(S[0] == 'o'){
      if(K[N-1] == K[1]) l = 0;
    }else{
      if(K[N-1] != K[1]) l = 0;
    }
  }
  if(K[0] == K[N] && l){
    rep(i, N){
      if(K[i] == 1) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    return 0;
  }
  rep(i, N+1) K[i] = 0; l = 1;
  //WW
  K[0] = 0; K[1] = 0;
  for(int i = 2; i <= N; i++){
    if(K[i-1] == 1 && K[i-2] == 1 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 1 && K[i-2] == 0 && S[i-1] == 'x') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 0 && S[i-1] == 'o') K[i] = 1;
    else if(K[i-1] == 0 && K[i-2] == 1 && S[i-1] == 'x') K[i] = 1;
  }
  if(K[0] == 1){
    if(S[0] == 'o'){
      if(K[N-1] != K[1]) l = 0;
    }else{
      if(K[N-1] == K[1]) l = 0;
    }
  }else{
    if(S[0] == 'o'){
      if(K[N-1] == K[1]) l = 0;
    }else{
      if(K[N-1] != K[1]) l = 0;
    }
  }
  if(K[0] == K[N] && l){
    rep(i, N){
      if(K[i] == 1) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
}
