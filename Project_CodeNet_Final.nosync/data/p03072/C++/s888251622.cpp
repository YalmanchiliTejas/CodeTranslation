#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
//#include <function>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)


int main() {

  int N;
  cin >> N;
  vector<int> H(N);
  REP(i, N) cin >> H[i];

  int tmp = H[0];
  int count = 0;

  REP(i, N){
    if (tmp <= H[i]){
      count++;
      tmp = H[i];
    }
  }

  cout << count << endl;
  return 0;
}
