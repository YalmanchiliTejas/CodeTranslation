
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int i = 0; i < (n); i++)

template <class T = int>
T in() { T x; std::cin >> x; return x; }
#define output(e) std::cout << e << '\n'

#ifdef LOCAL
#define db std::cout << "L" << __LINE__
#define de << "\n"
#define dv(x) << " " << #x << "->" << x
#else
#define db
#define de
#define dv(x)
#endif

//
// Implementation
//

#define MAX_N 300000

int tp[MAX_N];

int main() {
  int N = in();
  rep(i, N) tp[i] = in();

  bool reach = false;
  int curr = 0;
  while (true) {
    if (curr == N-1) {
      reach = true;
    }
    int maxpos = -1;
    int nextmaxpos = 0;
    for (int i=curr+1; i<curr+1+(tp[curr]/10); i++) {
      if (i >= N) break;
      int can = i+(tp[i]/10);
      if (can > nextmaxpos) {
        nextmaxpos = can;
        maxpos = i;
      }
    }
    if (maxpos == -1) {
      break;
    }
    db dv(curr) de;
    curr = maxpos;
  }
  if (!reach) {
    output("no");
    return 0;
  }
  
  reach = false;
  curr = N-1;
  while (true) {
    if (curr == 0) {
      reach = true;
    }
    int maxpos = -1;
    int nextmaxpos = 9999999;
    for (int i=curr-1; i>curr-1-(tp[curr]/10); i--) {
      if (i < 0) break;
      int can = i-(tp[i]/10);
      if (can < nextmaxpos) {
        nextmaxpos = can;
        maxpos = i;
      }
    }
    if (maxpos == -1) {
      break;
    }
    curr = maxpos;
    db dv(curr) de;
  }
  if (!reach) {
    output("no");
    return 0;
  }

  output("yes");
}

