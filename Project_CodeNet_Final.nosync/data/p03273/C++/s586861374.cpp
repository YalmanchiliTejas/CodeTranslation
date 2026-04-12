
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <iomanip> // std::std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

typedef long long ll;

int main (void) {

  int H, W; std::cin >> H >> W;
  std::vector< std::vector<char> > a(H, std::vector<char>(W));
  for(int i=0; i<H; i++) for(int j=0; j<W; j++) std::cin >> a[i][j];

  std::vector<int> h(H), w(W);
  for(int i=0; i<H; i++) {
    bool ok = true;
    for(int j=0; j<W; j++) {
      if ( a[i][j] == '#' ) ok = false;
    }
    if ( ok ) h[i] = 1;
    else      h[i] = 0;
  }

  for(int j=0; j<W; j++) {
    bool ok = true;
    for(int i=0; i<H; i++) {
      if ( a[i][j] == '#' ) ok = false;
    }
    if ( ok ) w[j] = 1;
    else      w[j] = 0;
  }

  for(int i=0; i<H; i++) {
    bool fill = false;
    for(int j=0; j<W; j++) {
      if ( h[i] == 0 && w[j] == 0 ) {
        std::cout << a[i][j];
        fill = true;
      }
    }
    if( fill ) std::cout << std::endl;
    fill = false;
  }

  return 0;
}
