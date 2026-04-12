#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> ipair;
typedef tuple<int, int, int> ituple;

// const int INF = INT_MAX;
const ll INF = LLONG_MAX;
// const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (3000 + 2)
int n;
int a[MAX_N];
ll dp[2][MAX_N][MAX_N];

ll rec(int player, int start, int end){
  if (dp[player][start][end] != INF){
    return dp[player][start][end];
  }

  ll score;

  if (player == 0){
    if (start == end){
      score = a[start];
    }
    else{
      score = max(a[start] + rec(1, start + 1, end), a[end] + rec(1, start, end-1));
    }
  }
  else{
    if (start == end){
      score = -a[start];
    }
    else{
      score = min(rec(0, start + 1, end) - a[start], rec(0, start, end-1) - a[end]);
    }

  }

  dp[player][start][end] = score;
  // printf("dp[%d][%d][%d] = %lld\n", player, start, end, score);

  return dp[player][start][end];

}

void exec(){
  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> a[i];

    for (int j = 0; j < n; j++){
      dp[0][i][j] = dp[1][i][j] = INF;
    }
  }
  cout << rec(0, 0, n-1) << endl;

}

void solve(){
  int t = 1;
  // scanf("%d", &t);
  for (int i = 0; i < t; i++){
    exec();
  }
}

int main(){
  solve();
  return 0;
}
