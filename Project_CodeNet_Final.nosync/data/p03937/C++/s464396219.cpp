#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};


int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  int cnt = 0;
  for (int i = 0; i < H; i++) {
    cin >> A[i];
    for (int j = 0; j < W; j++) {
      if (A[i][j] == '#') cnt++;
    }
  }
  if (cnt != H + W - 1) {
    cout << "Impossible" << endl;
    return 0;
  }


  vector<vector<int>> dp(H, vector<int>(W));
  dp[0][0] = A[0][0] == '#';
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A[i][j] == '.') continue;
      if (i > 0) dp[i][j] |= dp[i - 1][j];
      if (j > 0) dp[i][j] |= dp[i][j - 1];
    }
  }
  if (dp[H - 1][W - 1]) {
    cout << "Possible" << endl;
  } else {
    cout << "Impossible" << endl;
  }
  return 0;
}