#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int sum = 0;
  //必要な個数が多いほうをAにしちゃう
  if(X < Y) {
    swap(A, B);
    swap(X, Y);
  }
  int d = X - Y;
  if(A + B < C * 2) {
    sum += Y * (A + B);
  } else {
    sum += Y * C * 2;
  }
  if(A < C * 2) {
    sum += d * A;
  } else {
    sum += d * C * 2;
  }
  cout << sum << endl;
  return 0;
}