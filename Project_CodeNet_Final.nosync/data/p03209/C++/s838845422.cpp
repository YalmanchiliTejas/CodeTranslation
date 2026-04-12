#include <bits/stdc++.h>
using namespace std;

#define int long long

int Len[55]; // Len[level]: levelバーガー全体の長さ
int Pat[55]; // Pat[level]: levelバーガーのパティ数

// levelとlayerを投げると、パティ数が返ってくる関数
int rec(int level, int layer) {
  // レベル0は例外
  if (level == 0) {
    return 1;
  }

  if (layer == 1) { // 範囲1
    return 0;
  } else if (layer <= Len[level-1] + 1) { // 範囲2
    return rec(level-1, layer-1);
  } else if (layer <= Len[level-1] + 2) { // 範囲3
    return Pat[level-1] + 1;
  } else if (layer <= 2 * Len[level-1] + 2) { // 範囲4
    return Pat[level-1] + 1 + rec(level-1, layer - Len[level-1] - 2);
  } else { // 範囲5
    return 2 * Pat[level-1] + 1;
  }
}

signed main() {
  // 入力
  int N, X;
  cin >> N >> X;

  // バーガーの長さとパティの数を前計算
  Len[0] = Pat[0] = 1;
  for (int i = 1; i <= N; i++) {
    Len[i] = Len[i-1] * 2 + 3; // レベルi-1バーガー２つ + バン２つ + パティ１つ
    Pat[i] = Pat[i-1] * 2 + 1; // レベルi-1バーガー２つ + パティ１つ
  }

  // 出力
  cout << rec(N, X) << endl;

   return 0;
}
