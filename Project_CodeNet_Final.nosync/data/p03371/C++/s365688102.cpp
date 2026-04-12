
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue> //std::priority_queue<int> que; // 4, 3, 2, 1 (defualt, less) : 
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <numeric>  // std::accumulate(m.begin(), m.end(), 0LL);
#include <functional>
#include <cassert>
#include <cctype>  // std::islower(), std::isupper(), std::tolower, std::toupper
#include <iomanip> // std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

typedef long long ll;

int main (void) {
  int A, B, C, X, Y; std::cin >> A >> B >> C >> X >> Y;

  if ( A+B <= C*2 ) {
    std::cout << X*A + Y*B << std::endl;
  }
  else {
    int ans = 0;
    ans += std::min(X,Y) * 2*C;

    int rest = 1e9;

    int restX = X-std::min(X,Y);
    int restY = Y-std::min(X,Y);
    for(int i=0; i<=std::max(X-std::min(X,Y),Y-std::min(X,Y)); i++) {
      rest = std::min(rest, i*2*C + std::max(0,(restX-i))*A + std::max(0,(restY-i))*B);
    }
    std::cout << ans+rest << std::endl;
  }
  return 0;
}
