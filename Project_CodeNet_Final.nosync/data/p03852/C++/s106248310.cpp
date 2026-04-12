#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>
#include <limits>
using namespace std;
typedef long long ll;

float inf = std::numeric_limits<float>::infinity();

/* 二次元配列の宣言
  vector<vector<int>> tb;
  tb.resize(H);
  for (size_t i = 0; i < H; i++) {
    tb[i].resize(W);
  }
*/
/*
  A.resize(N);
  for (int i = 0; i < N; i++) {scanf("%d",&A[i]);}
*/

int main(void) {
  char c;
  array<char,5> boin={'a','e','i','o','u'};
  cin >> c;

  for (size_t i = 0; i < 5; i++) {
    if (boin[i]==c){
      cout << "vowel" << '\n';
      exit(0);
    }
  }
  cout << "consonant" << '\n';
}
