#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i, n) for (int i = 0; i < ((int)(n)); i++) // 0-indexed昇順

int main()
{
  int X,Y,Z;
  cin >> X >> Y >>Z;
  X -= Z;
  cout << X / (Y +Z) << endl;
}