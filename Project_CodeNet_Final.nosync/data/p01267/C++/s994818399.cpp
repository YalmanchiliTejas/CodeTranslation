// AOJ 2149
#include<iostream>
#include<vector>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

int solve(int n, int a, int b, int c, int x, vector<int> y) {
  int current = 0, rand = x;
  for (int i = 0; i <= 10000; i++) {
    if (x == y[current]) {
      current++;
    }
    if (current == n) {
      return i;
    }
    x = (a * x + b) % c;
  }
  return -1;
}

int main() {
  int N,A,B,C,X;
  while (cin >> N >> A >> B >> C >> X and N) {
    vector<int> Y(N);
    REP(i, N) {
      cin >> Y[i];
    }

    cout << solve(N,A,B,C,X,Y) << endl;
  }
}