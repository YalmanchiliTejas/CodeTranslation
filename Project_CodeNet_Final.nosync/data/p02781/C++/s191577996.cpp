#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <numeric>
#include <iomanip>
#include <deque>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

#define rep(i, x) for (int i = 0; i < (int)(x); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define F first
#define S second
#define pb push_back
#define pf push_front

using ll = long long;
using namespace std;
namespace mp = boost::multiprecision;
using cpp_int = mp::cpp_int;
ll M = 1000000007;
typedef pair<int, int> P;

typedef pair<ll, int> pli;

int dp[105][4][2];


void solve()
{
    
  string s;
  cin >> s;
  int n = s.size();
  int K;
  cin >> K;
  dp[0][0][0] = 1;
  //dp[i][j][k]
  /*
  i桁目まで決めて
  j個の非0を使い，
  k: 1:ここまででn以下であることが確定 
     0:そこまではnと一致

  */
  rep(i,n)rep(j,4)rep(k,2) {
    int nd = s[i]-'0'; //sの数字
    rep(d,10) {
      int ni = i+1, nj = j, nk = k;//次への遷移？
      if (d != 0) nj++;//非0ならばjが増える
      if (nj > K) continue; //Kより大きいとアウトだろ
      if (k == 0) {//以下が未確定なら
        if (d > nd) continue; //大きいとダメだろ
        if (d < nd) nk = 1;//小さいなら確定
        //同じならそのまま
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][K][0] + dp[n][K][1];
  cout << ans << endl;


}
int main()
{
    solve();
}