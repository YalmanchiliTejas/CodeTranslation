#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> H;

int main() {
  cin >> N;
  H.resize(N);
  for (int i = 0; i < N; i++) cin >> H[i];


  int cnt = 1;
  int max = H[0];
  for (int i = 1; i < N; i++) {
    if (max <= H[i]) cnt++, max = H[i];
  }
  cout << cnt << endl;
  return 0;
}