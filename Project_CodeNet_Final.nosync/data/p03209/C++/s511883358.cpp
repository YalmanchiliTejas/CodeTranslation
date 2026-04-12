#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cmath>
#include <utility> // pair make_pair
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits> // LLONG_MAX, LLONG_MIN, INT_MIN, INT_MAX
#include <assert.h>

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ll long long
#define int ll
#define INF INT_MAX/10
#define MOD 1000000007

using namespace std;
using Pi = pair<int, int>;
using Graph = vector<vector<int> >;
using WeightGraph = vector<vector<Pi> >;

int L[70];

int rec(int N, int X) {
  //cout << "N is : " << N << " X is : " << X<< endl;
  if (X == 0) {
    //cout << "1" << endl;
    return 0;
  } else if (N == 0) {
    //cout << "2" << endl;
    return 1;
  } else if (X > 4 * pow(2, N) - 3) {
    //cout << "3" << endl;
    return rec(N, 4 * pow(2, N) - 3);
  } else if ( X <= 4 * pow(2, N-1) - 2) {
    //cout << "4" << endl;
    return rec(N-1, X-1);
  } else {
    //cout << "5: L[N-1] is :" << L[N-1] << endl;
    
    return L[N-1] + 1 + rec(N-1, X - (4 * pow(2, N-1) - 2) - 1);
  }
}

signed main() {
  int N, X; cin >> N >> X;
  rep(i, N) {
    L[i] = 2 * pow(2, i) - 1;
  }

  int x = rec(N, X);
  cout << x << endl;
}
