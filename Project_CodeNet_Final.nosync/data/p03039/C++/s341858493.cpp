#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>

typedef long long ll;
const ll INF = (ll)1e18 + 1;
const ll MOD = 1e9 + 7;

template<typename H> void print(H head) { std::cout << head << std::endl; }

// nCa を求める
ll mod_combination(ll n, ll a, ll sum)
{
  const ll MAX_LOG_V = 30;

  ll ans = sum;
  for (ll i = n; i >= n - a + 1; i--) {
    ans = (ans * i) % MOD;
  }

  for (ll i = 1; i <= a; i++) {

    std::vector<ll> vd(MAX_LOG_V, i);
    for (ll k = 0; k+1 < MAX_LOG_V; k++) {
      vd[k+1] = (vd[k] * vd[k]) % MOD;
    }

    // Aで割りたい時は, A の M-2 乗で掛ければ良い
    ll calc = 1LL;
    for (ll k = MAX_LOG_V - 1; k >= 0; k--) {
      if ((MOD-2) >> k & 1) {
	calc = (calc * vd[k]) % MOD;
      }
    }
    ans = (ans * calc) % MOD;
  }

  return ans;
}

int main()
{
  ll N, M, K;
  std::cin >> N >> M >> K;

  // 2個の距離を求めて, それぞれの組み合わせを掛ける場合,
  // ......
  // ...B..
  // ......
  // .A..C.
  //
  // のような K=3のケースで A, B の距離を求めると, B, C の距離が混ざってくるような勘違いをしたが,
  // 上図のように A, B を固定して距離を求めた場合の C の配置の通り数を掛け算し,
  // A, B の組合わせを列挙しては C の配置のパターンで掛けたものを足していくと,
  //
  // ......
  // ...A..
  // ......
  // .C..B.
  //
  // A, B を 上図のような配置にした場合の, C の配置の通り数の掛け算も, もれなく足されるので,
  // (A, B の全て配置の組み合わせでの距離の総和) ✕ Combination(N*M-2, K-2) になる
  //
  // 高さN = 4, 幅 M = 6 のgridで, A, B の高さ方向の距離を求める場合, 距離 d=2 の場合を考えると
  //
  // ★ ケース 1
  // ......
  // ...#..  A で M 通り取れる
  // ......
  // .#....  B で M 通り取れる
  //
  // ★ ケース 2
  // ...#..  A で M 通り取れる
  // ......
  // .#....  B で M 通り取れる
  // ......
  //
  // というように, 高さ 4 - 2 で 2通り取れる (N-d)
  // M * M * (N-d) の　Σ を取れば良い.
  ll distance_sum = 0LL;
  for (ll d = 1; d < N; d++) {
    distance_sum = (distance_sum + d * M * M * (N-d)) % MOD;
  }

  // 同様に 横方向も 距離を求める
  for (ll d = 1; d < M; d++) {
    distance_sum = (distance_sum + d * N * N * (M-d)) % MOD;
  }

  // distance_sum * mod_combination(N*M-2, K-2) だと溢れたため,
  // combination 処理で, distance_sum に少しずつ掛け算していくことにした
  distance_sum = mod_combination(N*M-2, K-2, distance_sum);
  print(distance_sum);

  return 0;
}
