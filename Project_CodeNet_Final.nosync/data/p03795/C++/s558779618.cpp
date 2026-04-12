#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int N;
  cin >> N;
  int x = N * 800;
  int y = N / 15 * 200;
  cout << x - y << endl;
}