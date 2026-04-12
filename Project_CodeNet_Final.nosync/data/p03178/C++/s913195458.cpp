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
// const ll INF = LLONG_MAX;
const int MOD = ((int)1e9 + 7);
// const ld EPS = (1e-10);
#define PI acosl(-1)
#define MAX_N (100000 + 2)

string k;
int d;
// dp[大きい方からn桁まで][どの数字を使ってもいいか][mod D]
ll dp[MAX_N][2][102];

ll rec(int digit, int can_use_any_number, int remain){
  if (digit == -1){
    if (can_use_any_number){
      return 0;
    }
    else{
      return remain == 0 ? 1 : 0;
    }
  }
  if (dp[digit][can_use_any_number][remain] != -1){
    return dp[digit][can_use_any_number][remain];
  }

  ll result = 0;
  int number = k[digit] - '0';
  if (can_use_any_number){
    for (int i = 0; i <= 9; i++){
    // printf("1: 10 * %d + %d - %d mod %d = %d\n", d, remain, i, d, (10 * d + remain - i) % d);
      result += rec(digit - 1, 1, (10 * d + remain - i) % d);
      result %= MOD;
    }

    for (int i = 0; i <= number - 1; i++){
    // printf("2: 10 * %d + %d - %d mod %d = %d\n", d, remain, i, d, (10 * d + remain - i) % d);
      result += rec(digit - 1, 0, (10 * d + remain - i) % d);
      result %= MOD;
    }
  }
  else{
    result += rec(digit - 1, 0, (10 * d + remain - number) % d);
    result %= MOD;
  }
  // printf("dp[%d][%d][%d] = %lld\n", digit, can_use_any_number, remain, result);
  dp[digit][can_use_any_number][remain] = result;

  return result;
}

void exec(){
  cin >> k >> d;

  for (int i = 0; i < MAX_N; i++){
    for (int j = 0; j < 2; j++){
      for (int k = 0; k < 102; k++){
        dp[i][j][k] = -1;
      }
    }
  }

  ll result = rec(k.length()-1, 1, 0) + rec(k.length()-1, 0, 0);
  result %= MOD;
  result = (result + MOD - 1) % MOD;

  cout << result << endl;

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
