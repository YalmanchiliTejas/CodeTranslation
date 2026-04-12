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

ll N;
ll a[60], S, ans;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> a[i];

  {
    bool fl = true;
    rep( i, N )
    {
      fl &= a[i] < N;
    }

    if( fl )
    {
      std::cout << 0 << std::endl;

      return 0;
    }
  } 

  while( true )
  {
    bool fl = true;

    S = 0;

    rep( i, N )
      S += a[i]/N;

    rep( i, N )
    {
      ll c = a[i]/N;
      a[i] = a[i]-c*N+(S-c);
      fl &= a[i] < N;
    }

    ans += S;

    if( fl )
      break;
  }

  std::cout << ans << std::endl;

  return 0;
}