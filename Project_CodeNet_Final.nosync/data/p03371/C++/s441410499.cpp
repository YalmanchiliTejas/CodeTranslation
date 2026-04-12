#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

long long A, B, C, X, Y;

int main() {
  cin >> A >> B >> C >> X >> Y;

  long long p = min(A+B,C*2);
  long long q = min(C*2, A);
  long long r = min(C*2, B);

  long long cost = 0;

  if(X >= Y) {
    cost = p * Y + q * (X - Y);
  } else {
    cost += p * X;
    cost += r * (Y - X);
  }

  cout << cost << endl;

  return 0;
}