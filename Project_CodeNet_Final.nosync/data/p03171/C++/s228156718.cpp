#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// a[i]-a[j-1]が残った時にそれ以降のX-Yをdp[i][j]とする
// dp[i][j]が決まると、dp[i+1][j]かdp[i][j-1]のどちらかに遷移する
// どちらに遷移するかというと、太郎君の手番の場合は、X-Yを最大値にする方
// 次郎君の手番の場合はX-Yを最小値にする方へと遷移する
// 長さlenは1からNまでスタート地点はj=0からN-lenまでで計算
// どっちの手番かというと、数列にj-iこ残っている状態のとき、つまりN-j+iことった時に
// N-j+iが偶数なら太郎君の手番、N-j+iが奇数なら次郎君の手番

ll N, K;
vector<ll> ai;
vector<vector<ll>> dp;

int main() {
  cin >> N;
  ai = vector<ll>(N+10,0);
  for (ll i=0;i<N;i++) cin >> ai.at(i);

  dp = vector<vector<ll>>(N+10,vector<ll>(N+10,0));

  for (ll len=1;len<=N;len++){
    for (ll i=0;i<N+1-len;i++){
      ll j = i + len;
      if ((N-len)%2 == 0){
        dp.at(i).at(j) = max(dp.at(i+1).at(j)+ ai.at(i), dp.at(i).at(j-1)+ai.at(j-1)); 
      } else {
        dp.at(i).at(j) = min(dp.at(i+1).at(j)- ai.at(i), dp.at(i).at(j-1)-ai.at(j-1));
      }
    }
  }

  cout << dp.at(0).at(N) << endl;
}