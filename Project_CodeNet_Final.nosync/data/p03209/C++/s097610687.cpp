#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int64 latte[51], malta[51];

int N;
int64 X;

int64 rec(int N) {
  if(X <= 0) {
    return 0;
  }

  if(N == -1) {
    return 0;
  }
  if(X >= latte[N]) {
    X -= latte[N];
    return malta[N];
  } else {
    int64 ret = 0;
    X--;
    ret += rec(N - 1);
    if(X > 0) {
      ret++;
      X--;
    }
    ret += rec(N - 1);
    X--;
    return ret;
  }
}

int main() {
  cin >> N >> X;
  latte[0] = 1;
  malta[0] = 1;
  for(int i = 1; i < 51; i++) {
    latte[i] = latte[i - 1] * 2 + 3;
    malta[i] = malta[i - 1] * 2 + 1;
  }
  cout << rec(N) << endl;
}