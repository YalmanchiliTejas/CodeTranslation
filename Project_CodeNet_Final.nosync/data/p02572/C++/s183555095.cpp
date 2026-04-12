#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define ll long long
static const ll MAX = 10000;
static const ll INFTY = 1e12;
static const ll MOD = 1e9+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using P = pair<ll, ll>;
// 入力
// 入力
ll h, w;
ll startX, startY, endX, endY;
vector<vector<char>> s;
vector<vector<ll>> cnts; // 魔法使った回数


int main() {

  ll N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  REP(i, N){
    cin >> A[i];
    sum += A[i];
    sum %= MOD;
  }
  ll ans = 0;
  REP(i, N-1){
    sum -= A[i];
    if (sum < 0) sum += MOD;
    ll tmp = (sum * A[i]) % MOD;
    ans += tmp;
    ans %= MOD;
    // cout << ans << endl;
  }
  cout << ans << endl;

   
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/