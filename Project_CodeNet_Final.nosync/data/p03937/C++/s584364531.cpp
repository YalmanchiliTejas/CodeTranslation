#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;

ll H, W;
std::string A[10];

int main()
{
  std::cin >> H >> W;
  
  rep( i, H )
    std::cin >> A[i];

  ll cnt = 0;

  rep( i, H ) rep( j, W )
    cnt += A[i][j] == '#';

  std::cout << (cnt == H+W-1 ? "Possible" : "Impossible") << std::endl;

  return 0;
}